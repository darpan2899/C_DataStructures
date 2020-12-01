#include<stdio.h>
int insert(int a[],int n)
{
 int i,pos,val;
 printf("enter the position at which you want to enter the element");
 scanf("%d",&pos);
 printf("enter the value you want to enter at position %d \n",pos);
 scanf("%d",&val);
 pos=pos-1;
 for(i=n-1;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	n=n+1;
	a[pos]=val;
 return n;
 }
int delete(int a[],int n)
{
 int i,pos;
 printf("enter the position at which you want to delete the element");
 scanf("%d",&pos);
 pos=pos-1;
	for(i=pos;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n=n-1;
 return n;
}
void search(int a[],int n)
{
 int i,v,b,cnt=0;
 printf("enter the value you want to search");
 scanf("%d",&v);
 for(i=0;i<n;i++)
 {
  if(v==a[i])
   { 
    cnt=1; 
    printf("the position of element %d is %d",a[i],i+1);
    break;
    }
  
  }
   if(cnt==0)
    {
     printf("value not found");
     }
}
void display(int a[],int n)
{
 int i;
 printf("elements of array are:");
 for(i=0;i<n;i++)
  {
   printf("%d",a[i]);
  }
}
void update(int a[],int n)
{
 int i,v,b,t,cnt=0;
 printf("enter the value you want to replace");
 scanf("%d",&v);
 for(i=0;i<n;i++)
 {
  if(v==a[i])
   { 
    cnt=1; 
    printf("the position of element %d is %d",a[i],i+1);
    printf("enter new element");
    scanf("%d",&t);
    a[i]=t;
    break;
    }
  
  }
   if(cnt==0)
    {
     printf("value not found");
     }
}
 
void main()
{
 int a[50],i,n,ch;
 printf("enter the size of array");
 scanf("%d",&n);

 printf("enter the elements of array");
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 do
 {
  printf("\n Enter your Choice:");
  printf("\n1.insert\n2.delete\n3.search\n4.display\n5.update\n6.exit");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       n= insert(a,n);
          display(a,n);
        break;
   case 2:
       n= delete(a,n);
        display(a,n);
        break;
   case 3:
        search(a,n);
        break;
   case 4:
        display(a,n);
        break;
   case 5:
        update(a,n);
        display(a,n);
        break;
   case 6:
        printf("terminating the program\n");
        break;
   default:
        printf("wrong choice");
   }
  }
  while(ch!=6);
}
        
        
        

  
     
