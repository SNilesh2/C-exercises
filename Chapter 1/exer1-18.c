//Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include<stdio.h>
#define MAXLENGTH 20
int my_getline(char s[],int maxi);
int removetrailing(char str[],int size);
int main()
{
   int len;
   char line[MAXLENGTH];
   while((len = my_getline(line,MAXLENGTH)) > 0)
   { 
     len = removetrailing(line,len);
     if(len>0)
     {
       printf("%s",line);
     }
   }
   return 0;
}

int removetrailing(char s[],int length)
{
  int i=length-1;
  if(i>=0 && s[i]=='\n')
  {
    i--;
  }
  while(i>=0 && (s[i]==' ' || s[i]=='\t'))
  { 
     i--;
  }
  if(i>=0)
  {
    s[i+1]='\n';
    s[i+2]='\0';
    return i+2;
  }
  s[0]='\0';
  return 0;
}

int my_getline(char s[],int max)
{
   int c;
   int i=0;
   while((c=getchar()) != EOF && c!='\n')
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
