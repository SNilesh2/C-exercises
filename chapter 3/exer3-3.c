//Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

#include<stdio.h>
#include<ctype.h>
int main()
{
  char s1[100];
  char s2[1000];
  printf("enter a string : ");
  scanf("%s",s1);
  int i=0;
  int j=0;
  char start,end;
  while(s1[i]!='\0')
  {
    if(s1[i]=='-' && i>0 && s1[i+1]!='\0' && ( (islower(s1[i-1]) && islower(s1[i+1])) || (isupper(s1[i-1]) && isupper(s1[i+1])) || (isdigit(s1[i-1]) && isdigit(s1[i+1]))) )
    {
      start=s1[i-1];
      end=s1[i+1];
      if(start<end)
      {
        for(char c=start+1;c<=end;c++)
        {
          s2[j]=c;
          j++;
        }
        i=i+2;
      }
      else
      {
        s2[j]='-';
        j++;
        i++;
      }
    }
    else
    {
      s2[j]=s1[i];
      j++;
      i++;
    }
    //i++;
  }
  s2[j]='\0';
  printf("after expansion : %s\n",s2);
  return 0;
}
