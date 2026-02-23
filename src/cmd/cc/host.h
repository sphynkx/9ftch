#pragma once

#include "lib9.h"
#include "bio.h"

#ifndef TRune
typedef Rune TRune;
#endif

#ifndef USED
#define USED(...) (void)0
#endif

#ifndef SET
#define SET(x) ((x) = 0)
#endif

#ifndef nelem
#define nelem(x) (sizeof(x)/sizeof((x)[0]))
#endif

#ifndef nil
#define nil ((void*)0)
#endif

#ifndef IOUNIT
#define IOUNIT 8192
#endif

#ifdef _9FTCH_HOST
#include <unistd.h>

/* Plan 9 dup(old, new) compatibility */
static inline int
p9dup(int oldfd, int newfd)
{
  if(newfd < 0)
	return dup(oldfd);
  return dup2(oldfd, newfd);
}

/* Some 9front code calls dup(old,new) directly */
#undef dup
#define dup p9dup

/* Plan 9 DMTMP flag - no direct POSIX equivalent */
#ifndef DMTMP
#define DMTMP 0
#endif
#endif
