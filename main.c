#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/assert.h"
#include "lib/string.h"
#include "lib/trace.h"
#include "bst2.h"
#include "bst2.c"
#include "lib/string.c"



void handleArgs(int argc, char *argv[]) {
    // Check if there is at least one argument (program name counts as an argument)
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1); // Exit the program with an error code
    }

    // Access the first argument (index 1) as it contains the filename
    char *filename = argv[1];
    printf("The provided filename is: %s\n", filename);
}


void pr (poly s)
{
  printf ("%s", (char *)s);
}

int main0 (int argc, char *argv[])
{ 
  /* we cook a binary search tree "t", which maps
   * string to integer.
   */
  Bst_t t = 0;
  t = Bst_insert (t, "a", "hello", strcmp);
  t = Bst_insert (t, "b", "world", strcmp);
  t = Bst_insert (t, "c", "binary", strcmp);
  t = Bst_insert (t, "d", "search", strcmp);
  t = Bst_insert (t, "e", "tree", strcmp);

  /*

  The strcmp function is a standard C library function defined in the <string.h> header file. 
  It is commonly used to compare two C-style strings (null-terminated character arrays) and determine their lexicographical order.
  */
  
  /* Question: what will the tree "t" look like here?
   */

   /*
        a
         \
          b
           \
            c
             \
              d
               \
                e

   */
  /* Try to justify your answer by printing "t" out in in-order:
   */
  printf ("inOrder visit:\n");
  Bst_inOrder (t, pr, pr);

  // try to perform a lookup:
  char *s = Bst_lookup (t, "a", strcmp);
  if (s)
    printf ("found: %s\n", s);
  else
    printf ("not found\n");  
  
  return 0;
}

char *main_toString (int i, char *argv[])
{
  return String_fromArray(i, argv, " ");
}

int main (int argc, char *argv[])
{
  int r;

  handleArgs (argc, argv);

  Trace_TRACE("main", main0,
        (argc, argv), main_toString, r, Int_toString);
  return 0;
}

