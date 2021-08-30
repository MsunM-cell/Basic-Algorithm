// 2021-08-29

#include <iostream>

using namespace std;

int n, x;

int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    cin >> n;
    while (n--)
    {
        int res = 0;
        cin >> x;
        while (x)
        {
            x -= lowbit(x);
            res++;
        }
        cout << res << ' ';
    }
    return 0;
}