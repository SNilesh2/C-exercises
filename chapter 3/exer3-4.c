//In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.

#include<stdio.h>
#include<string.h>
void itoa(int n,char s[]);
void reverse(char s[]);
int main()
{
  int n;
  char s[50];
  printf("enter the number : ");
  scanf("%d",&n);
  itoa(n,s);
  reverse(s);
  printf("the final string is : %s\n",s);
  return 0;
}

void itoa(int n,char s[])
{
  int sign=n;
  int i=0;
  do
  {
    int digit=n%10;
    if(digit<0)
    {
      digit=-digit;
    }
    s[i]=digit+'0';
    i++;
    n=n/10;
  }while(n!=0);
  if(sign<0)
  {
    s[i]='-';
    i++;
  }
  s[i]='\0';
}

void reverse(char s[])
{
  int len=strlen(s);
  int start=0;
  int end=len-1;
  while(start<=end)
  {
    char temp=s[start];
    s[start]=s[end];
    s[end]=temp;
    start++;
    end--;
  }
}
