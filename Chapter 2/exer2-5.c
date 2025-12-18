//Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)

#include<stdio.h>
#include<string.h>
int find(char s1[],char s2[],int len1,int len2);
int main()
{
  char s1[50];
  char s2[50];
  printf("enter the string 1 : ");
  scanf("%s",s1);
  printf("enter the string 2 : ");
  scanf("%s",s2);
  int len1=strlen(s1);
  int len2=strlen(s2);
  
  int result=find(s1,s2,len1,len2);
  printf("the index is %d\n",result);//if it is -1 then no characters are matched 
  return 0;
}

int find(char s1[],char s2[],int len1,int len2)
{
  int i,j;
  for(i=0;i<len1;i++)
  {
    for(j=0;j<len2;j++)
    {
      if(s1[i]==s2[j])
      {
        return i;
      }
    }
  }
  return -1;
}
