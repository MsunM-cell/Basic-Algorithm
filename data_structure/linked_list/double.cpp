// 2021-09-01

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m, k, x;
int e[N], l[N], r[N], idx;

void init()
{
    r[0] = 1, l[1] = 0, idx = 2;
}

void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k)
{
    r[l[k + 1]] = r[k + 1];
    l[r[k + 1]] = l[k + 1];
}

int main()
{
    init();

    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if (op == "IR")
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    cout << endl;

    return 0;
}