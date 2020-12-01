#include<stdio.h>
#include<stdlib.h>
struct node
 {
  int data;
  struct node *next;
 }*start='\0';
 int val;
 
void create_singly_ll()
{
 struct node *new_node,*ptr;
 printf("\nEnter the value you want to add to the LINKED LIST:\n(Press -1 for end)");
 scanf("%d",&val);
 while(val!=-1)
 {
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
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
   printf("\nEnter data \n(Press -1 for end)");
   scanf("%d",&val);
 }
}
void display_singly_ll()
{
 struct node *ptr;
 printf("Linked list is:\n");
 ptr=start;
 while(ptr!='\0')
 {
  printf("\n %d->",ptr->data);
  ptr=ptr->next;
 }
  printf("\n NULL");
}
void singly_insert_beg(int val)
{
 struct node *new_node;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(new_node=='\0')
 {
  printf("\nOverflow");
 }
 else
 {
  new_node->data=val;
  new_node->next=start;
  start=new_node;
 }
}
void singly_insert_end(int val)
{
 struct node *new_node,*ptr;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(new_node=='\0')
 {
  printf("\nOverflow");
 }
 else
 {
  new_node->data=val;
  new_node->next='\0';
  ptr=start;
  while(ptr->next!='\0')
  {
   ptr=ptr->next;
  }
  ptr->next=new_node;
 } 
}
void singly_insert_afternode(int val,int num)
{
 struct node *new_node,*ptr,*preptr;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(new_node=='\0')
 {
  printf("\nOverflow");
 }
 else
 {
  new_node->data=val;
  ptr=start;
  preptr=ptr;
  while(preptr->data!=num)
  {
   preptr=ptr;
   ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
 } 
}
void singly_insert_before(int val,int num)
{
 struct node *new_node,*ptr,*preptr;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(new_node=='\0')
 {
  printf("\nOverflow");
 }
 else
 {
  new_node->data=val;
  ptr=start;
  preptr=ptr;
  while(ptr->data!=num)
  {
   preptr=ptr;
   ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
 } 
}
void singly_sorted_insert(int val,int num)
{
 struct node *new_node,*ptr,*preptr;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(new_node=='\0')
 {
  printf("\nOverflow");
 }
 else
 {
  new_node->data=val;
  ptr=start;
  preptr=ptr;
  while(ptr->data<num)
  {
   preptr=ptr;
   ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
 } 
}
void singly_delete_first()
{
 struct node *new_node,*ptr;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   start=start->next;
   free(ptr);
  }
}
void singly_delete_last()
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
   while(ptr->next!='\0')
   {
   preptr=ptr;
   ptr=ptr->next;
   }
   preptr->next='\0';
   free(ptr);
  }
}
void singly_delete_after(int num)
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
   while(preptr->data!=num)
   {
    preptr=ptr;
   ptr=ptr->next;
   }
   preptr->next=ptr->next;
   free(ptr);
  }
}
void singly_delete_specific(int num)
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
   while(ptr->data!=num)
   {
   preptr=ptr;
   ptr=ptr->next;
   }
   preptr->next=ptr->next;
   free(ptr);
  }
}
void singly_delete_before(int num)
{ 
 struct node *new_node,*ptr,*preptr,*prepreptr;
  if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   preptr=ptr;
   prepreptr=ptr;
   while(ptr->data!=num)
   {
   prepreptr=preptr;
   preptr=ptr;
   ptr=ptr->next;
   }
   prepreptr->next=preptr->next;
   free(preptr);
  }
}
 
 
 
void main()
{
 int num,ch1;
 int ch;
 create_singly_ll();
 display_singly_ll();
 do
 {
   printf("\nEnter your choice:");
  printf("\n1.TRAVERSE\n2.INSERT\n3.DELETE\n4.EXIT");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
          display_singly_ll();
          break;
   case 2:
           do
           {
            printf("\nEnter your choice:");
            printf("\n1.INSERT AT BEGINING\n2.INSERT AT END\n3.INSERT AFTER GIVEN NODE\n4.INSERT BEFORE GIVEN NODE\n5.INSERT IN SORTED LIST\n6.Back To Main Menu");
            scanf("%d",&ch1);
            switch(ch1)
            {
             case 1:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    singly_insert_beg(val);
                    display_singly_ll();
                    break;
             case 2:
                     printf("\nEnter the value you want to enter");
                     scanf("%d",&val);
                     singly_insert_end(val);
                     display_singly_ll();
                     break;
             case 3:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    printf("\nEnter the number after which you want to insert the NODE");
                    scanf("%d",&num);
                    singly_insert_afternode(val,num);
                    display_singly_ll();
                    break;
             case 4:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    printf("\nEnter the number before which you want to insert the NODE");
                    scanf("%d",&num);
                    singly_insert_before(val,num);
                    display_singly_ll();
                    break;
             case 5:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    singly_sorted_insert(val,num);
                    display_singly_ll();
                    break;
             case 6:
                    printf("RETURNING To Main Menu\n");
                    break;
            default:
                    printf("wrong choice");
            }
          }
            while(ch1!=6);
            break;
    
     case 3:
           do
           {
            printf("\nEnter your choice:");
            printf("\n1.DELETE AT BEGINING\n2.DELETE AT END\n3.DELETE AFTER GIVEN NODE\n4.DELETE BEFORE GIVEN NODE\n5.DELETE SPECIFIC NODE\n6.Back To Main Menu");
            scanf("%d",&ch1);
            switch(ch1)
            {
             case 1:
                     singly_delete_first();
                     display_singly_ll();
                     break;
             case 2:
                     singly_delete_last();
                     display_singly_ll();
                     break;
             
              case 3:
                    printf("\nEnter the number after which you want to delete the NODE");
                    scanf("%d",&num);
                    singly_delete_after(num);
                    display_singly_ll();
                    break;
             case 4:
                    printf("\nEnter the number before which you want to delete the NODE");
                    scanf("%d",&num);
                    singly_delete_before(num);
                    display_singly_ll();
                    break;
             case 5:
                    printf("\nEnter the NODE you want to delete ");
                    scanf("%d",&num);
                    singly_delete_specific(num);
                    display_singly_ll();
                    break;
            
             case 6:
                    printf("RETURNING To Main Menu\n");
                    break;
            default:
                    printf("wrong choice");
            }
          }
            while(ch1!=6);
            break;                
      case 4:
             printf("terminating the program\n");
             break;  
      default:
              printf("\nWrong Choice"); 
   }
  }
   while(ch!=4);
}
                  
                    
          
             
  

 
 
