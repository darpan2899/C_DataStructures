#include<stdio.h>
int top=-1;
void push(int item,int n,int s[])
{
 if(top==n-1)
  {
   printf("\nThe stack is getting overflow");
  }
 else
  {
   top=top+1;
   s[top]=item;
  }
}
void pop(int s[])
{
 if(top==-1)
  {
   printf("\nThe stack is under underflow condition");
  }
 else
  {
   printf("\nThe popped element is %d",s[top]);
   s[top]=0;
   top=top-1;
  }
}
void display(int s[],int n)
{
 int i;
 if(top==-1)
 {
  printf("\nStack is empty");
 }
 else
 {
 printf("\nelements of stack are:");
 for(i=top;i>=0;i--)
  {
   if(i==top)
     {
       printf("\n|\t%d\t|<-----TOP\n",s[i]);
       printf("|---------------|");
     }
    else
      {
        printf("\n|\t%d\t|\n",s[i]);
        printf("|---------------|");
      }
  }
 }
}
int peep(int s[])
{
 if(top==-1)
 {
  printf("\n it is underflow condition");
 }
 else
 {
  return s[top];
 }
}
void CHANGE(int s[])
{
 int nv;

    printf("enter new element");
    scanf("%d",&nv);
    s[top]=nv;

  }
void main()
{
 int item,n,ch,st;
 printf("\nEnter the size of STACK");
 scanf("%d",&n);
 int s[n];
 do
 {
  printf("\nEnter your choice:");
  printf("\n1.PUSH\n2.POP\n3.PEEP\n4.CHANGE\n5.EXIT");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
         printf("\nEnter the value you want to add to the stack");
         scanf("%d",&item);
         push(item,n,s);
         display(s,n);
         break;
   case 2:
         pop(s);
         display(s,n);
         break;
   case 3:
        st= peep(s);
        printf("\n The top most element of stack is %d",st);
        break;
    case 4:
        CHANGE(s);
        display(s,n);
        break;
   case 5:
        printf("terminating the program\n");
        break;
   default:
        printf("wrong choice");
  }
 }
 while(ch!=5);
 }
