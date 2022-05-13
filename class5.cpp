#include <iostream>
#include <algorithm>

using namespace std;

struct class5
{
    int m;
    string n;
    bool disabled;
};

bool cmp(class5 a, class5 b)
{
    return a.m > b.m;
}

int main()
{

    class5 a[60];
    srand((unsigned)time(NULL));
    for (int i = 1; i < 60; i++)
    {
        a[i].m = rand();
    }
    a[1].n = "李玮楠";
    a[2].n = "胡瀚文";
    a[3].n = "邓思阳"; a[3].disabled = true;
    a[4].n = "王佳业";
    a[5].n = "蔡卓琳"; a[5].disabled = true;
    a[6].n = "郭一梵";
    a[7].n = "杨泽祺";
    a[8].n = "梁滔";
    a[9].n = "赖艳鹏";
    a[10].n = "黄彬源";
    a[11].n = "谢嘉欢";
    a[12].n = "林晓东";
    a[13].n = "雷昊禧";
    a[14].n = "樊曦阳";
    a[15].n = "马家豪";
    a[16].n = "刘坚豪";
    a[17].n = "王文威";
    a[18].n = "吴中其";
    a[19].n = "谢城";
    a[20].n = "何泳良";
    a[21].n = "黄贝苗";
    a[22].n = "黄俊"; a[22].disabled = true;
    a[23].n = "商汇川";
    a[24].n = "陈佳浚";
    a[55].n = "张信宇";
    a[26].n = "曾宇璐";
    a[27].n = "旷恒毅";
    a[28].n = "李晓芳";
    a[29].n = "陈隽淇"; a[29].disabled = true;
    a[30].n = "吴凡";
    a[31].n = "丁汉基";
    a[32].n = "陈晓琪";
    a[33].n = "香南斌";
    a[34].n = "沈德增";
    a[35].n = "徐旗"; a[35].disabled = true;
    a[36].n = "林芷泳";
    a[37].n = "李志成";
    a[38].n = "王仁杰"; a[38].disabled = true;
    a[39].n = "李志文"; a[39].disabled = true;
    a[40].n = "王玮璟";
    a[41].n = "谭恩泽"; a[41].disabled = true;
    a[42].n = "潘国俊";
    a[43].n = "李晓钰";
    a[44].n = "陈佳茵";
    a[45].n = "罗仕鑫";
    a[46].n = "蒋泽明";
    a[47].n = "邓子曼";
    a[48].n = "陈芷茵";
    a[49].n = "王凯峰";
    a[50].n = "黄树华";
    a[51].n = "王明生";
    a[52].n = "容加林"; a[52].disabled = true;
    a[53].n = "陈家豪";
    a[54].n = "陈诗伟";
    a[55].n = "陈锦川"; a[55].disabled = true;
    
    sort(a + 1, a + 56, cmp);
    cout << endl << "### 本轮抽签仅用于调试" << endl;
    cout << "抽取结果：" << " ";
    int cnt = 0;
    for (int i = 1; i <= 55; i++) {
        if (a[i].disabled == false) {
            cout << a[i].n << " ";
            cnt++;
            if (cnt == 30) break;
        }
    cout << endl;
    return 0;
}
