//Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

#include<stdio.h>
#include<string.h>
void itoa(int n,char s[],int w);
void reverse(char s[]);
int main()
{
  int n;
  int w;
  char s[100];
  printf("enter the number : ");
  scanf("%d",&n);
  printf("enter the width : ");
  scanf("%d",&w);
  itoa(n,s,w);
  printf("%s\n",s);
  return 0;
}

void itoa(int n,char s[],int w)
{
  int sign=n;
  int j=0;
  do
  {
    int digit=n%10;
    if(digit<0)
    {
      digit=-digit;
    }
    s[j]=digit+'0';
    j++;
    n=n/10;
  }while(n!=0);
  if(sign<0)
  {
    s[j]='-';
    j++;
  }
  while(j<w)
  {
    s[j]=' ';
    j++;
  }
  s[j]='\0';
  reverse(s);
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

