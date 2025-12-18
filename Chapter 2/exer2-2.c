//for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
          //s[i] = c;
//Write a loop equivalent to the for loop above without using && or ||

//just writing the loop whic avoids && and || not the exact complete code 
int i=0;
while(i<lim-1)
{
  c=getchar();
  
  if(c=='\n')
  {
    break;
  }
  if(c==EOF)
  {
    break;
  }
  s[i]=c;
  i++;
  
}
 //remaining code 
