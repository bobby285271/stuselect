#include <iostream>
#include <algorithm>

using namespace std;

struct class5
{
    int n, m;
};

bool cmp(class5 a, class5 b)
{
    return a.m > b.m;
}

int main()
{

    class5 a[15];
    srand((unsigned)time(NULL));
    for (int i = 1; i < 13; i++)
    {
        a[i].m = rand();
        a[i].n = i;
    }
    sort(a + 1, a + 13, cmp);
    cout << endl << "### 计算机基础实验演讲顺序" << endl;
    cout << "抽取结果：" << " ";
    for (int i = 1; i < 13; i++)
        cout << a[i].n << " ";
    cout << endl;
    return 0;
}
