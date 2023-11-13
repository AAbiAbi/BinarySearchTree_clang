#ifndef BST_H
#define BST_H

#include "lib/poly.h"

#define T Bst_t
typedef struct _T *T;

// typedef struct bst_t *T;

#define Key_t poly
#define Value_t poly

typedef struct _node {
    Key_t key;
    Value_t value;
    struct _node* left;
    struct _node* right;
} *node;

typedef struct _T {
    node root;
    tyCompares compares;
} *T;
// New interface function
T Bst_new(tyCompares compares);
//T Bst_new2(Key_t key, Value_t value, T left, T right);

T Bst_insert2 (T t, node ele);
//define of compares exists in poly2.h
//As we all know, bst needs a rule of comparsion. While type poly does not have a natural compartor. That why we need to manually add a compartor to poly2
Value_t Bst_lookup2 (T t, Key_t key);
// Recall that "inOrder" will visit the tree nodes in increasing order
void Bst_inOrder (T t, tyVisit visitKey, tyVisit visitValue);
// void Bst_inOrder (T t, tyVisit visitKey, tyVisit visitValue);




#endif
