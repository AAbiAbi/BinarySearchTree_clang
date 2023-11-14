# BinarySearchTree_clang
Implement the binary search tree "Bst_t" ADT. 


## Question
- Read line 12 of file bst.h. Note that functions Bst_insert, Bst_lookup have taken an extra function pointer compares as an extra arguments. Where is the definition of compares? And explain why would we need this function pointer?
- Read line 20-24 of file main.c. Notice that it's cumbersome to always pass the argument strcmp (where does strcmp come from?). But notice an important fact: for any given BST, this argument is fixed. So a good idea is to pass this argument at BST creation time. The data structure may be revised as:
- typedef struct node *node;
```c
struct Bst_t

{

  node *node;

  tyCompares compares;

};

 

struct node

{

  Key_t key;

  Key_t value;

  node left;

  node right;

};
```
And add a new interface function:
```c

T Bst_new (tyCompares compares);
```

Explain how this strategy works. And then implement it.

## Result

Result can be found at res directory.

![Binary Search Tree Diagram](https://github.com/AAbiAbi/BinarySearchTree_clang/blob/main/res/bst1res.png "Binary Search Tree")

![Binary Search Tree Diagram](https://github.com/AAbiAbi/BinarySearchTree_clang/blob/main/res/bst2res.png "Binary Search Tree")

![Binary Search Tree Diagram](https://github.com/AAbiAbi/BinarySearchTree_clang/blob/main/res/bst2res2.png "Binary Search Tree")

