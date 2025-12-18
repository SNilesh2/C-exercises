//Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
  //signed type
  printf("Signed Types\n");
  printf("signed char Min : %d ,signed char max : %d\n",SCHAR_MIN,SCHAR_MAX);
  printf("signed short Min : %d ,signed short max : %d\n",SHRT_MIN,SHRT_MAX);
  printf("signed int Min : %d ,signed int max : %d\n",INT_MIN,INT_MAX);
  printf("signed long Min : %ld ,signed long max : %ld\n",LONG_MIN,LONG_MAX);
  
  //unsigned types
  printf("unsigned char : 0 to %u\n",UCHAR_MAX);
  printf("unsigned short : 0 to %u\n",USHRT_MAX);
  printf("unsigned int : 0 to %u\n",UINT_MAX);
  printf("unsigned long : 0 to %lu\n",ULONG_MAX);

  //floating point types
  printf("float min : %e ,float max : %e\n",FLT_MIN,FLT_MAX);
  printf("double Min : %e ,double max : %e\n",DBL_MIN,DBL_MAX);
  printf("long double Min : %Le ,long double max : %Le\n",LDBL_MIN,LDBL_MAX);
  
  return 0;
}
