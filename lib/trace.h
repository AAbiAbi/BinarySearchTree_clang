#ifndef TRACE_H
#define TRACE_H

#include <time.h>
#include "control.h"

void Trace_indent ();
void Trace_unindent ();
void Trace_spaces ();
int Trace_lookup (char *);

#ifdef DEBUG

#define Trace_TRACE(s, f, x, toStringx, r, toStringr)   \
  do {                                                  \
    clock_t start, finish;                              \
    if (Trace_lookup(s)) {                              \
      if (Control_debugLevel>=1) {                      \
        Trace_spaces ();                                \
        printf ("%s starting\n", s);                    \
        Trace_indent ();                                \
        if (Control_debugLevel >= 2) {                  \
          Trace_spaces ();                              \
          printf ("%s arg is:\n", s);                   \
          Trace_spaces ();                              \
          printf("%s\n", toStringx x);                  \
          if (Control_debugLevel>=3) {                  \
            start = clock ();                           \
          }                                             \
        }                                               \
      }                                                 \
    }                                                   \
    r = f x;                                            \
    if (Trace_lookup(s)) {                              \
      if (Control_debugLevel >=1) {                     \
        if (Control_debugLevel >= 2) {                  \
          Trace_spaces ();                              \
          printf ("%s result is:\n", s);                \
          Trace_spaces ();                              \
          printf("%s\n", toStringr (r));                \
        }                                               \
        Trace_unindent ();                              \
        Trace_spaces ();                                        \
        if (Control_debugLevel >= 3) {                          \
          finish = clock ();                                    \
          printf ("%s finished in @time used: %lf\n", s,        \
                  ((double)(finish-start))/CLOCKS_PER_SEC);     \
        }                                                       \
        else                                                    \
          printf ("%s finished\n", s);                          \
      }                                                         \
    }                                                           \
  } while (0)

#else

#define Trace_TRACE(s, f, x, toStringx, r, toStringr) \
  do {                                                \
    r = (f x);                                        \
  } while (0)                                         

#endif

#endif
