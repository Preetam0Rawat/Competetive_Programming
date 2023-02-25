// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v(6);       // Vector of vectors
//vector<int> v[6];                 // Array of vectors
vector<bool> vis(6, 0);
void make_graph(int s, int d)
{
    v[s].push_back(d);
    v[d].push_back(s);
}
void bfs(int val)
{
   queue<int> q;
   q.push(val);
   vis[val] = 1;
   while(!q.empty())
   {
       int node;
       node = q.front();  q.pop();
       cout<<node<<" ";
      vector <int> :: iterator it;
      for(it = v[node].begin(); it < v[node].end(); it++)
      {
        if(vis[*it] == 0)
          {
             q.push(*it);
             vis[*it] = 1;
          }
      }
    // Though preferable to use iterator
    // for(int i = 0; i< v[node].size(); i++)
    //   {
    //     if(vis[v[node][i]] == 0)
    //       {
    //          q.push(v[node][i]);
    //          vis[v[node][i]] = 1;
    //       }
    //   }
   }
}

int main() 
{
int n = 6,e = 6;

make_graph(0,5);
make_graph(0,2);
make_graph(5,4);
make_graph(5,1);
make_graph(2,3);
make_graph(4,1);
                    //          /0\
                    //      /5\       2\
                    //   4 ----  1       3
bfs(0);

}