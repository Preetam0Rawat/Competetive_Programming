#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

 void *InsertInTree(struct node **rt, int val)
{   
    if (*rt == NULL)
    {
        struct node *root = new struct node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;

        *rt =  root;
    }

    else
    {
      if( val < (*rt)->data)
            InsertInTree(&(*rt)->left, val);
      else
            InsertInTree(&(*rt)->right, val);
    }

}

void Preorder_Traverse(struct node *rt)         // N-L-R
{
  if(rt == NULL)
    return;
  else
  {
     cout<<rt->data<<" ";
     Preorder_Traverse(rt->left);
     Preorder_Traverse(rt->right);         
  }
}

void Inorder_Traverse(struct node *rt)           // L-N-R
{
  if(rt == NULL)
    return;
  else
  {
     Inorder_Traverse(rt->left);
     cout<<rt->data<<" ";
     Inorder_Traverse(rt->right);         
  }
}

void Postorder_Traverse(struct node *rt)          // L-R-N
{
  if(rt == NULL)
    return;
  else
  {
     Postorder_Traverse(rt->left);
     Postorder_Traverse(rt->right);   
     cout<<rt->data<<" ";
 }
}


int main()
{
    struct node *root;
    root = NULL;

     InsertInTree(&root, 10);
     InsertInTree(&root, 8);
     InsertInTree(&root, 15);
     InsertInTree(&root, 5);
     InsertInTree(&root, 20);
     InsertInTree(&root, 9);   
     InsertInTree(&root, 14);

    
  
    cout<<"\nElements in the tree array(Preorder Traverse) :\n";
    Preorder_Traverse(root);
  
    cout<<"\n\nElements in the tree array(Inorder Traverse) :\n";
    Inorder_Traverse(root);

    cout<<"\n\nElements in the tree array(Postorder Traverse) :\n";
    Postorder_Traverse(root);

}

