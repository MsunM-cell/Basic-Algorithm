#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int u)
{
    if (y == n)
    {
        x++;
        y = 0;
    }
    if (x == n)
    {
        if (u == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;
    }
    
    // there is no queen
    dfs(x, y + 1, u);
    
    // there is a queen
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, u + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    
    dfs(0, 0, 0);
    
    return 0;
}