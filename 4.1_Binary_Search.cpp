// Binary Search
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Iterative Approach         TC = O(log(n))   SC = O(1) 
int binarySearchIterative(vector<int> &v, int f, int l, int val)
{
    int mid;
    while(f <= l)
    {
        mid = (f+l)/2;
        if(val == v[mid])
            return mid;
        if(val < v[mid])
            l = mid-1;
        else
            f= mid+1;
    }
    return -1;
}

//Recursive Approach         TC = O(log(n))   SC = O(log(n))

int binarySearchRecursive(vector<int> &v, int f, int l, int val)
{
     if( f == l)
      {
        if(val == v[f])
         return f;
        else
         return -1;
      }     
        
     else
     {  
        int mid = (f+l)/2;
        if(val == v[mid])
            return mid;
        if(val < v[mid])
            return binarySearchRecursive(v, f, mid-1, val);
        else
            return binarySearchRecursive(v, mid+1, l, val);
     }
         
    }

int main()
{
     vector<int> v =  {2, 1, 4 ,8 ,6 ,4 ,9};
     int n = v.size();
     int val = 9;
     int res;
     sort(v.begin(), v.end());//First sorting is required
    
     //res = binarySearchIterative(v, 0, n-1, val);
     res = binarySearchRecursive(v, 0, n-1, val);

     if(res != -1)
     {
         cout<<"Element found at index :"<<res;
     }
     else
     {
         cout<<"Element not found";
     }
}