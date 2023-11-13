#ifndef CONTROL_FLAGS_H
#define CONTROL_FLAGS_H

#define T ControlFlag_t
struct T
{
  char *name;
  void *currentValue;
  void *defaultValue;
  void (*print)(void *);
  struct T *prev;
};

// all flags
extern int Control_assert;
extern int Control_debugLevel;
extern int Control_nogc;
extern int Control_tracedAll;
extern char *Control_tracedFuncs[];
extern int Control_tracedLast;



void printAllFlags ();

#undef T

#endif

