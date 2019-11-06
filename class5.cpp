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

    class5 a[12];
    srand((unsigned)time(NULL));
    for (int i = 1; i < 12; i++)
    {
        a[i].m = rand();
        a[i].n = i;
    }
    a[2].m = a[3].m - 1;    //第二组演讲过了。
    a[1].m = a[2].m;        //第一组演讲过了。
    a[10].m = a[2].m;       //第十组演讲过了。
    sort(a + 1, a + 12, cmp);
    //for (int i = 1; i < 11; i++)
    cout << endl << "### 测试" << endl;
    cout << "抽取结果：" << a[1].n << " ";
    cout << endl;
    return 0;
}
