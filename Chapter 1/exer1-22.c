//Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

#include<stdio.h>
#define MAXLENGTH 200
#define MAXCOL 20
int my_getline(char s[],int max);
int main()
{
  int len;
  char line[MAXLENGTH];
  while((len = my_getline(line,MAXLENGTH)) > 0)
  {
    int col=0;
    int last_blank=-1;
    for(int i=0;i<len;i++)
    {
      if(line[i]==' ')
      {
        last_blank=i;
      }
      putchar(line[i]);
      col++;
      if(col==MAXCOL)
      {
        if(last_blank!=-1)
        { 
          putchar('\n');
          col=0;
          last_blank=-1;
        }
        else
        {
          putchar('\n');
          col=0;
        }
      }
      
    }
  }
  return 0;
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
    s[i]='\n';
    i++;
  }
  s[i]='\0';
  return i;
}
