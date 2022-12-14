/*7-41 PAT排名汇总 (25 分)
计算机程序设计能力考试（Programming Ability Test，简称PAT）旨在通过统一组织的在线考试及自动评测方法客观地评判考生的算法设计与程序设计实现能力，科学的评价计算机程序设计人才，为企业选拔人才提供参考标准（网址http://www.patest.cn）。

每次考试会在若干个不同的考点同时举行，每个考点用局域网，产生本考点的成绩。考试结束后，各个考点的成绩将即刻汇总成一张总的排名表。

现在就请你写一个程序自动归并各个考点的成绩并生成总排名表。

输入格式:
输入的第一行给出一个正整数N（≤100），代表考点总数。随后给出N个考点的成绩，格式为：首先一行给出正整数K（≤300），代表该考点的考生总数；随后K行，每行给出1个考生的信息，包括考号（由13位整数字组成）和得分（为[0,100]区间内的整数），中间用空格分隔。

输出格式:
首先在第一行里输出考生总数。随后输出汇总的排名表，每个考生的信息占一行，顺序为：考号、最终排名、考点编号、在该考点的排名。其中考点按输入给出的顺序从1到N编号。考生的输出须按最终排名的非递减顺序输出，获得相同分数的考生应有相同名次，并按考号的递增顺序输出。

输入样例:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

输出样例:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class student
{
public:
    string num;
    int score, test_room, room_rank;

    student(string n, int s, int tr) : num(n), score(s), test_room(tr)
    {};
};

bool cmp(student &x, student &y) //定义cmp比较函数
{ return x.score > y.score || (x.score == y.score && x.num < y.num); }

int main()
{
    int n, m, rank, pre;
    cin >> n;
    vector<student> room, all;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            string num;
            int score;
            cin >> num >> score;
            room.emplace_back(student(num, score, i + 1));
        }
        sort(room.begin(), room.end(), cmp);
        rank = 1, pre = room[0].score;
        for (int j = 0; j < m; ++j)
        {
            rank = (room[j].score == pre) ? rank : j + 1;
            room[j].room_rank = rank;
            pre = room[j].score;
        }
        all.insert(all.end(), room.begin(), room.end()); //比较完单个考场后将该考场学生信息移入all并清空room
        room.clear();
    }
    sort(all.begin(), all.end(), cmp);
    cout << all.size() << endl;
    rank = 1, pre = all[0].score;
    for (int i = 0; i < all.size(); ++i)
    {
        rank = (all[i].score == pre) ? rank : i + 1;
        pre = all[i].score;
        cout << all[i].num << " " << rank << " " << all[i].test_room << " " << all[i].room_rank << endl;
    }
}