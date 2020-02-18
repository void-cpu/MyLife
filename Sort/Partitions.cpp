#include <iostream>
#include <algorithm>
using namespace std;

void swap(int Array[],int i,int j){
	int temp=Array[i];
	Array[i]=Array[j];
	Array[j]=temp;
}

void Patitions(int Array[], int len,int number)
{
    int p = 0;
    int left = 0;
    int right = len-1;

    while(p<=right){
        if(Array[p]<number){
            swap(Array[p],Array[left]);
            p++;
        }
        else if(Array[p]>number){
            swap(Array[p],Array[right]);
            right--;
        }
        else{
            p++;  //Ìî¿ÕÎ»ÖÃ
        }
    }
}
int main()
{
    int array[7]={-2,3,4,5,6,-7,-8};
    int len=sizeof(array)/sizeof(array[0]);
    int number;
    cout<<"input a number of inputnumber:\t";
    cin>>number;
    Patitions(array,len,number);
    for(int i=0;i<len;i++)
    	cout<<array[i]<<"\t";
    return 0;
}

