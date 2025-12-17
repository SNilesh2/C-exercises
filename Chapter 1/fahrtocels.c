//fahrenheit to celsius
#include<stdio.h>
int main()
{
  int cels,fahr;
  int step=20;
  fahr=0;
  while(fahr<=300)
  {
    cels=(fahr-32)*5/9;
    printf("%d\t%d\n",fahr,cels);
    fahr=fahr+step;
  }
  return 0;
}

