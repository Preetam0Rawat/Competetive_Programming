// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v(6);           // Vector of vectors
//vector<int> v[6];                 // Array of vectors
void make_graph(int s, int d)
{
    v[s].push_back(d);
    v[d].push_back(s);
}

int main() 
{
    int n , e;
    int s, d;
    cout<<"Enter number of node and edges:\n";
    cin>>n >> e;
    
    for(int i = 0 ; i< e ; i++)
    {
        cout<<"Ener source and destination;\n";
        cin>>s>>d;
        make_graph(s,d);
        
    }

// make_graph(0,5);
// make_graph(0,2);
// make_graph(5,4);
// make_graph(5,1);
// make_graph(2,3);
// make_graph(4,1);
                    //          /0\
                    //      /5\       2\
                    //   4 ----  1       3
                    
}