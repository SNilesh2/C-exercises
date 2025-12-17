//Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

#include<stdio.h>
#define TAB 6
int main()
{
  int c;
  int space;
  int col=0;
  while((c=getchar())!=EOF)
  {
    if(c=='\t')
    {
      space=TAB - (col%TAB);
      for(int i=0;i<space;i++)
      {
        putchar(' ');
        col++;
      }
    }
    else if(c=='\n')
    {
      putchar('\n');
      col=0;
    }
    else
    {
      putchar(c);
      col++;
    }
  }
  return 0;
}
