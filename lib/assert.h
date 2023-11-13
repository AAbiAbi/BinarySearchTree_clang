#ifndef ASSERT_H
#define ASSERT_H

#include <assert.h>
#include "control.h"

#ifdef DEBUG
#define Assert_assert(e)                        \
  do {                                          \
    if (Control_assert)                         \
      assert (e);                               \
    else;                                       \
  }while (0)
#else

#define Assert_assert(e)

#endif

#endif
