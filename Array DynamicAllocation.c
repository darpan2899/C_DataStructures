#include<stdio.h>
#include<malloc.h>
void insert(int *a,int n)
{
 int i;
 printf("\nenter the values of array");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
}
void display(int *a,int n)
{
 int i;
 printf("the values of array are");
 for(i=0;i<n;i++)
 {
  printf("%d",a[i]);
 }
}
void main()
{
 int n,*a;
 printf("\n enter the size of array");
 scanf("%d",&n);
 a=(int*)malloc(n*sizeof(int));
 insert(a,n);
 display(a,n);
}
