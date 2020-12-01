#include<stdio.h>
int Q[50];
int f=-1,r=-1;
void QINSERT(int n,int item)
{
  if(r>=n-1)
  {
   printf("\nTHE QUEUE IS OVERFLOW");
  }
  else
  {
   if(f==-1)
   {
    f=0;
    r=0;

   }
   else
   {

    r=r+1;
   }
Q[r]=item;
  }
}
int QDELETE(int n)
{
 int y=NULL;
 if(f==-1)
 {
  printf("\nThe QUEUE is empty");
 }
 else
 {
  y=Q[f];
  Q[f]=0;
   if(f==r)
   {
   f=-1;
   r=-1;
   }
   else
   {
    f=f+1;
   }
 }
 return y;
}
void display(int item)
{
 int i;
 if(f==-1)
 {
  printf("\nQUEUE is empty");
 }
 else
 {
 printf("\nelements of QUEUE are:");
 for(i=f;i<=r;i++)
  {
    printf("|%d|",Q[i]);
  }
 }
}
int main()
{
 int n,x,item,choice;
 printf("\nENTER THE SIZE OF QUEUE:");
 scanf("%d",&n);
 do
 {
  printf("\nENTER YOUR CHOICE");
  printf("\n1.INSERT\n2.DELETE\n3.EXIT");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
           printf("\nEnter the value you want to add to the QUEUE");
           scanf("%d",&item);
           QINSERT(n,item);
           display(item);
           break;
   case 2:
          x=QDELETE(n);
          printf("\nTHE ELEMENT DELETED IS %d",x);
          display(item);
          break;
   case 3:
          printf("terminating the program\n");
          break;
   default:
        printf("wrong choice");
   }
 }
 while(choice!=3);
 return 0;
}


