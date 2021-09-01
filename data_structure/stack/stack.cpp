// 2021-09-01

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;

int main(void)
{
    int m;
    cin >> m;

    while (m--)
    {
        string op;
        cin >> op;

        int x;

        if (op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if (op == "pop")
        {
            tt--;
        }
        else if (op == "empty")
        {
            if (tt > 0)
                puts("NO");
            else
                puts("YES");
        }
        else
        {
            printf("%d\n", stk[tt]);
        }
    }

    return 0;
}