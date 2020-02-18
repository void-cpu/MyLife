#include<iostream>
using namespace std;

void swap(int Array[],int i,int j){
	int temp=Array[i];
	Array[i]=Array[j];
	Array[j]=temp;
}

void InsertionSort(int Array[],int lenght){
	if (lenght<2){
		return ;
	}else{
		for(int i=1;i<lenght;i++){
			for(int j=i-1; j>=0 && Array[j]<Array[j+1];j--){
				swap(Array,j,j+1);
			}
		}
	}
}

int main(){
	int Array[]={12,34,1,5};
	int lenght=sizeof(Array)/sizeof(int);
	InsertionSort(Array,lenght);
	for(int i=0;i<4;i++){
		printf("%d\t",Array[i]);
	}
}
