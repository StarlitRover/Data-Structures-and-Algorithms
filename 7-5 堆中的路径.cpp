/*7-5 堆中的路径 (25 分)
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
结尾无空行
输出样例:
24 23 10
46 23 10
26 10
结尾无空行*/
#include <iostream>
#include <vector>

using namespace std;

class min_heap
{
public:
    void append(int k);

    void printPath(int k);

private:
    int num = 0;
    vector<int> val;
};

void min_heap::append(int k)
{
    val.push_back(k);
    num += 1;
    int father_num = num / 2, self_num = num;
    while (self_num != 1 && val[father_num - 1] > val[self_num - 1])
    {
        swap(val[father_num - 1], val[self_num - 1]);
        self_num = father_num;
        father_num = father_num / 2;
    }
}

void min_heap::printPath(int k)
{
    for (k; k > 0; k /= 2)
    {
        cout << val[k - 1];
        if (k != 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    min_heap h;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        h.append(k);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        h.printPath(k);
    }
}
