// 2021-09-01

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

int main()
{
    init();
    
    int m, k, x;
    cin >> m;
    while (m--)
    {
        char c;
        cin >> c;
        switch(c)
        {
            case 'H':
                cin >> x;
                e[idx] = x;
                ne[idx] = head;
                head = idx++;
                break;
            case 'D':
                cin >> k;
                if (k == 0)
                    head = ne[head];
                else
                    ne[k - 1] = ne[ne[k - 1]];
                break;
            case 'I':
                cin >> k >> x;
                e[idx] = x;
                ne[idx] = ne[k - 1];
                ne[k - 1] = idx++;
        }
    }
    
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;
    
    return 0;
}