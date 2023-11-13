#ifndef POLY2_H
#define POLY2_H

typedef void *poly;
typedef int (*tyEquals)(poly, poly);
typedef char *(*tyToString) (poly);
typedef void (*tyVisit)(poly);
typedef int (*tyCompares)(poly, poly);

#endif
