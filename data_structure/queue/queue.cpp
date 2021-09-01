// 2021-09-01

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m, x;
int q[N], hh, tt = -1;

int main()
{
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[++tt] = x;
        }
        else if (op == "pop")
            hh++;
        else if (op == "empty")
        {
            if (hh <= tt)
                puts("NO");
            else
                puts("YES");
        }
        else
            cout << q[hh] << endl;
    }
    return 0;
}