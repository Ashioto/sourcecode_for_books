#include<stdio.h>
#include<math.h>
int
main ()
{
  int a, b, c;
  float d, e, f;
  d = sqrt (-10);
  e = 1.0 / 0.0;
  f = 0.0 / 0.0;
  a = 1 / 0;
  printf ("result is %f,%f,%f,%d.\n", d, e, f, a);
  return 0;
}
