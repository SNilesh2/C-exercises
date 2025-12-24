#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAXOP 100
#define NUMBER '0'
#define SIN 's'
#define EXP 'e'
#define POW 'p'
#define MAXVAL 100
#define BUFSIZE 100


int sp=0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp=0;

int getop(char s[]);
void push(double val);
double pop();
int getch();
void ungetch(int val);

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  
  while((type=getop(s))!=EOF)
  {
    switch(type)
    {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop()+pop());
        break;
      case '*':
        push(pop()*pop());
        break;
      case '-':
        op2=pop();
        push(pop()-op2);
        break;
      case '/':
        op2=pop();
        if(op2!=0)
        {
          push(pop()/op2);
        }
        else
        {
          printf("divide by zero error");
        }
        break;
      case SIN:
        push(sin(pop()));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case POW:
        op2=pop();
        push(pow(pop(),op2));
        break;
      case '\n':
        printf("%.4g\n",pop());
        break;
      default:
        printf("invalid");
        break;
    }
  }
  return 0;
}

void push(double value)
{
  if(sp<MAXVAL)
  {
    val[sp]=value;
    sp++;
  }
  else
  {
    printf("overflow");
  }
}

double pop()
{
  if(sp>=0)
  {
    sp--;
    return val[sp];
  }
  else
  {   
    printf("underflow");
  }
}

int getop(char s[])
{
  int i;
  int c;
  int next;
  while((c=getch())==' ' || c=='\t');

  if(isalpha(c))
  {
    i=0;
    while(isalpha(s[i++]=c))
    {
      c=getch();
    }
    s[i-1]='\0';
    if(c!=EOF)
    {
      ungetch(c);
    }
    
    if(strcmp(s,"sin")==0)
    {
      return SIN;
    }
    if(strcmp(s,"exp")==0)
    {
      return EXP;
    }
    if(strcmp(s,"pow")==0)
    {
      return POW;
    }
    return s[0];
  }
  
  if(!isdigit(c) && c!='.' && c!='-')
  {
    return c;
  }
  
  i=0;
  if(c=='-')
  {
    next=getch();
    if(!isdigit(next) && next!='.')
    {
      ungetch(next);
      return '-';
    }
    s[i++]=c;
    c=next;
  }
  
  if(isdigit(c))
  {
    s[i++]=c;
    while(isdigit(s[i++]=c=getch()));
  }
  
  if(c=='.')
  {
    while(isdigit(s[i++]=c=getch()));
  }
  s[i-1]='\0';
  
  if(c!=EOF)
  {
    ungetch(c);
  }
  return NUMBER;
}

int getch()
{
  if(bufp>0)
  {
    bufp--;
    return buf[bufp];
  }
  else
  {
    return getchar();
  }
}

void ungetch(int value)
{
  if(bufp<BUFSIZE)
  {
    buf[bufp]=value;
    bufp++;
  }
  else
  {
    printf("overflow");
  }
}



