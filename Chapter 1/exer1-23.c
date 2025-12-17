//Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.
#include<stdio.h>
#define NORMAL 0
#define SL 1
#define ML 2
#define STR 3
#define CHAR 4
int main()
{
  int c,prev=0;
  int state=NORMAL;
  while((c=getchar())!=EOF)
  {
    if(state==NORMAL)
    {
      if(prev=='/' && c=='/')
      {
        state=SL;
        prev=0;
      }
      else if(prev=='/' && c=='*')
      {
        state=ML;
        prev=0;
      }
      else if(c=='"')
      {
        if(prev)
        {
          putchar(prev);
        }
        putchar(c);
        state=STR;
        prev=0;
      }
      else if(prev=='\'')
      {
        if(prev)
        {
          putchar(prev);
        }
        putchar(c);
        state=CHAR;
        prev=0;
      }
      else
      {
        if(prev)
        { 
          putchar(prev);
        }
        prev=c;
      }
    }
    else if(state==SL)
    {
      if(c=='\n')
      {
        putchar('\n');
        state=NORMAL;
      }
    }
    else if(state==ML)
    {
      if(prev=='*' && c=='/')
      {
        state=NORMAL;
        prev=0;
      }
      else
      {
        prev=c;
      }
    }
    else if(state==STR)
    {
      putchar(c);
      if(c=='"' && prev!='\\')
      {
        state=NORMAL;
      }
      prev=c;
    }
    else if(state==CHAR)
    {
      putchar(c);
      if(c=='\'' && prev!='\\')
      {
        state=NORMAL;
      }
      prev=c;
    }
  }
  if(state==NORMAL && prev)
  {
    putchar(prev);
  }
  return 0;
}
