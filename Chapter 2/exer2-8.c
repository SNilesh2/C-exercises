//Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.

#include<stdio.h>
unsigned rightrot(unsigned x,int n);
int main()
{
  unsigned x;
  int n;
  printf("enter the value of x : ");
  scanf("%u",&x);
  printf("enter the value of n : ");
  scanf("%d",&n);
  unsigned result=rightrot(x,n);
  printf("%u\n",result);
}
unsigned rightrot(unsigned x,int n)
{
  int size=sizeof(unsigned)*8;
  unsigned right=x>>n;
  unsigned left=x<<(size-n);
  return left | right;
}
