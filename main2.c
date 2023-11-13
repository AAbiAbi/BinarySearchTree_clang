#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/assert.h"
#include "lib/string.h"
#include "lib/trace.h"
#include "bst.h"
#include "bst.c"
#include "lib/string.c"
#include "lib/poly.h"
#define DEBUG
#ifdef DEBUG

node create_node(poly key, poly value) {
    node new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_node->key = key;   // Duplicate the key string
    new_node->value = value; // Duplicate the value string
    new_node->left = NULL;
    new_node->right = NULL;
    printf("Found: %s\n", (char *)new_node->key);
    return new_node;
    // Rest of the implementation
}

void handleArgs(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    printf("The provided filename is: %s\n", filename);
}

void pr (poly s) {
    printf ("%s", (char *)s);
}

int strcmp_wrapper(void *a, void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main(int argc, char *argv[]) {
    handleArgs(argc, argv);

    // Create a new binary search tree "t" with strcmp as the comparison function
    
    Bst_t t = Bst_new(strcmp_wrapper);

    if (!t) {
        fprintf(stderr, "Failed to create binary search tree.\n");
        return 1;
    }
    node a_ele = create_node("a", "hello"); 
    if (!a_ele) {
    fprintf(stderr, "Failed to create node a_ele.\n");
    // Handle error, such as by exiting or cleaning up
    }

    node b_ele = create_node("b", "world"); 
    if (b_ele) {
        printf("fff");
    // Handle error, such as by exiting or cleaning up
    }

    node c_ele = create_node("c", "binary"); 
    node d_ele = create_node("d", "search"); 
    node e_ele = create_node("e", "tree"); 

    //int comparison = strcmp_wrapper(a_ele, b_ele);
    //printf("%d",comparison);

    // Insert elements into the tree
 
    //printf("Founda: %s\n", pr,pr);
    Bst_insert2(t, b_ele);
    Bst_insert2(t, a_ele);
//    // printf("Foundb: %s\n", pr,pr);
//     Bst_insert2(t, c_ele);
//     Bst_insert2(t, d_ele);
//     Bst_insert2(t, e_ele);
    poly ddd1 = t->root->key;

    // Perform in-order traversal
    printf("InOrder visit:\n");

    poly ddd = t->root->value;
    printf ("%s\n", (char *)ddd);

    pr(ddd);//should be b

    printf ("sss\n");
    Bst_inOrder(t, pr, pr);

    // Perform a lookup
    char *s = Bst_lookup2(t, "a");
    if (s) {
        printf("Found: %s\n", s);
    } else {
        printf("Not found\n");
    }
    

    // Additional code for cleanup, if necessary

    printf("Debugging message: %s\n", "ddd");

    return 0;
}




#endif
