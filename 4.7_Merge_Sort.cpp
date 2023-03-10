#include <iostream>
#include <vector>
using namespace std;
    void merge(vector<int>&v,int l,int mid,int r)
    {
        int n1=mid-l+1;   int n2=r-mid;
        vector<int>v1(n1), v2(n2);
        
        for(int i=0;i<n1;i++)   v1[i]=v[i+l];
        for(int i=0;i<n2;i++)   v2[i]=v[i+mid+1];
        
        int i=0,j=0,k=l;
        while(i<n1&&j<n2)
        {
            if(v1[i]<v2[j])
            {    v[k++]=v1[i++];   }
            else
            {   v[k++]=v2[j++];    }
        }
        while(i<n1)
        {    v[k++]=v1[i++]; }
        
        while(j<n2)
        {   v[k++]=v2[j++]; }
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