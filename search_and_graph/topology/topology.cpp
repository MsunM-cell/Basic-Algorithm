#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool toposort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    
    return tt == n - 1;
}

int main()
{
    memset(h, -1, sizeof h);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    
    if (toposort())
    {
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
        puts("");
    }
    else
        puts("-1");
        
    return 0;
}