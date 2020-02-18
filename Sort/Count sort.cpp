#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
const int MAXN = 1000;
int data[MAXN];
int tmp[MAXN];
int count[MAXN];      //��������
 
int maxbit(int data[], int n)
{
    int max_num = 1;
    int num = 10;
    for(int i = 0;i < n;i ++)
    {
        while(data[i] >= num)
        {
            num *= 10;
            max_num ++;
        }
    }
    return max_num;
}
 
void RadixSort(int data[], int n)
{
    /**
    ����˵����ʵ�ֻ�������
    ����˵����
        data����������
        n��data��������λ
    **/
    int d = maxbit(data,n);  //�õ���������ߵ�λ��
    int radix = 1;
    for(int i  =0 ;i < d;i ++)  //����d������
    {
        for(int j =0 ;j < 10;j ++)   // ���Ƚ�����Ͱ�Ĳ���
            count[j] = 0;
        for(int j =0 ;j < n;j ++)
        {
            int k = (data[j] / radix) % 10;  //ͳ��ÿ��Ͱ�к������ֵ�����
            count[k] ++;
        }
        for(int j =1 ;j < 10;j ++)
            count[j] += count[j-1];   //��tmp�е�λ�����η����ÿ��Ͱ,��˼����Ϊÿ��Ͱ���滹�е����������¹��õĿռ�
            //�����벻���׿������Ϊ����������λ֮��Ĳ��ʾ�ľ��Ǹ����Ͱ����Ŀռ䣻
        for(int j = n - 1; j >= 0;j --)//��Ͱ�еļ�¼�����ռ���tmp��
        {
            int k = (data[j] / radix) % 10;          //�õ�������һ��Ͱ����
            tmp[count[k] - 1 ]  = data[j];           //��Ϊ�����Ѿ������Ͱ��������Ӧ�Ŀռ䣬����ֻ��Ҫһ������1���Ϳ����ŵ��ʵ���λ��
            count[k] -- ;
        }
        for(int j = 0;j < n;j ++)    //����ʱ��������ݸ��Ƶ�data������
        {
            data[j] = tmp[j];
        }
        radix *= 10;
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i =0 ;i < n;i ++)
        scanf("%d",&data[i]);
    RadixSort(data,n);
    for(int i =0 ;i < n;i ++)
        printf("%d%c",data[i],i==n-1?'\n':' ');
    return 0;
}

