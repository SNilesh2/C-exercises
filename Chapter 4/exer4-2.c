//Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.

#include<stdio.h>
#include<ctype.h>
double atof(char s[]);
int main()
{
  char s[100];
  printf("enter the string :");
  scanf("%s",s);
  double result=atof(s);
  printf("the soln is %lf\n",result);
  return 0;
}

double atof(char s[])
{
  int i=0;
  int sign=(s[i]=='-')?-1:1 ;
  if(s[i]=='-' || s[i]=='+')
  {
    i++;
  }
  double val=0.0;
  while(isdigit(s[i]))
  {
    val=(val*10.0) + (s[i]-'0');
    i++;
  }
  if(s[i]=='.')
  {
    i++;
  }
  //fraction part
  double frac=1.0;
  while(isdigit(s[i]))
  {
    val=(val*10.0)+(s[i]-'0');
    frac=frac*10.0;
    i++;
  }
  double calc=(sign*val)/frac;
  //exponentiation
  if(s[i]=='e' || s[i]=='E')
  {
    i++;
  }
  int expsign=(s[i]=='-')?-1:1;
  if(s[i]=='-' || s[i]=='+')
  {
    i++;
  }
  int exp=0;
  while(isdigit(s[i]))
  {
    exp=exp*10 + (s[i]-'0');
    i++;
  }
  while(exp>0)
  {
    calc = (expsign==-1)?calc/10 : calc*10 ;
    exp--;
  }
  return calc;
}


