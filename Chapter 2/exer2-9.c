//In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.

#include<stdio.h>
int main()
{
  unsigned x;
  printf("enter the value of x :");
  scanf("%u",&x);
  int b=0;
  while(x!=0)
  {
    b++;
    x=x & (x-1);
  }
  printf("total bitcount = %d\n",b);
  return 0;
}
