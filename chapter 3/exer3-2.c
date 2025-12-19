//Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.

#include<stdio.h>
void char_to_esc(char s[],char t[]);
void esc_to_char(char t[],char s[]);
int main()
{
  char t[100];
  char s[100];
  char r[100];
  printf("enter the string t with newline and tab : ");
  fgets(t,sizeof(t),stdin);
  
  char_to_esc(s,t);
  printf("the string t after converting new line and tab to escape : %s\n",s);
  
  esc_to_char(r,s);
  printf("the string s after converting escape seq to characters : %s\n",r);
  
  return 0;
}

void esc_to_char(char r[],char s[])
{
  int i=0;
  int j=0;
  while(s[i]!='\0')
  {
    if(s[i]=='\\')
    {
      i++;
      switch(s[i])
      {
        case 'n':
        {
          r[j]='\n';
          j++;
          break;
        }
        case 't':
        {
          r[j]='\t';
          j++;
          break;
        }
        default:
        {
          r[j]='\\';
          j++;
          r[j]=s[i];
          j++;
        }
      }
      i++;
    }
    else
    {
      r[j]=s[i];
      j++;
      i++;
    }
  }
  r[j]='\0';
}

void char_to_esc(char s[],char t[])
{
  int i=0;
  int j=0;
  while(t[i]!='\0')
  {
    char c=t[i];
    switch(c)
    {
      case '\t':
      {
        s[j]='\\';
        j++;
        s[j]='t';
        j++;
        break;
      }
      case '\n':
      {
        s[j]='\\';
        j++;
        s[j]='n';
        j++;
        break;
      }
      default:
      {
        s[j]=c;
        j++;
      }
    }
    i++;
  }
  s[j]='\0';
}
