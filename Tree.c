#include<stdio.h>
#include<stdlib.h>
struct node
 {
  struct node *left;
  int data;
  struct node *right;
 }*root='\0';
 int val;

void create_tree()
{
 int e;
 struct node *cpt,*new_node;
 printf("\nEnter the value you want to add to the TREE:\n(Press -1 for end)");
 scanf("%d",&val);
 while(val!=-1)
 {
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->right='\0';
  new_node->left='\0';
  if(root=='\0')
  {
   root=new_node;
  }
  else
  {
   cpt=root;
   abc:  
   printf("\n on which side of %d do you want to enter the new value ",cpt->data);
   printf("\n press 1 for left\npress 2 for right");
   scanf("%d",&e);
   if(e==1)
   {
    if(cpt->left=='\0')
    {
    cpt->left=new_node;
    }
   else
    {
    cpt=cpt->left;
     goto abc;
    }
   }
   else
   {
    if(cpt->right=='\0')
    {
    cpt->right=new_node;
    }
    else
    {
    cpt=cpt->right;
     goto abc;
    }
   }
  }
   printf("\nEnter data \n(Press -1 for end)");
   scanf("%d",&val);
 }
}
void preorder(struct node *root)
{
 if(root!='\0')
 {
  printf("%d",root->data);
  preorder(root->left);
  preorder(root->right); 
 }
}
void inorder(struct node *root)
{
 if(root!='\0')
 {
  inorder(root->left);
  printf("%d",root->data);
  inorder(root->right); 
 }
}
void postorder(struct node *root)
{
 if(root!='\0')
 {
  postorder(root->left);
  postorder(root->right);
  printf("%d",root->data); 
 }
}
void main()
{
 int ch;
 create_tree();
 do
 {
  printf("\n Enter in which order you want to traverse");
  printf("\n1.preorder\n2.inorder\n3.postorder\n4.exit");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
          preorder(root);
          break;
   case 2:
          inorder(root);
          break;
   case 3:
          postorder(root);
          break;
   case 4:
          printf("\nterminating the program");
          break;
  default:
          printf("wrong choice");
   }
  }while(ch!=4);
}
   
