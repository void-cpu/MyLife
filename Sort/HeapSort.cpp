#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
 
void adjust(int arr[], int len, int index)
{
    int left = 2*index + 1; 
    int right = 2*index + 2;
 
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;
 
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}

void heapSort(int arr[], int size)
{
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           
        adjust(arr, i, 0);              
    }
}
 
int main(void)
{
	int NUMBER; 
	cin>>NUMBER;
    int *p;
    p=new int[NUMBER];
    
	for(int k=0;k<NUMBER;k++)
    {
        p[k]=rand()%NUMBER;
    }
    
    cout<<endl;
    cout<<endl;
	heapSort(p,NUMBER);
    for(int i=0;i<NUMBER;i++)
    {
      cout<<p[i]<<" ";
    }
	return 0;
}

