/* host.h - POSIX host shim for building 9front 6l with gcc */

#pragma once

#include <stdarg.h>
#include <stddef.h>

/* From 9-cc POSIX portability layer */
#include "lib9.h"
#include "bio.h"

/* Plan 9 helper macros */
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

/* If IOUNIT isn't provided by the lib9/u.h world, define a sane default */
#ifndef IOUNIT
#define IOUNIT 8192
#endif
