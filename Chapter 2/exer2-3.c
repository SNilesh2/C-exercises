//Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F

#include<stdio.h>
int htoi(char s[]);
int main()
{
  char s[50];
  printf("Enter the hexa decimal value : ");
  scanf("%s",s);
  
  int decimal = htoi(s);
  printf("The decimal value is %d\n",decimal);
  return 0;
}

int htoi(char s[])
{
  int i=0;
  int deci=0;
  if((s[i]=='0' && s[i+1]=='x') || (s[i]=='0' && s[i+1]=='X'))
  {
   i=i+2;
  }
  else
  {
    i=0;
  }
  while(s[i]!='\0')
  {
    if(s[i]>='0' && s[i]<='9')
    {
      deci=(deci*16)+(s[i]-'0');
    }
    else if(s[i]>='a' && s[i]<='z')
    {
      deci=(deci*16)+(s[i]-'a'+10);
    }
    else if(s[i]>='A' && s[i]<='Z')
    {
     deci=(deci*16)+(s[i]-'A'+10);
    }
    else
    {
      printf("Invalid character");
      return -1;
      break;
    }
    i++;
  }
  return deci;
}
