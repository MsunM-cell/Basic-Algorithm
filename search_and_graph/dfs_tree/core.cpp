#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = 0x3f3f3f3f;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;
    
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int t = e[i];
        if (!st[t])
        {
            int s = dfs(t);
            res = max(res, s);
            sum += s;
        }
    }
    
    res = max(res, n - sum);
    ans = min(ans, res);
    
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    dfs(1);
    printf("%d\n", ans);
    
    return 0;
}