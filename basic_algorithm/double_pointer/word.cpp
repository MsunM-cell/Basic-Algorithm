// 2021-08-29

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char str[100];
    cin.getline(str, 100);

    int n = strlen(str);
    for (int i = 0, j = 0; i < n; i++)
    {
        j = i;
        while (j < n && str[j] != ' ')
            j++;
        for (int k = i; k < j; k++)
            cout << str[k];
        cout << endl;
        i = j;
    }

    return 0;
}