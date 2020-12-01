#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
 {
  int serialno;
  char book[50];
  char author[50];
  int data;
  struct node *next;
 }*start='\0';
 char y,n;
 char b[50],tp[50];
 char a[50];
 int c,ch; 
 int sn;

void create_singly_ll()
{
 struct node *new_node,*ptr;
do 
{
 printf("\n enter serial no.");
 scanf("%d",&sn);
 printf("\nEnter the book you want to add to the library:");
 gets(tp);
 gets(b);
 printf("\nEnter the author of the book you added to the library:");
 gets(a);
 printf("\nenter the number of copies available for the book");
 scanf("%d",&c);

  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->serialno=sn;
  strcpy(new_node->book,b);
  strcpy(new_node->author,a);
  new_node->data=c;
  new_node->next='\0';
  if(start=='\0')
  {
   start=new_node;
  }
  else
  {
   ptr=start;
   while(ptr->next!='\0')
   {
    ptr=ptr->next;
   }
   ptr->next=new_node;
  }
  
   printf("\ndo you want to enter more books? \n(Press 1 for yes \npress 0  for end)");
   scanf("%d",&ch);
 
 }while(ch!=0);
}
void display_singly_ll()
{
 struct node *ptr,*new_node;
 printf("Library book list is:\n");
 ptr=start;
 while(ptr!='\0')
 {
  printf("\nserialno. %d",sn);
  puts(tp);
  printf("\nBook:");
  puts(new_node->book);
   printf("\nAuthor:");
  puts(new_node->author);
  printf("\n No. of copies %d",new_node->data);
  ptr=ptr->next;
  }
}
void issuebook(int sn1)
{
 struct node *new_node,*ptr,*preptr;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   preptr=ptr;
   while(ptr->serialno!=sn1)
   {
   preptr=ptr;
   ptr=ptr->next;
   }
   if(ptr->data<=0)
   {
    printf("book not available"):
    }
    else
    {
     ptr->data=ptr->data-1; 
     }
  }
}
void returnbook(int sn1)
{
 struct node *new_node,*ptr,*preptr;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   preptr=ptr;
   while(ptr->serialno!=sn1)
   {
   preptr=ptr;
   ptr=ptr->next;
   }
    else
    {
     ptr->data=ptr->data+1; 
     }
  }
}
void main()
{
 int sn1,ch1;
 create_singly_ll();
 display_singly_ll();
 do
 {
  printf("\n enter your choice:");
   printf("\n1.issue\n2.return\n3.EXIT");
  scanf("%d",&ch1);
  switch(ch1)
  {
   case 1:
           display_singly_ll();
           printf("\nEnter the serial no. of the book you ant to issue");
           scanf("%d",&sn1);
           issuebook(sn1);
           break;
  case 2:
           display_singly_ll();
           printf("\nEnter the serial no. of the book you ant to return");
           scanf("%d",&sn1);
           returnbook(sn1);
           break;
   case 3:
           printf("terminating the program\n");
           break;
   default:
           printf("wrong choice");
   }
 }while(ch1!=3)
}
