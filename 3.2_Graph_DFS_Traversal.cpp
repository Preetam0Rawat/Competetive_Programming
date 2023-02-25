// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
//vector<vector<int>> v(6);       // Vector of vectors
vector<int> v[6];                 // Array of vectors
vector<bool> vis(6, 0);
void make_graph(int s, int d)
{
    v[s].push_back(d);
    v[d].push_back(s);
}
void dfs(int val)
{
   vis[val]= 1;
   cout<<val<<" ";
   
        //   for(int j = 0; j < v[val].size(); j++)
        //   {
        //       if(  vis[v[val][j]] == 0 )
        //       {
        //           dfs(v[val][j]);
        //       }
        //   }

vector<int> :: iterator it;
for(it = v[val].begin(); it < v[val].end(); it++)
{
  if(vis[*it] == 0)
  {
      dfs(*it);
  }
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
dfs(0);

}