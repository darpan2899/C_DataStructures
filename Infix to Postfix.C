#include<stdio.h>
#include<string.h>
#define N 50
int top=-1;
int j=0;
char s[N];
char infix[N];
char postfix[N];
int prec(char op)
 {
  if(op=='^'||op=='$')
     return 5;
 else if(op=='/'||op=='*')
     return 4;
 else if(op=='+'||op=='-')
     return 3;
  }
void push(char op)
{
 if(top>=N-1)
  {
   printf("\nThe stack is getting overflow");
  }
 else
  {
   top=top+1;
   s[top]=op;
  }
}
char pop()
{
 char y=NULL;
 if(top==-1)
  {
   printf("\nThe stack is under underflow condition");
  }
 else
  {
   y=s[top];
   s[top]=0;
   top=top-1;
  }
  return y;
}

int main()
{
char op,element;
int i;
printf("\nEnter the infix expression with extra ) ");
gets(infix);
printf("\nCHARACTER\tSTACK\tPOSTFIX EXP");
push('(');
for(i=0;infix[i]!=NULL;i++)
 {
  op=infix[i];
  if(op>='a' && op<='z')
      {
       postfix[j]=op;
       j++;
       }
 else if(op=='(')
   {
    push(op);
   }
  else if(op==')')
   {
     while((element=pop())!='(')
       {
         postfix[j]=element;
         j++;
       }
    }
   else
	{
		while(prec(op)<=prec(s[top]))
                {
                  if(s[top]=='(')
                   break;
                      element=pop();
                      postfix[j]=element;
                        j++;
                   }
                 push(op);
	}
    postfix[j]=NULL;
    printf("\n%c\t\t%s\t\t%s",op,s,postfix);
    scanf("%c",&op);
   }

   return 0;
}
