#include "cc.h"
#include <unistd.h>
#include <string.h>
#include <math.h>

static char *hunk;
static long nhunk;

static void
gethunk(long min)
{
  long n;
  char *p;

  /* allocate in chunks */
  n = 64*1024;
  if(min > n)
	n = (min + 4095) & ~4095;

  p = sbrk(n);
  if(p == (char*)-1)
	sysfatal("out of memory");

  hunk = p;
  nhunk = n;
}

void*
alloc(long n)
{
  void *p;

  if(n <= 0)
	n = 1;

  n = (n + sizeof(void*)-1) & ~(sizeof(void*)-1);

  if(hunk == nil || nhunk < n)
	gethunk(n);

  p = hunk;
  hunk += n;
  nhunk -= n;
  memset(p, 0, n);
  return p;
}

void*
allocn(void *old, long on, long n)
{
  void *p;

  p = alloc(on + n);
  if(old != nil && on > 0)
	memmove(p, old, on);
  return p;
}

int
isInf(double d, int sign)
{
  (void)sign;
  return isinf(d) != 0;
}
