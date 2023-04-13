#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

vector<string> group9 = {"陈佳浚", "陈晓琪", "樊曦阳", "雷昊禧", "吴凡", "潘国俊", "罗仕鑫", "李志文", "容加林", "蒋泽明", "刘坚豪", "李玮楠", "黄俊", "旷恒毅", "蔡卓琳", "王文威", "商汇川", "黄树华", "王玮璟", "谢嘉欢", "香南斌", "陈锦川", "曾宇璐", "陈隽淇"};
vector<string> group10 = {"陈诗伟", "邓思阳", "林芷泳", "胡瀚文", "李志成", "丁汉基", "徐旗", "陈家豪", /*"何泳良",*/ "王凯峰", "陈芷茵", "林晓东", "张信宇", "梁滔", "谭恩泽", "王明生", "马家豪", "郭一梵", "陈佳茵", "沈德增", "谢城", "杨泽祺", "王仁杰", "黄彬源"};

vector<pair<long long, string>> group9_rnk, group10_rnk;

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);

    cout << rand_num();

    for (auto i : group9)
    {
        group9_rnk.push_back(make_pair(rand_num(), i));
    }
    for (auto i : group10)
    {
        group10_rnk.push_back(make_pair(rand_num(), i));
    }
    sort(group9_rnk.begin(), group9_rnk.end());
    sort(group10_rnk.begin(), group10_rnk.end());
    cout << "\n### 毕设答辩助理 - 抽签\n"
         << "\n第九组 " << group9_rnk[0].second
         << "\n第十组 " << group10_rnk[0].second
         << "\n";
}
