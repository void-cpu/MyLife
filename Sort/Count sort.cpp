#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
const int MAXN = 1000;
int data[MAXN];
int tmp[MAXN];
int count[MAXN];      //计数数组
 
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
    函数说明：实现基数排序
    参数说明：
        data：数据数组
        n：data数组的最高位
    **/
    int d = maxbit(data,n);  //得到数组中最高的位数
    int radix = 1;
    for(int i  =0 ;i < d;i ++)  //进行d次排序
    {
        for(int j =0 ;j < 10;j ++)   // 首先进行清桶的操作
            count[j] = 0;
        for(int j =0 ;j < n;j ++)
        {
            int k = (data[j] / radix) % 10;  //统计每个桶中含有数字的数量
            count[k] ++;
        }
        for(int j =1 ;j < 10;j ++)
            count[j] += count[j-1];   //将tmp中的位置依次分配给每个桶,意思就是为每个桶里面还有的数量都留下够用的空间
            //这里想不明白可以理解为相邻两个数位之间的差表示的就是给这个桶分配的空间；
        for(int j = n - 1; j >= 0;j --)//将桶中的记录依次收集到tmp中
        {
            int k = (data[j] / radix) % 10;          //得到他在哪一个桶里面
            tmp[count[k] - 1 ]  = data[j];           //因为上面已经给这个桶留下了相应的空间，所以只需要一次向后减1，就可以排到适当的位置
            count[k] -- ;
        }
        for(int j = 0;j < n;j ++)    //将临时数组的内容复制到data数组中
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

