//Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

#include<stdio.h>
#include<string.h>
#define MAX 100
int strindex(char s[],char t[]);
int main()
{
  char s[MAX];
  char t[MAX];
  printf("enter the string s : ");
  fgets(s,MAX,stdin);
  printf("enter the string t : ");
  fgets(t,MAX,stdin);
  //fgets stores newline before '\0' always so remove '\n'
  int tlen=strlen(t);
  for(int i=0;i<tlen;i++)
  {
    if(t[i]=='\n')
    {
      t[i]='\0';
      break;
    }
  }
  int ind=strindex(s,t);
  if(ind<0)
  {
    printf("no  matches found");
  }
  else
  {
    printf("match found at index %d\n",ind);
  }
  return 0;
}

int strindex(char s[],char t[])
{
  int pos=-1;
  int slen=strlen(s);
  int tlen=strlen(t);
  for(int i=0;i<slen-tlen;i++)
  {
    int sind=i;
    int tind=0;
    while(t[tind]!='\0')
    {
      if(t[tind]==s[sind])
      {
        tind++;
        sind++;
      }
      else
      {
        break;
      }
    }
    if(tind==tlen)
    {
      pos=i;
    }
  }
  return pos;
}
