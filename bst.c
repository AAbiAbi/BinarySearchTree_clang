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
    printf("success build tree\n");
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
        // printf("before insert null");
        //printf("%s\n",ele->left);

        t->root = ele; 
        // printf("%s\n",t->root->key);
        // // If the tree is empty, insert the node at the root
        // printf("after insert null");
        return t;
    }
    // printf("before insert");
    t->root = Bst_insertRecursive(t->root, ele, t->compares);
    // printf("\n%s\n",t->root->key);
    
    return t;
}



#define INDENT 4

// Forward declaration for the recursive in-order function
static void Bst_inOrder_recursive(node current);


static void printSpace (int n)
{
  Assert_assert (n>=0);
  while (n--)
    printf (" ");
}

// static int Bst_inOrder_traced (T t, tyVisit visitKey, tyVisit visitValue, int i)
// {
//   if (0==t)
//     return 0;
//   Bst_inOrder_traced(t->root->left, visitKey, visitValue, i + INDENT);
//   printSpace (i);
//   printf ("(");
//   visitKey (t->root->key);
//   printf (", ");
//   visitValue (t->root->value);
//   printf (")\n");


//   Bst_inOrder_traced(t->root->right, visitKey, visitValue, i + INDENT);
// }

// static char *junk1 (T t, ...)
// {
//   return "";
// }

// static char *junk2(int i)
// {
//   return "";
// }


// static void Bst_inOrder2 (T t, tyVisit visitKey, tyVisit visitValue, int i)
// {
//   int r;
//   Trace_TRACE("Bst_inOrder", Bst_inOrder_traced, 
//               (t, visitKey, visitValue, i), junk1, r, junk2);
//   return;
// }


void Bst_inOrder (T t){

    if (t == NULL || t->root == NULL) {
        // Tree is empty or uninitialized
        return;
    }

   // printf("before traverse");
    // Start the recursive in-order traversal from the root
    Bst_inOrder_recursive(t->root);
    // printf("before traverse");
    // visitKey(t->root->key);
    // Bst_inOrder2 (t, visitKey, visitValue, 0);
    // printf("after traverse");
}

// The recursive in-order traversal function
static void Bst_inOrder_recursive(node current) {
    if (current == NULL) {
        // Base case: reached a leaf node's child
        return;
    }
    //printf("before traverse");
    // Traverse the left subtree
    Bst_inOrder_recursive(current->left);

    // Visit the current node
    // visitKey(current->key);   // Process the key
    printf("(%s,%s)\n",(char *)current->key,(char *)current->value);
    // visitValue(current->value); // Process the value

    // printf("%s\n",(char *)current->value);

    // Traverse the right subtree
    Bst_inOrder_recursive(current->right);
}

// Helper function for Bst_lookup
static Value_t Bst_lookup_recursive(node current, Key_t key, tyCompares compares) {

    
    if (current == NULL) {
        // The key was not found in the tree
        return NULL;
    }

    int comparison = compares(key, current->key);
    // printf("%d/n",comparison);

    if (comparison == 0) {
        // Found the key, return the associated value
        return current->value;
    } else if (comparison < 0) {
        // Key may be in the left subtree
        return Bst_lookup_recursive(current->left, key, compares);
    } else {
        // Key may be in the right subtree
        return Bst_lookup_recursive(current->right, key, compares);
    }
}



Value_t Bst_lookup2(T t, Key_t key) {
    if (t == NULL) {
        // If the tree is empty, return NULL
        return NULL;
    }

    // printf ("sss\n");
    return Bst_lookup_recursive(t->root, key, t->compares);
}
