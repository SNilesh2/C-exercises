//Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

#include<stdio.h>
unsigned invert(unsigned x,int p,int n);
int main()
{
  unsigned x;
  int n,p;
  printf("enter the value of X : ");
  scanf("%u",&x);
  printf("enter the position p : ");
  scanf("%d",&p);
  printf("enter the value of n : ");
  scanf("%d",&n);
  unsigned result=invert(x,p,n);
  printf("%u\n",result);
  return 0;
}
unsigned invert(unsigned x,int p,int n)
{
  unsigned y=x;
  unsigned mask= (~(~0<<n))<<(p+1-n);
  return mask^x;
}
