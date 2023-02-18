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
struct node* inorder_successor(struct node* n)
{
    while(n->left != NULL)
       {  n = n->left;}
       return n;
     
}
struct node* BST_deletion(struct node* root, int val)
{
    if(root == NULL)         return NULL;
    
    if(val < root->data)         root->left = BST_deletion(root->left, val);
    else if(val > root->data)    root->right = BST_deletion(root->right, val);
    
    else
    {
        if(root->left == NULL || root->right == NULL)       //Leaf node
           {
               return NULL;
           }
          
        if(root->right == NULL)
        {
            root = root->left;
            return root;
        }
        
        if(root->left == NULL)
        {
            root = root->right;
            return root;
        }
        
        else
        {
            struct node* temp = inorder_successor(root->right);
            root->data = temp -> data; 
            root->right = BST_deletion(root->right, temp->data); 
            return root;
        }
    }
    return root;
}

int main()
{
    struct node *root;
    root = NULL;

    // root = InsertInTree(root, 10);
    // root = InsertInTree(root, 8);
    // root = InsertInTree(root, 15);
    // root = InsertInTree(root, 5);
    // root = InsertInTree(root, 20);
    // root = InsertInTree(root, 9);   
    // root = InsertInTree(root, 14);

    root = InsertInTree(root, 2);
    root = InsertInTree(root, 1);
    root = InsertInTree(root, 5); 
    root = InsertInTree(root, 4); 
    root = InsertInTree(root, 3);
  
    cout<<"\n\nElements in the tree array(Inorder Traverse) :\n";
    Inorder_Traverse(root);

    root = BST_deletion(root, 2);

    cout<<"\n\nElements after deletion(Inorder Traverse) :\n";
    Inorder_Traverse(root);
 
  

}
