#include <iostream>
#include <vector>
using namespace std;
    void merge(vector<int>&v,int low,int mid,int high)
    {
        vector<int> B(high-low+1);
        
        int i = low, j = mid+1, k=0;
        while(i<=mid &&j<=high)
        {
            if(v[i]<v[j])
            {    B[k++]=v[i++];   }
            else
            {   B[k++]=v[j++];    }
        }
        while(i<=mid)
        {    B[k++]=v[i++]; }
        
        while(j<=high)
        {   B[k++]=v[j++]; }

        for(int i = low, k = 0; i <= high; i++,k++)
        {   v[i] = B[k]; }              
    }

    void mergeSort(vector<int>&v, int low, int high)
    {
        if(low < high)
        {
            int mid=low + (high - low)/2;
            mergeSort(v,low,mid);
            mergeSort(v,mid+1,high);
            merge(v,low,mid,high);
        }
    }
    

int main()
{
   vector<int> nums = {9, 8, 7, 6, 5, 4};
   int n = nums.size();
   mergeSort(nums, 0, n-1);
  
   cout<<"After sorting :\n";
   for(auto i: nums)
     cout<<i<<" ";
}





//--------------------ALternate Easy merge function but takes too much space and time, not ideal for competitive programming-------------------------//

//void merge(vector<int> &A, int low, int mid, int high)
// {
//   int i, j, k, B[100];
//   i = low; j = mid+1; k = low;

//   while((i <= mid) && (j <=high))
//   {
//     if(A[i] < A[j])
//     {
//       B[k] = A[i];
//       i++; k++;
//     }
//     else
//     if(A[j] < A[i])
//     {
//       B[k] = A[j];
//       j++; k++;
//     }
//   }

//   while(i <= mid)
//   {
//     B[k] = A[i];
//     i++; k++;
//   } 
  
//   while(j <= high)
//   {
//     B[k] = A[j];
//     j++; k++;
//   }

//   for(int i = low; i<=high; i++)
//   {
//     A[i] = B[i];
//   }
// }
