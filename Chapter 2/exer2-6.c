//Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.

#include<stdio.h>
unsigned setbits(unsigned x,unsigned y,int p,int n);
int main()
{
  unsigned x,y;
  int p;
  int n;
  printf("enter the value of x : ");
  scanf("%u",&x);
  printf("enter the value of y : ");
  scanf("%u",&y);
  printf("enter the position p : ");
  scanf("%d",&p);
  printf("enter the value of n : ");
  scanf("%d",&n);
  unsigned result=setbits(x,y,p,n);
  printf("%u\n",result);
  return 0;
}
unsigned setbits(unsigned x,unsigned y,int p,int n)
{
  unsigned mask=~(~0<<n);
  y=(y & mask)<<(p+1-n);
  x= x & ~(mask<<(p+1-n));
  return x|y;
}
