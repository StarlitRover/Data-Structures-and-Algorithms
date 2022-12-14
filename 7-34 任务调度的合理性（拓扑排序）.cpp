/*7-34 任务调度的合理性 (25 分)
假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。

比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。

但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，这就是一个不可行的方案。你现在的工作是写程序判定任何一个给定的任务调度是否可行。

输入格式:
输入说明：输入第一行给出子任务数N（≤100），子任务按1~N编号。随后N行，每行给出一个子任务的依赖集合：首先给出依赖集合中的子任务数K，随后给出K个子任务编号，整数之间都用空格分隔。

输出格式:
如果方案可行，则输出1，否则输出0。

输入样例1:
12
0
0
2 1 2
0
1 4
1 5
2 3 6
1 3
2 7 8
1 7
1 10
1 7

输出样例1:
1

输入样例2:
5
1 4
2 1 4
2 2 5
1 3
0
输出样例2:
0*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, cnt = 0;
    cin >> n;
    vector<vector<int>> out_point(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            cin >> k;
            out_point[i].push_back(k - 1);
            in_degree[k - 1] += 1;
        }
    }
    vector<int>::iterator zero_node;
    while ((zero_node = find(in_degree.begin(), in_degree.end(), 0)) != in_degree.end())
    {
        for (auto &r: out_point[zero_node - in_degree.begin()])
            in_degree[r] -= 1;
        *zero_node = -1;
        ++cnt;
    }
    if (cnt == n)
        cout << 1;
    else
        cout << 0;
}