#ifndef STRING_H
#define STRING_H

#define T String_t

typedef char *T;

T String_new (char *);
T String_concat (char *s, ...);
T String_fromArray (int size, char *array[], char *sep);
T Int_toString (int i);
T Double_toString (double f);
// Function declaration for String_fromArray
char *String_fromArray(int size, char *array[], char *sep);

#undef T

#endif
