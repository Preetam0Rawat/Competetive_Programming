//This traversal method if BFS also lnown as Level Order Traversal
//It uses queue DS
#include <iostream>
#include <queue>
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
void bfs(struct node *root)
{
  queue<struct node*> q;
  int level = 0, count;
  q.push(root);
   while(!q.empty())
   {
       count = q.size();
       while(count != 0)
       {   struct node* temp = q.front();
           cout<<temp->data<<"  ";
           if(temp->left)  q.push(temp->left);
           if(temp->right) q.push(temp->right);
           q.pop();
           count--;
       }
       level++;
   }
   cout<<"\nLevel of the tree is: "<<level;
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
    
    bfs(root);
    return 0;
}
