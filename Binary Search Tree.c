#include<stdio.h>
#include<stdlib.h>
struct node
 {
  struct node *left;
  int data;
  struct node *right;
 }*root='\0';
 int val;

struct node *create_bst(struct node *root,int val)
{
 struct node *new_node;
  if(root=='\0')
  {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=val;
   new_node->right='\0';
   new_node->left='\0';
   return new_node;
  }
  else
  {
   if(val<root->data)
   {
    root->left=create_bst(root->left,val);
   }
   else
   {
    root->right=create_bst(root->right,val);
   }
  }
 // printf("\nEnter data \n(Press -1 for end)");
  //scanf("%d",&val);
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
 int ch,val;
 while(val!=-1)
 {
 printf("\nEnter the value you want to add to the TREE:\n(Press -1 for end)");
 scanf("%d",&val);
 root=create_bst(root,val);
 }
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
   
