#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Swap(int Array[],int i,int j){
	int temp=Array[i];
	Array[i]=Array[j];
	Array[j]=temp;
}

int Remol_QuickSort(int Array[],int left,int right){
	int temp_number;
	int i=left-1;
	
	int rand_number=left+rand()%(right-left+1);
	
	Swap(Array,rand_number,right);
	
	temp_number=Array[right];
	
	for(int j=left;j<right;j++){
		if(Array[j]<=temp_number)
        {
            i=i+1;
            Swap(Array,i,j);
        }
	}
	
	Swap(Array,i+1,right);
	
	return (i+1);
} 

void RandQuickSort(int Array[],int left,int right){
	if(left<right){
		int Mid=Remol_QuickSort(Array,left,right);
		RandQuickSort(Array,left,Mid-1);
		RandQuickSort(Array,Mid+1,right);
	}
	return;
}

int main(){
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
	
	RandQuickSort(p, 0, Number-1);
	
	end_time=clock();
	
//	cout<<"ÅÅÐòºó"<<endl; 
//	for(int i=0;i<Number;++i){
//		cout<<p[i]<<" ";
//	}
	
	cout<<end_time-begin_time<<endl;
	return 0;
}
