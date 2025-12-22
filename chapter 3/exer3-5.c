//Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.

#include<stdio.h>
#include<string.h>
void itob(int n,char s[],int b);
void reverse(char s[]);
int main()
{
  int n,b;
  char s[100];
  printf("enter the number : ");
  scanf("%d",&n);
  printf("enter the base : ");
  scanf("%d",&b);
  itob(n,s,b);
  printf("%s\n",s);
  return 0;
}
void itob(int n,char s[],int b)
{
  int sign=n;
  if(n<0)
  {
    n=-n;
  }
  int j=0;
  do
  {
    int digit=n%b;
    if(digit<10)
    {
      s[j]=digit+'0';
      j++;
    }
    else
    {
      s[j]=(digit-10)+'A';
      j++;
    }
    n=n/b;
  }while(n!=0);
  if(sign<0)
  {
    s[j]='-';
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
