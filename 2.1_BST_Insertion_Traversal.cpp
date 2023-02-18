#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

 struct node *InsertInTree(struct node *rt, int val)
{   
    if (rt == NULL)
    {
        struct node *root = new struct node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;

        rt =  root;// "return node" is also correct
    }

    else
    {
      if( val < rt->data)
         rt->left =  InsertInTree(rt->left, val);
      else
         rt->right = InsertInTree(rt->right, val);
    }

    return rt;
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

    root = InsertInTree(root, 10);
    root = InsertInTree(root, 8);
    root = InsertInTree(root, 15);
    root = InsertInTree(root, 5);
    root = InsertInTree(root, 20);
    root = InsertInTree(root, 9);   
    root = InsertInTree(root, 14);

    
  
    cout<<"\nElements in the tree array(Preorder Traverse) :\n";
    Preorder_Traverse(root);
  
    cout<<"\n\nElements in the tree array(Inorder Traverse) :\n";
    Inorder_Traverse(root);

    cout<<"\n\nElements in the tree array(Postorder Traverse) :\n";
    Postorder_Traverse(root);

}

