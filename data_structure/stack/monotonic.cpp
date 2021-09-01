// 2021-09-01

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;

int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        while (tt && stk[tt] >= x)
            tt--;
        if (tt == 0)
            cout << "-1" << " ";
        else
            cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    return 0;
}