#include <iostream>
#include <vector>
using namespace std;
    int partition(vector<int> &nums,int low,int high)
    {
       int pivot = low,  i = low, j = high;
       
      while(i < j)
      {
            while(i < j && nums[i] <= nums[pivot])  i++;   // i<j BECAUSE LEETCODE WAS GIVING HEAP BUFFER OVERFLOW WITHOUT IT. WORKS FINE WITHOUT IT TOO ;)
            while(nums[j] > nums[pivot])   j--;
            
            if(i < j)  
                swap(nums[i], nums[j]);

           }
       
       swap(nums[pivot], nums[j]);
       return j;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        if(low < high)
        {
            int pi = partition(nums, low, high);
            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }
    }
    

int main()
{
   vector<int> nums = {9, 5, 7, 6, 5, 4};
   int n = nums.size();
   quickSort(nums, 0, n-1);
  
   cout<<"After sorting :\n";
   for(auto i: nums)
     cout<<i<<" ";
}


