//Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.

#include<stdio.h>
int binarysearch(int arr[],int val,int n);
int main()
{
  int val;
  int arr[]={1,2,3,4,5,6,7,8};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("enter the valueto search : " );
  scanf("%d",&val);
  int result=binarysearch(arr,val,n);
  printf("%d\n",result);
  return 0;
}
int binarysearch(int arr[],int val,int n)
{
  int low=0;
  int high=n-1;
  while(low<high)
  {
    int mid=(low+high)/2;
    if(val>arr[mid])
    {
      low=mid+1;
    }
    else
    {
      high=mid;
    }
  }
  if(low<n && arr[low]==val)
  {
    return low;
  }
  else
  {
    return -1;
  }
}

