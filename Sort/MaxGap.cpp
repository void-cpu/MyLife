#include<iostream>
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

//求出每一个数所在的桶的编号
int bocketNum(int a[], int i, int min, int max, int len){
	return (a[i]-min) * len / (max-min);
}
int Min(int a, int b){
	return a <= b ? a : b;
}
int Max(int a, int b){
	return a >= b ? a : b;
}

int maxGap(int A[], int n)
{
	int min = A[0];
	int max = A[0];
	
	//找出最大值和最小值
	for(int i = 1; i < n; ++i){
		min = (min <= A[i] ? min : A[i]);
		max = (max >= A[i] ? max : A[i]);
	}
	
	int* minArr = new int[n+1]();//记录每个桶中的最小数
	int* maxArr = new int[n+1]();//记录每个桶中的最大数
	bool hasNum[n+1] = {0};//记录桶中是否有数
	
	for(int i = 0; i < n; ++i){
		//求出每一个数所在的桶的编号
		int bocketID = bocketNum(A, i, min, max, n);
		minArr[bocketID] = hasNum[bocketID] ? Min(minArr[bocketID], A[i]) : A[i];
		maxArr[bocketID] = hasNum[bocketID] ? Max(maxArr[bocketID], A[i]) : A[i];
		hasNum[bocketID] = true;
	}
	
	int MaxGap = 0;//记录最大差值
	int LastMax = 0;//记录当前空桶的上一个桶的最大值
	
	int i = 0;
	while(i < n + 1){	//可能会有多个空桶
		//遍历桶，找到一个空桶
		while(i < n + 1 && hasNum[i])
			i++;
		if(i == n + 1)
			break;
		LastMax = maxArr[i-1];
		//继续遍历桶，找到下一个非空桶
		while(i < n + 1 && !hasNum[i])
			i++;
		if(i == n + 1)
			break;
		MaxGap = Max(MaxGap, minArr[i]-LastMax);
	}
	delete []minArr;
	delete []maxArr;
	
	return MaxGap;
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
    
    for(int i=0;i<NUMBER;i++)
    {
      cout<<p[i]<<" ";
    }
    cout<<endl;
    
	cout<<maxGap(p,NUMBER)<<endl<<endl;
	
	heapSort(p,NUMBER);
    for(int i=0;i<NUMBER;i++)
    {
      cout<<p[i]<<" ";
    }
	return 0;
}

