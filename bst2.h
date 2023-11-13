#ifndef BST_H
#define BST_H

#include "lib/poly.h"

#define T Bst_t
typedef struct _T *T;

#define Key_t poly
#define Value_t poly

T Bst_insert (T t, Key_t key, Value_t value, tyCompares compares);
//define of compares exists in poly2.h
//As we all know, bst needs a rule of comparsion. While type poly does not have a natural compartor. That why we need to manually add a compartor to poly2
Value_t Bst_lookup (T t, Key_t key, tyCompares compares);
// Recall that "inOrder" will visit the tree nodes in increasing order
void Bst_inOrder (T t, tyVisit visitKey, tyVisit visitValue);


#undef T
#undef Key_t
#undef Value_t

#endif
