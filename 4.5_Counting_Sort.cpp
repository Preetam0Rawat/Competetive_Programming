#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &A, int n)
{
    //int max_val = max(*A.begin(), *A.end());  
      int max_val = max(A[0], A[n-1]);  
      vector<int> count(max_val, 0);
      
      for(auto i: A)
      {
          count[i] = count[i] + 1;
      }
      int i = 0, j = 0;
      
      while(i <= max_val)
      {
          if(count[i] > 0)
          {
              A[j] = i;
              count[i] = count[i] -1 ;
              j++;
          }
          else
          {
              i++;
          }
      }
}

int main()
{
    vector <int> nums = {5 , 4, 3, 2, 1, 0};
    int n = nums.size();
    
    countingSort(nums, n);
    
    cout<<"After sorting :\n";
    for(auto i: nums)
      cout<<i<<" ";
}