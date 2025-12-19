//Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.

#include<stdio.h>
int lower(char c);
int main()
{
  char c;
  printf("enter the character : " );
  scanf("%c",&c);
  int result=lower(c);
  printf("%c",result);
  return 0;
}
int lower(char c)
{
  return (c>='A' && c<='Z')? c+'a'-'A' : c; 
}
