// 2021-09-03

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int n;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool query(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            insert(x);
        else
            if (query(x) == true)
                puts("Yes");
            else 
                puts("No");
    }
    return 0;
}