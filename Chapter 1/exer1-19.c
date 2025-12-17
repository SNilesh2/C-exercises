//Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

#include<stdio.h>
#define MAXLENGTH 50
int my_getline(char s[],int max);
void reverse(char s[],int len);
int main()
{
  int len;
  char line[MAXLENGTH];
  while((len = my_getline(line,MAXLENGTH))>0)
  {
    reverse(line,len-1);
    printf("%s",line);
  }
}

void reverse(char s[],int length)
{
  if(length>=0 && s[length]=='\n')
  {
     length--;
  }
  int start=0;
  int end=length;
  while(start<=end)
  {
    char temp = s[start];
    s[start]=s[end];
    s[end]=temp;
    start++;
    end--;
  }
}
int my_getline(char s[],int max)
{
   int c;
   int i=0;
   while((c=getchar())!=EOF && c!='\n')
   {
     if(i<max-1)
     {
       s[i]=c;
       i++;
     }
   }
   if(c=='\n')
   {
     if(i<max-1)
     {
       s[i]='\n';
       i++;
     }
   }
   s[i]='\0';
   return i;
}
