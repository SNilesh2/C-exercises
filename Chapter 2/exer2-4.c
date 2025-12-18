//Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.

#include<stdio.h>
#include<string.h>
int main()
{
  char s1[50];
  char s2[50];
  printf("Enter s1 : ");
  scanf("%s",s1);
  printf("Enter s2 : ");
  scanf("%s",s2);
  int len1=strlen(s1);
  int len2=strlen(s2);
  int k=0;
  int i,j;
  for(i=0;i<len1;i++)
  {
    for(j=0;j<len2;j++)
    {
      if(s1[i]==s2[j])
      {
        break;
      }
    }
    if(s2[j]=='\0')
    {
      s1[k]=s1[i];
      k++;
    }
  }
  s1[k]='\0';
  printf("after removal : %s\n",s1);
  return 0;
}
