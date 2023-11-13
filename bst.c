#include <stdio.h>
#include <stdlib.h>
#include "lib/poly.h"
#include "lib/trace.h"
#include "lib/assert.h"

// Define your own memory management functions
#define Mem_NEW(p) ((p) = malloc(sizeof(*(p))))
#define Mem_NEW_SIZE(p, size) ((p) = malloc((size) * sizeof(*(p))))
#define Mem_FREE(p) free(p)

// Define your own error handling function
#define Error_error(msg) fprintf(stderr, "Error: %s\n", msg)

// Define your own debugging functions (you can replace with your own implementation)

#include "bst.h"




// struct _node {
//   Key_t key;
//   Value_t value;
//   node left;
//   node right;
// };

// struct _T
// {
//   Key_t key;
//   Key_t value;
//   T left;
//   T right;
// };

// This is a private function used to create a new BST node with the given key, value, and left and right children.
// It allocates memory for the new node and returns a pointer to it.


// Function to create a new BST
T Bst_new(tyCompares compares) {
    T bst;
    Mem_NEW(bst);
    if (!bst) {
        Error_error("Memory allocation failed for BST");
        return NULL;
    }
    bst->root = NULL;
    bst->compares = compares;
    printf("success build tree %s\n",bst->root);
    return bst;
}

/*
This function is used to insert a new key-value pair into the BST t.
If the BST is empty (i.e., t is 0), a new node is created with the given key and value, and it becomes the root of the tree.
Otherwise, the compares function is used to compare the new key with the keys in the existing nodes to determine the insertion point.
The function recursively inserts the new key-value pair into the appropriate subtree (left or right) based on the comparison result.
*/

static node Bst_insertRecursive(node current, node ele, tyCompares compares) {
    if (current == NULL) {
        return ele; // Found the correct position for the new node
    }

    int compareResult = compares(ele->key, current->key);
    if (compareResult < 0) {
        current->left = Bst_insertRecursive(current->left, ele, compares); // Insert in the left subtree
    } else if (compareResult > 0) {
        current->right = Bst_insertRecursive(current->right, ele, compares); // Insert in the right subtree
    } else {
        Error_error("Attempted to insert a duplicated key!"); // Duplicated key found
    }

    return current; // Return the unchanged node pointer
}



T Bst_insert2 (T t, node ele)
{
    if (t == NULL || t->root == NULL) {
        printf("before insert null");
        printf("%s\n",ele->left);

        t->root = ele; 
        printf("%s\n",t->root->key);
        // If the tree is empty, insert the node at the root
        printf("after insert null");
        return t;
    }
    printf("before insert");
    t->root = Bst_insertRecursive(t->root, ele, t->compares);
    printf("\n%s\n",t->root->key);
    printf("success insert");
    return t;
}



#define INDENT 4

static void printSpace (int n)
{
  Assert_assert (n>=0);
  while (n--)
    printf (" ");
}

static int Bst_inOrder_traced (T t, tyVisit visitKey, tyVisit visitValue, int i)
{
  if (0==t)
    return 0;
  Bst_inOrder_traced(t->root->left, visitKey, visitValue, i + INDENT);
  printSpace (i);
  printf ("(");
  visitKey (t->root->key);
  printf (", ");
  visitValue (t->root->value);
  printf (")\n");


  Bst_inOrder_traced(t->root->right, visitKey, visitValue, i + INDENT);
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


void Bst_inOrder (T t, tyVisit visitKey, tyVisit visitValue){
    printf("before traverse");
    visitKey(t->root->key);
    Bst_inOrder2 (t, visitKey, visitValue, 0);
     printf("after traverse");
}

// Helper function for Bst_lookup
static Value_t Bst_lookup_recursive(T t, Key_t key, tyCompares compares) {
    if (t == NULL) {
        // The key was not found in the tree
        return NULL;
    }

    int comparison = compares(key, t->root->key);

    if (comparison == 0) {
        // Found the key, return the associated value
        return t->root->value;
    } else if (comparison < 0) {
        // Key may be in the left subtree
        return Bst_lookup_recursive(t->root->left->key, key, compares);
    } else {
        // Key may be in the right subtree
        return Bst_lookup_recursive(t->root->right->key, key, compares);
    }
}



Value_t Bst_lookup2(T t, Key_t key) {
    if (t == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    }
    return Bst_lookup_recursive(t, key, t->compares);
}
