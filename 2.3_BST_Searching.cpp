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

struct node* BST_search(struct node* root, int val)
{
    if(root == NULL)
         return NULL;
    
    if(root->data == val)
         return root;
         
    if(val < root->data)
         return  BST_search(root->left, val);

    if(val > root->data)
        return  BST_search(root->right, val);
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

  
    cout<<"\n\nElements in the tree array(Inorder Traverse) :\n";
    Inorder_Traverse(root);

    struct node* n;
    n = BST_search(root, 14);
    if(n == NULL)  cout<<"\nElement not found\n";
    else           cout<<"\nElement found : "<<n->data;

}

