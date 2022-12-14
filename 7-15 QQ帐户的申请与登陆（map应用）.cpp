/*7-15 QQ帐户的申请与登陆 (25 分)
实现QQ新帐户申请和老帐户登陆的简化版功能。最大挑战是：据说现在的QQ号码已经有10位数了。

输入格式:
输入首先给出一个正整数N（≤10^5），随后给出N行指令。每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。其中命令符为“N”（代表New）时表示要新申请一个QQ号，后面是新帐户的号码和密码；命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。QQ号码为一个不超过10位、但大于1000（据说QQ老总的号码是1001）的整数。密码为不小于6位、不超过16位、且不包含空格的字符串。

输出格式:
针对每条指令，给出相应的信息：

1）若新申请帐户成功，则输出“New: OK”；
2）若新申请的号码已经存在，则输出“ERROR: Exist”；
3）若老帐户登陆成功，则输出“Login: OK”；
4）若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；
5）若老帐户密码错误，则输出“ERROR: Wrong PW”。

输入样例:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com

输出样例:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, string> info;
    int n;
    cin >> n;
    char cmd;
    string account, password;
    for (int i = 0; i < n; ++i)
    {
        cin >> cmd >> account >> password;
        auto loc = info.find(account);
        switch (cmd)
        {
            case 'L':
                if (loc == info.end())
                    cout << "ERROR: Not Exist" << endl;
                else if (loc->second == password)
                    cout << "Login: OK" << endl;
                else
                    cout << "ERROR: Wrong PW" << endl;
                break;
            case 'N':
                if (loc == info.end())
                {
                    cout << "New: OK" << endl;
                    info[account] = password;
                }
                else
                    cout << "ERROR: Exist" << endl;
                break;
        }
    }
}
