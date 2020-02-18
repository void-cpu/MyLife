#include <iostream>
#include<stdlib.h>
#include<time.h>

#define NUMBER 45
using namespace std;

//��������
void exchange(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//p��ʾ������A�������ʼ�±꣬r�ǽ����±�
int random_patition(int *A,int p,int r)
{
    int temp;
    int i=p-1;

    //������������±�
    int k= p + rand()%(r -p +1);

    //��Ȼ����������ύ�������
    exchange(A[r],A[k]);
    temp=A[r];
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=temp)//��֤��ߵ�ֵ��Զ��tempС 
        {
        	//����Ǳȵ�i��󣬺ã�ȥ����ֵ�������ݱ�֤����벿��һ������˳��ģ�������ȴû�� 
            i=i+1;
            exchange(A[i],A[j]);
        }
    }

    //�����Ԫ��������Ϊ���������������ݶ������ˣ����ǵ�i+���ĩβ��Ӧ��λ�����෴�ģ���������һ�Ϊ����� 
    exchange(A[i+1],A[r]);

    return i+1;
}

//�ݹ����
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

