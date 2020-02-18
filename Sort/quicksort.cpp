#include <iostream>
#include <cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int a[], int p, int r)
{
    int i = p; 
    int j = r + 1; 
    int x = a[p]; 
    
    while(1){
    	 
        while(i<r && a[++i]<x);
        
		while(a[--j]>x);
        
        if(i>=j) break;
        
        swap(a,i,j);
    }
    swap(a,j,p);
    return j;
}


void QuickSort(int a[], int p, int right)
{
    if(p<right){
        int Mid = partition(a,p,right);
        QuickSort(a,p,Mid-1);
        QuickSort(a,Mid+1,right);
    }
}

int main()
{
	srand((unsigned)time(NULL));
    clock_t begin_time,end_time;
	
    int Number;
	cout<<"Place input a number of input_number:\t";
	cin>>Number;
	int* p=new int[Number];
	
	
	for(int i=0;i<Number;++i){
		p[i]=rand()%Number;
	}
	
//	cout<<"ÅÅÐòÇ°"<<endl; 
//	for(int i=0;i<Number;++i){
//		cout<<p[i]<<" ";
//	}
	//cout<<endl<<endl;
	
	begin_time=clock();
	
	QuickSort(p, 0, Number-1);
	
	end_time=clock();
	
//	cout<<"ÅÅÐòºó"<<endl; 
//	for(int i=0;i<Number;++i){
//		cout<<p[i]<<" ";
//	}
	
	cout<<end_time-begin_time<<endl;
	
    return 0;
}

