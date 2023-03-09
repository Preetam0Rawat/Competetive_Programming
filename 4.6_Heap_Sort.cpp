/* 
		There are two types of heaps
		1. MAX heap - This is used to sort in ascending order 
		2. MIN heap - This is used in descending order  	
*/

//------------------------USING MAX HEAP TO SORT IN ASCENDING ORDER-------------------------//

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &nums, int n, int i)
{
  int left = 2*i+1,  right = 2*i+2,  largest = i;
  
  if(left < n && nums[largest] < nums[left])    largest = left;

  if(right <n && nums[largest] < nums[right])   largest = right;
  
  if(largest != i)
  {
      swap(nums[i], nums[largest]);
      heapify(nums, n, largest);      //This will go down the heap-tree
  }
}


void heapSort(vector<int> &nums, int n)
{
    // First create the heap(max or min) of given array   Here creating a MAX HEAP
    for(int i = (n/2)-1; i >= 0; i--)   //We will start with the last non-leaf node then move up.  
    {
        heapify(nums, n , i);
    }
    for(int i = n-1; i > 0; i--)        //Sorting begins
    {
        swap(nums[0], nums[i]);         //Putting largest element at the end of array
        heapify(nums, i, 0);            //Heapifying remaining array
    }
}
int main()
{
    vector<int> nums = {6, 5, 4, 7 , 9};
    int n = nums.size();
    
    heapSort(nums, n);
    
    cout<<"After sorting : \n";
    for(auto i : nums)
      cout<<i<<" ";
}