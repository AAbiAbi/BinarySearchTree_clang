#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "string.h"

#define T String_t

#define Mem_NEW_SIZE(ptr, size) (ptr = malloc(size))


T String_new (char *s)
{
  char *temp;
  int size = strlen(s) +1;
  Mem_NEW_SIZE(temp, size);
  return strcpy(temp, s);
}

// char *String_fromArray(int size, char *array[], char *sep) {
//     // Your implementation here
//     // ...
// }

T String_concat (char *s, ...)
{
  int totalSize = 0;
  char *current = s;
  va_list ap;
  va_start(ap, s);
  while(current) {
    totalSize += strlen (current);
    current = va_arg (ap, char *);
  }
  va_end(ap);

  char *temp, *head;
  Mem_NEW_SIZE(temp, (totalSize+1));
  head = temp;
  current = s;
  va_start(ap, s);
  while(current) {
    strcpy (temp, current);
    temp += strlen(current);
    current = va_arg (ap, char *);
  }
  return head;
}

T String_fromArray (int size, char *array[], char *sep)
{
  int i = 0;
  int totalSize = 0;
  while (i<size) {
    totalSize += strlen (array[i]);
    i++;
  }
  char *temp, *head;
  Mem_NEW_SIZE (temp, (totalSize + 1 + size * strlen(sep)));
  head = temp;
  i = 0;
  while (i<size) {
    strcpy (temp, array[i]);
    temp += strlen(array[i]);
    strcpy (temp, sep);
    temp += strlen (sep);
    i++;
  }
  return head;
}

#define BUF_SIZE 1024

T Int_toString (int i)
{
  char *temp;
  Mem_NEW_SIZE(temp, BUF_SIZE);
  // Note that I initially want to write
  //   snprintf (temp, BUF_SIZE, "%d", i);
  // but it seems that this version of GCC has a bug on
  // the function "snprintf".
  sprintf (temp, "%d", i);
  return temp;
}

T Double_toString (double f)
{
  char *temp;
  Mem_NEW_SIZE(temp, BUF_SIZE);
  // Note that I initially want to write
  //   snprintf (temp, BUF_SIZE, "%d", i);
  // but it seems that this version of GCC has a bug on
  // the function "snprintf".
  sprintf (temp, "%lf", f);
  return temp;
}

#undef BUF_SIZE

