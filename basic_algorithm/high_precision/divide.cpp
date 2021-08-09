// 2020-08-09

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r;

vector<int> divide(vector<int> &A, int &b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = t * 10 + A[i];
        C.push_back(t / b);
        t %= b;
    }

    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    r = t;
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = 0; i < a.size(); i++)
        A.push_back(a[i] - '0');
    
    auto C = divide(A, b);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl << r;

    return 0;
}