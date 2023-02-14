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

int main() 
{
    // struct node *root= new struct node;   
    // root->data =10;
    // root->left = NULL;
    // root->right = NULL;
    
    // cout<<root->data<<" "<<root->left<<" "<< root->right;
    
    //Creating a binary tree successfully, Just the root node though
    struct node *root = new struct node;
    root = NULL;
    root = tree(root, 1);
       cout<<root->data<<" "<<root->left<<" "<< root->right;
       
    //Creating  two child of the parent root
    struct node *child1 = new struct node;    child1->data = 2;
    struct node *child2 = new struct node;    child2->data = 3;

    root->left = child1;
    root->right = child2;
    return 0;
}