#include <iostream>
using namespace std;

int merge(int a[], int b[], int l, int m, int r)
{
	int Sum=0;
    int i = l;
    int j = m + 1;
    int k = l;
    
    while (k <= r) {
        if (i > m) {
            b[k++] = a[j++];
        }
        else if (j > r) {
            b[k++] = a[i++];
        }
        else {
            if (a[i] > a[j]) {
                b[k++] = a[j++];
            }
            else {
            	Sum+=a[i]*(r-j+1);
                b[k++] = a[i++];
            }
        }
    }

    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
    return Sum;
}

int merge_sort_helper(int a[], int b[], int l, int r)
{
    if (l >= r) {
        return 0;
    }
    int m =(l + r)/2;
    return merge_sort_helper(a, b, l, m)+merge_sort_helper(a, b, m + 1, r)+merge(a, b, l, m, r);
}

int merge_sort(int a[], int len)
{
    int *b = new int[len];
    int Liltlesum=merge_sort_helper(a, b, 0, len - 1);
    delete[] b;
    return Liltlesum;
}

int main()
{
    int a[] = {1,3,4,2,5};
    cout<<merge_sort(a, sizeof(a)/sizeof(a[0]));
    return 0;
}

