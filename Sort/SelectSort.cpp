#include<iostream>
using namespace std;

void swap(int Array[],int i,int j){
	int temp=Array[i];
	Array[i]=Array[j];
	Array[j]=temp;
}

void SelectSort(int Array[],int lenght){
	if (lenght<2){
		return ;
	}else{
		for(int i=0;i<lenght-1;i++){
			for(int j=i+1;j<lenght;j++){
				if(Array[i]<Array[j]){
					swap(Array,i,j);
				}
			}
		}
	}
}

int main(){
	int Array[]={12,34,1,5};
	int lenght=sizeof(Array)/sizeof(int);
	SelectSort(Array,lenght);
	for(int i=0;i<4;i++){
		printf("%d\t",Array[i]);
	}
}
