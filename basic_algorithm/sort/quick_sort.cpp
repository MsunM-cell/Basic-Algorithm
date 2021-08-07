// 2021-08-07
// pay attention to boundary problem

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    
    // look for the cut-off point
    int x = q[(l + r + 1) / 2], i = l - 1, j = r + 1;
    // adjust the interval
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    // recursive processing
    quick_sort(q, l, i - 1);
    quick_sort(q, i, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    
    return 0;
}

