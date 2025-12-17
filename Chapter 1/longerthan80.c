#include<stdio.h>
#define MAXLENGTH 100
int my_getline(char s[],int max);
int main()
{
  char s[MAXLENGTH];
  int len;
  while((len=my_getline(s,MAXLENGTH))>0) 
  {
    if(len>80)
    {
      printf("%s",s);
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
    else
    {
      i++; 
    }// count extra characters
  }
  if(c=='\n')
  {
    if(i<max-1)
    {
      s[i]='\n';
      i++;
    }
    else
    {
      i++;
    }
  }
  s[i<max?i:max-1]='\0';
  return i;
}

