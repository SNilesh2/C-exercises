//Exercise 4-4. Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100
#define NUMBER '0'
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
void print_top();
void duplicate_top();
void swap_top();
void clear_stack();

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  
  while((type=getop(s))!=EOF)
  {
    //printf("%d",type);
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
      case 'p':
        print_top();
        break;
      case 'd':
        duplicate_top();
        break;
      case 's':
        swap_top();
        break;
      case 'c':
        clear_stack();
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
  
  s[0]=c;
  s[1]='\0';
  
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
    s[++i]=next;
    c=next;
  }
  
  if(isdigit(c))
  {
    while(isdigit(s[++i]=c=getch()));
  }
  
  if(c=='.')
  {
    while(isdigit(s[++i]=c=getch()));
  }
  s[i]='\0';
  
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

void print_top()
{
  if(sp>0)
  {
    printf("Stack top value : %.8g\n",val[sp-1]);
  }
  else
  {
    printf("stack is empty"); 
  }
}

void duplicate_top()
{
  if(sp>0)
  {
    push(val[sp-1]);
  }
  else
  {
    printf("stack is empty");
  }
}

void swap_top()
{
  if(sp>1)
  {
    double temp=val[sp-1];
    val[sp-1]=val[sp-2];
    val[sp-2]=temp;
  }
  else
  {
    printf("there is no two numbers to swap");
  }
}

void clear_stack()
{
  sp=0;
}

