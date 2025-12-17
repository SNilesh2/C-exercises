//Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include<stdio.h>
#define TAB 6
int main()
{ 
  int c;
  int space=0;
  int col=0;
  while((c=getchar())!=EOF)
  {
    if(c==' ')
    {
      space++;
      col++;
    }
    else
    {
      while(space>0)
      {
        int tab=TAB-((col-space)%TAB);
        if(tab>1 && space>=tab)//tab>1 for minimum number of \t
        {
          putchar('\t');
          space=space-tab;
        }
        else
        { 
          putchar(' ');
          space--;
        }
      }
      putchar(c);//character after space  
      if(c=='\n')
      {
        col=0;
      }
      else if('\t')//tab is not included we include only spaces
      {
        col=col+TAB;
      }
      else
      {
        col++;
      }
    }
  }
  return 0;
}

