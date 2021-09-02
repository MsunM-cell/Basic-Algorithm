// 2021-09-02

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], cnt;

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[t] > h[u * 2])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1])
        t = u * 2 + 1;

    if (t != u)
    {
        swap(h[t], h[u]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    cnt = n;

    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[cnt--];
        down(1);
    }
}