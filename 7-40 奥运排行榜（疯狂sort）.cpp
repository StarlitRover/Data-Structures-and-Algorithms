/*7-40 奥运排行榜 (25 分)
每年奥运会各大媒体都会公布一个排行榜，但是细心的读者发现，不同国家的排行榜略有不同。比如中国金牌总数列第一的时候，中国媒体就公布“金牌榜”；而美国的奖牌总数第一，于是美国媒体就公布“奖牌榜”。如果人口少的国家公布一个“国民人均奖牌榜”，说不定非洲的国家会成为榜魁…… 现在就请你写一个程序，对每个前来咨询的国家按照对其最有利的方式计算它的排名。

输入格式:
输入的第一行给出两个正整数N和M（≤224，因为世界上共有224个国家和地区），分别是参与排名的国家和地区的总个数、以及前来咨询的国家的个数。为简单起见，我们把国家从0 ~ N?1编号。之后有N行输入，第i行给出编号为i?1的国家的金牌数、奖牌数、国民人口数（单位为百万），数字均为[0,1000]区间内的整数，用空格分隔。最后面一行给出M个前来咨询的国家的编号，用空格分隔。

输出格式:
在一行里顺序输出前来咨询的国家的排名:计算方式编号。其排名按照对该国家最有利的方式计算；计算方式编号为：金牌榜=1，奖牌榜=2，国民人均金牌榜=3，国民人均奖牌榜=4。输出间以空格分隔，输出结尾不能有多余空格。

若某国在不同排名方式下有相同名次，则输出编号最小的计算方式。

输入样例:
4 4
51 100 1000
36 110 300
6 14 32
5 18 40
0 1 2 3

输出样例:
1:1 1:2 1:3 1:4*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_COUNTRY_NUM 225
using namespace std;

class country
{
public:
    int num;
    double judge[4];  //存四种计算方式的结果

    country(int g, int m, int p, int n)
    {
        judge[0] = g;
        judge[1] = m;
        judge[2] = 1.0 * g / p;
        judge[3] = 1.0 * m / p;
        num = n;
    };
};

int method;
vector<country> countries;

int main()
{
    int n, k, g, m, p, t;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> g >> m >> p;
        countries.emplace_back(country(g, m, p, i));
    }
    vector<pair<int, int>> rank(n, pair(MAX_COUNTRY_NUM, 0));   //存排名最小的结果以及相应的排序方式编号
    for (method = 0; method < 4; ++method)
    {
        sort(countries.begin(), countries.end(), [](country &x, country &y)
        { return x.judge[method] > y.judge[method]; });
        int r = 1;
        double pre = countries[0].judge[method];
        for (int i = 0; i < n; ++i)
        {
            r = (countries[i].judge[method] == pre) ? r : i + 1;  //注意奖牌数相同名次相同否则等于其当前编号+1（两个并列第一后面是第三而非第二）
            if (r < rank[countries[i].num].first)
                rank[countries[i].num] = move(pair(r, method + 1));
            pre = countries[i].judge[method];
        }
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> t;
        cout << ((i == 0) ? "" : " ") << rank[t].first << ":" << rank[t].second;
    }
}