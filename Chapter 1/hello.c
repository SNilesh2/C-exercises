//Write a program to print a histogram of the lengths of words in its input.
#include<stdio.h>
#define MAXLENGTH 10
int main()
{
int c;
int len=0;
int wordsize[MAXLENGTH+1]={0};
while((c=getchar())!=EOF)
{
   if(c == '\n' || c == '\t' || c == ' ')
   {
     if(len>0 && len<=MAXLENGTH)
     {
       wordsize[len]++;
       len=0;
     }
   }
   else
   {
      len++;
   }
}//end of while

//for last word 

if(len>0 && len<=MAXLENGTH)
{
  wordsize[len]++;
  len=0;
}

//printing histogram 

for(int i=1;i<=MAXLENGTH;i++)
{
   printf("%2d sized words |",i);
   for(int j=0;j<wordsize[i];j++)
   {
     printf("*");
   }
   printf("\n");
}

}

