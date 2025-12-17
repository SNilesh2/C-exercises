//Write a program to print a histogram of the frequencies of different characters in its input.
#include<stdio.h>
#define MAXCHAR 26
int main()
{
  int c;
  int freq[MAXCHAR]={0};
  while((c=getchar())!=EOF)
  {
    if(c >= 'a' && c <= 'z')
    {
      freq[c-'a']++; 
    }
    else if(c >= 'A' && c <= 'Z')
    {
      freq[c-'A']++;
    }
  }//end of loop

  for(int i=0;i<MAXCHAR;i++)
  {
     printf("%2c |",'a'+i);
     for(int j=0;j<freq[i];j++)
     {
       printf("*");
     }
     printf("\n");     
  }

  
}


