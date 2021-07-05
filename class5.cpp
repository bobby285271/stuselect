#include <bits/stdc++.h>
using namespace std;

string a[] = {"", "王玮璟", "黄贝苗", "吴凡", "李志文", "黄彬源"};

int p[30];
int s[10];

int main()
{

    cout << "### 大作业评分" << endl << endl;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= 27; i++)
    {
        p[i] = i;
        std::swap(p[i], p[rand() % i + 1]);
    }
    for (int i = 1; i <= 5; i++)
    {
        s[i] = i;
        std::swap(s[i], s[rand() % i + 1]);
    }
    int t = 1;
    for (int i = 1; i <= 2; i++)
    {
        cout << a[s[i]] << endl;
        for (int j = 0; j < 6; j++)
        {
            cout << p[t] << ' ';
            t++;
        }
        cout << endl
             << endl;
    }
    for (int i = 3; i <= 5; i++)
    {
        cout << a[s[i]] << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << p[t] << ' ';
            t++;
        }
        cout << endl
             << endl;
    }
}
