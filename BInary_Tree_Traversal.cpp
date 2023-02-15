// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* tree(struct node *n, int key)
{ 
  if(n == NULL)
  {  
     struct node *nnode = new struct node;
      nnode->data = key;
      nnode->left = NULL;
      nnode->right = NULL;
      n = nnode;
  }
  return n;
}
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
       cout<<root->data;    
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    
    cout<<root->data;
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
        
    inorder(root->left);
    inorder(root->right);
        cout<<root->data<<"  ";
}

int main() 
{
  
    struct node *root ;
    root = NULL;
    root = tree(root, 1);
       
    struct node *child1 = new struct node;    child1->data = 2;
    struct node *child2 = new struct node;    child2->data = 3;

    root->left = child1;
    root->right = child2;
    
    cout<<"Inorder: ";      inorder(root);
    cout<<"\nPreorder :";   preorder(root);
    cout<<"\nPostorder :";  postorder(root);
    return 0;
}