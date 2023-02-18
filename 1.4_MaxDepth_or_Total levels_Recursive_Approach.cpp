//Recursuve method to find maxumin depth of tree or levels of a tree
//Recursion uses DFS approach
#include <iostream>
#include <algorithm>
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
int recursive_Depth(struct node* root)
{
   if(root == NULL)
      return 0;
   int maxLeft = recursive_Depth(root->left);
   int maxRight = recursive_Depth(root->right);
     return max(maxLeft, maxRight) + 1;
}

int main() 
{
    int d;
    struct node *root ;
    root = NULL;
    root = tree(root, 1);
       
    struct node *child1 = new struct node;    child1->data = 2;
    struct node *child2 = new struct node;    child2->data = 3;
    struct node *child3 = new struct node;    child3->data = 4;
    struct node *child4 = new struct node;    child4->data = 5;

    root->left = child1;
    root->right = child2;
    child1->left = child3;
    child1->right = child4;
    
                 //                     1
                 //                  2       3
                 //              4      5      
    d = recursive_Depth(root) - 1;
    cout<<"Maximum Depth of the tree is: "<<d;
    cout<<"\nTotal levels are: "<<d+1;
    return 0;
}
