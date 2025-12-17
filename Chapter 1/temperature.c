//Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
#include<stdio.h>
float convert(int fahr)
{
  float cels = (fahr - 32) * 5.0/9.0 ;
  return cels; 
}

int main()
{
  for(int fahr=0;fahr<=300;fahr=fahr+20)
  {
    float celsius = convert(fahr);
    printf("%3d %6.1f \n",fahr,celsius);
  }
}//end of program
