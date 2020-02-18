#include <iostream>
using namespace std;

void merge(int a[], int b[], int l, int m, int r)
{
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
                b[k++] = a[i++];
            }
        }
    }

    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
}

void merge_sort_helper(int a[], int b[], int l, int r)
{
    if (l >= r) {
        return;
    }
    int m = (l + r)/2;
    merge_sort_helper(a, b, l, m);
    merge_sort_helper(a, b, m + 1, r);
    merge(a, b, l, m, r);
}

void merge_sort(int a[], int len)
{
    int *b = new int[len];
    merge_sort_helper(a, b, 0, len - 1);
    delete[] b;
}

int main()
{
    int a[] = {1, 1, 6, 6, 8, 3, 5, 100, 300, 200, 99, 99};
    merge_sort(a, sizeof(a)/sizeof(a[0]));
    
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    	cout<<a[i]<<" ";
	}
    
    return 0;
}

