#include<stdio.h>
#include<stdlib.h>
struct node
 {
  struct node *prev;
  int data;
  struct node *next;
 }*start='\0';
 int val;
 
void create_doubly_ll()
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
   new_node->prev='\0';
  }
  else
  {
   ptr=start;
   while(ptr->next!='\0')
   {
    ptr=ptr->next;
   }
   ptr->next=new_node;
   new_node->prev=ptr;
  }
   printf("\nEnter data \n(Press -1 for end)");
   scanf("%d",&val);
 }
}
void display_doubly_ll()
{
  int e;
 struct node *ptr,*preptr;
 printf("Linked list is:\n");
 ptr=start;
 while(ptr!='\0')
 {
  printf("\n %d->",ptr->data);
  preptr=ptr;
  ptr=ptr->next;
 }
  printf("\n NULL");
  printf("\ndo you want to print the linked list in reverse order?");
 printf("\npress 1 for yes\npress 2 for no");
 scanf("%d",&e);
 if(e==1)
 {
  printf("Linked list is printed in reverse order:\n");
  ptr=preptr;
  while(ptr!='\0')
  {
  printf("\n %d->",ptr->data);
  ptr=ptr->prev;
  }
 }
}
void doubly_insert_beg(int val)
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
  new_node->prev='\0';
  new_node->next=start;
  start->prev=new_node;
  start=new_node;
 }
}
void doubly_insert_end(int val)
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
  new_node->prev=ptr;
 } 
}
void doubly_insert_afternode(int val,int num)
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
  while(ptr->data!=num)
  {
   ptr=ptr->next;
  }
  new_node->next=ptr->next;
  new_node->prev=ptr;
  ptr->next=new_node;
  new_node->next->prev=new_node;
 } 
}
void doubly_insert_before(int val,int num)
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
  while(ptr->data!=num)
  {
   ptr=ptr->next;
  }
  new_node->next=ptr;
  new_node->prev=ptr->prev;
  if(ptr->prev=='\0')
   {
    start=new_node;
   }
  else
   {
    ptr->prev->next=new_node;
   }
  ptr->prev=new_node;
 } 
}
void doubly_sorted_insert(int val)
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
  while(ptr->data<val)
  {
   ptr=ptr->next;
  }
  new_node->next=ptr;
  new_node->prev=ptr->prev;
  if(ptr->prev=='\0')
   {
    start=new_node;
   }
  else
   {
    ptr->prev->next=new_node;
   }
  ptr->prev=new_node;
 } 
}
void doubly_delete_first()
{
 struct node *new_node,*ptr;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   ptr->next->prev='\0';
   start=ptr->next;
   free(ptr);
  }
}
void doubly_delete_last()
{
 struct node *new_node,*ptr,*preptr;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   while(ptr->next!='\0')
   {
   ptr=ptr->next;
   }
   ptr->prev->next='\0';
   free(ptr);
  }
}
void doubly_delete_after(int num)
{
 struct node *new_node,*ptr,*temp;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   while(ptr->data!=num)
   {
   ptr=ptr->next;
   }
   temp=ptr->next;
   ptr->next=temp->next;
   temp->next->prev=ptr;
   free(temp);
  }
}
void doubly_delete_specific(int num)
{
 struct node *new_node,*ptr,*temp;
 if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   while(ptr->data!=num)
   {
   ptr=ptr->next;
   }
   ptr->prev->next=ptr->next;
   ptr->next->prev=ptr->prev;
   free(ptr);
  }
}
void doubly_delete_before(int num)
{ 
 struct node *new_node,*ptr,*temp;
  if(start=='\0')
  {
   printf("Underflow");
  }
 else
  {
   ptr=start;
   while(ptr->data!=num)
   {
   ptr=ptr->next;
   }
   temp=ptr->prev;
   temp->prev->next=ptr;
    ptr->prev=temp->prev;
   free(temp);
  }
}
 
 
 
void main()
{
 int num,ch1;
 int ch;
 create_doubly_ll();
 display_doubly_ll();
 do
 {
   printf("\nEnter your choice:");
  printf("\n1.TRAVERSE\n2.INSERT\n3.DELETE\n4.EXIT");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
          display_doubly_ll();
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
                    doubly_insert_beg(val);
                    display_doubly_ll();
                    break;
             case 2:
                     printf("\nEnter the value you want to enter");
                     scanf("%d",&val);
                     doubly_insert_end(val);
                     display_doubly_ll();
                     break;
             case 3:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    printf("\nEnter the number after which you want to insert the NODE");
                    scanf("%d",&num);
                    doubly_insert_afternode(val,num);
                    display_doubly_ll();
                    break;
             case 4:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    printf("\nEnter the number before which you want to insert the NODE");
                    scanf("%d",&num);
                    doubly_insert_before(val,num);
                    display_doubly_ll();
                    break;
             case 5:
                    printf("\nEnter the value you want to enter");
                    scanf("%d",&val);
                    doubly_sorted_insert(val);
                    display_doubly_ll();
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
                     doubly_delete_first();
                     display_doubly_ll();
                     break;
             case 2:
                     doubly_delete_last();
                     display_doubly_ll();
                     break;
             
              case 3:
                    printf("\nEnter the number after which you want to delete the NODE");
                    scanf("%d",&num);
                    doubly_delete_after(num);
                    display_doubly_ll();
                    break;
             case 4:
                    printf("\nEnter the number before which you want to delete the NODE");
                    scanf("%d",&num);
                    doubly_delete_before(num);
                    display_doubly_ll();
                    break;
             case 5:
                    printf("\nEnter the NODE you want to delete ");
                    scanf("%d",&num);
                    doubly_delete_specific(num);
                    display_doubly_ll();
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
                  
                    
          
             
  

 
 
