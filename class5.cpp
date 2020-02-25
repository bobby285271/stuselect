#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define IO ios::sync_with_stdio(0)
#define DEBUG(x) cout << "--->" << (x) << endl;
typedef pair<int, int> P;
const int maxn = 2e4 + 5;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
using namespace std;

int main()
{
    IO;

    for (int c__ = 10000; c__ > 0; c__--)
    {
        for (int b__ = c__; b__ > 0; b__--)
        {
            for (int a__ = b__; a__ > 0; a__--)
            {
                cout << c__ << " " << b__ << " " << a__ << endl;
                int ans__ = 1e9;
                int A__ = -1, B__ = -1, C__ = -1;
                for (int cA__ = 1; cA__ <= 2 * a__; ++cA__)
                {
                    for (int cB__ = cA__; cB__ <= 2 * b__; cB__ += cA__)
                    {
                        for (int i__ = 0; i__ < 2; ++i__)
                        {
                            int cC__ = cB__ * (c__ / cB__) + i__ * cB__;
                            int res__ = abs(cA__ - a__) + abs(cB__ - b__) + abs(cC__ - c__);
                            if (ans__ > res__)
                            {
                                ans__ = res__;
                                A__ = cA__;
                                B__ = cB__;
                                C__ = cC__;
                            }
                        }
                    }
                }

                int a, b, c;
                a = a__;
                b = b__;
                c = c__;
                int cnt = inf;
                int aa = a, bb = b, cc = c;
                for (int i = 1; i <= maxn; i++)
                {
                    int tmp = abs(b - i);
                    int t1 = inf;
                    int tempa;
                    for (int j = 1; j * j <= i; j++)
                    {
                        if (i % j == 0)
                        {
                            if (t1 > abs(j - a))
                            {
                                t1 = abs(j - a);
                                tempa = j;
                            }
                            if (t1 > abs(i / j - a))
                            {
                                t1 = abs(i / j - a);
                                tempa = i / j;
                            }
                        }
                    }
                    int t2 = min(abs(c / i * i - c), abs((c / i + 1) * i - c));
                    tmp += t1 + t2;
                    int tempc;
                    if (abs(c / i * i - c) < abs((c / i + 1) * i - c))
                        tempc = c / i * i;
                    else
                        tempc = (c / i + 1) * i;
                    if (cnt > tmp)
                    {
                        cnt = tmp;
                        aa = tempa;
                        bb = i;
                        cc = tempc;
                    }
                }
                if (cnt != ans__)
                {
                    cout << a__ << " " << b__ << " " << c__ << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}
