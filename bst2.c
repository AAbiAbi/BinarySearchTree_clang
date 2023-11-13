#include <stdio.h>
#include <stdlib.h>
#include "lib/trace.h"


// Define your own memory management functions
#define Mem_NEW(p) ((p) = malloc(sizeof(*(p))))
#define Mem_NEW_SIZE(p, size) ((p) = malloc((size) * sizeof(*(p))))
#define Mem_FREE(p) free(p)

// Define your own error handling function
#define Error_error(msg) fprintf(stderr, "Error: %s\n", msg)

// Define your own debugging functions (you can replace with your own implementation)
#define Assert_assert(cond) do { if (!(cond)) { Error_error("Assertion failed: " #cond); exit(1); } } while (0)


#include "bst2.h"

#define T Bst_t
#define Key_t poly
#define Value_t poly

struct _T
{
  Key_t key;
  Key_t value;
  T left;
  T right;
};
// This is a private function used to create a new BST node with the given key, value, and left and right children.
// It allocates memory for the new node and returns a pointer to it.
static T Bst_new2 (Key_t key, Value_t value, T left, T right)
{
  T t;
  Mem_NEW (t);
  t->key = key;
  t->value = value;
  t->left = left;
  t->right = right;
  return t;
}

/*
This function is used to insert a new key-value pair into the BST t.
If the BST is empty (i.e., t is 0), a new node is created with the given key and value, and it becomes the root of the tree.
Otherwise, the compares function is used to compare the new key with the keys in the existing nodes to determine the insertion point.
The function recursively inserts the new key-value pair into the appropriate subtree (left or right) based on the comparison result.
*/


T Bst_insert (T t, Key_t key, Value_t value, tyCompares compares)
{
  if (0==t)
    return Bst_new2 (key, value, 0, 0);
  int direction = compares (key, t->key);
  if (direction<0) 
    return Bst_new2 (t->key, t->value, 
                     Bst_insert(t->left, key, value, compares), t->right);
  if (0==direction)
    Error_error ("try to insert a duplicated key!");

  return Bst_new2 (t->key, t->value, t->left, 
                   Bst_insert(t->right, key, value, compares));
}




#define INDENT 4

static void printSpace (int n)
{
  Assert_assert (n>=0);
  while (n--)
    printf (" ");
}

static void Bst_inOrder2 (T, tyVisit, tyVisit, int);

static int Bst_inOrder_traced (T t, tyVisit visitKey, tyVisit visitValue, int i)
{
  if (0==t)
    return 0;
  Bst_inOrder2 (t->left, visitKey, visitValue, i+INDENT);
  printSpace (i);
  printf ("(");
  visitKey (t->key);
  printf (", ");
  visitValue (t->value);
  printf (")\n");
  Bst_inOrder2 (t->right, visitKey, visitValue, i+INDENT);
}

static char *junk1 (T t, ...)
{
  return "";
}

static char *junk2(int i)
{
  return "";
}

static void Bst_inOrder2 (T t, tyVisit visitKey, tyVisit visitValue, int i)
{
  int r;
  Trace_TRACE("Bst_inOrder", Bst_inOrder_traced, 
              (t, visitKey, visitValue, i), junk1, r, junk2);
  return;
}

void Bst_inOrder (T t, tyVisit visitKey, tyVisit visitValue)
{
  Bst_inOrder2 (t, visitKey, visitValue, 0);
}

// Helper function for Bst_lookup
static Value_t Bst_lookup_recursive(T t, Key_t key, tyCompares compares) {
    if (t == NULL) {
        // The key was not found in the tree
        return NULL;
    }

    int comparison = compares(key, t->key);

    if (comparison == 0) {
        // Found the key, return the associated value
        return t->value;
    } else if (comparison < 0) {
        // Key may be in the left subtree
        return Bst_lookup_recursive(t->left, key, compares);
    } else {
        // Key may be in the right subtree
        return Bst_lookup_recursive(t->right, key, compares);
    }
}

Value_t Bst_lookup (T t, Key_t key, tyCompares compares) {
    // Call the recursive lookup function starting from the root
    return Bst_lookup_recursive(t, key, compares);
}
