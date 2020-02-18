#include <iostream>
#include<stdlib.h>
#include<time.h>

#define NUMBER 45
using namespace std;

//两数交换
void exchange(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//p表示将数组A排序的起始下标，r是结束下标
int random_patition(int *A,int p,int r)
{
    int temp;
    int i=p-1;

    //产生随机数组下标
    int k= p + rand()%(r -p +1);

    //仍然将随机的枢轴交换到最后
    exchange(A[r],A[k]);
    temp=A[r];
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=temp)//保证左边的值永远比temp小 
        {
        	//如果是比第i项大，好，去交换值，这样据保证了左半部分一定是有顺序的，而右面却没有 
            i=i+1;
            exchange(A[i],A[j]);
        }
    }

    //最后主元交换，因为当结束后所有数据都有序了，但是第i+项和末尾项应该位置是相反的，及最后的那一项即为所求项。 
    exchange(A[i+1],A[r]);

    return i+1;
}

//递归调用
void QuickSort(int *A,int p,int q)
{
    if(p<q){
        int r = random_patition(A, p, q);
        QuickSort(A, p, r-1);
        QuickSort(A, r+1, q);
    }

}

int main(void)
{
    int *p;
    p=new int[NUMBER];
    
	for(int k=0;k<NUMBER;k++)
    {
        p[k]=rand()%NUMBER;
    }
    
    cout<<endl;
    cout<<endl;
    QuickSort(p,0,NUMBER-1);
    for(int i=0;i<NUMBER;i++)
    {
      cout<<p[i]<<" ";
    }
    //cout<<endl<<endl<<end_time-begin_time<<" ms"<<endl;
	return 0;
}

