#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;
stack<int> num;
stack<int> op;
int flag;

void eval() {
    auto b = num.top() ; num.pop();
    auto a = num.top() ; num.pop();
    auto c = op.top() ; op.pop();
    int x;
    if(c == '+')        x = a + b;
    else if(c == '-')   x = a - b;
    else if(c == '*')   x = a * b;
    else if(c == '/') {
        if(b)           x = a / b;
        else {
            printf("中途有分母为0\n");
            flag = 0;
        }            
    }
    num.push(x);
}

int main() {
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    char choose = '1';
    while(choose == '1') {
        system("cls");
        flag = 1;
        printf("请输入您的表达式（输入 = 按回车即可）：");
        string str;
        char c;
        while(cin >> c, c != '=') {
            if(c >= '0' && c <= '9' || c == '+' || c == '-' || c == '*' || c == '/')
                str += c;               //看啥呢，就是防止你脸滚键盘润滑键盘(doge)
        }

        for(int i = 0 ; i < str.size() ; i ++ ) {
            auto c = str[i];
            if(isdigit(c)) {
                int x = 0, j = i;
                while(j < str.size() && isdigit(str[j]))
                    x = x * 10 + str[j ++ ] - '0';
                i = j - 1;
                num.push(x);
            }
            else if(c == '(')   op.push(c);
            else if(c == ')') {
                while(op.top() != '(')  eval();
                op.pop();
            }
            else {
                while(op.size() && pr[op.top() >= pr[c]])   eval();
                op.push(c);
            }
        }
        while(op.size())    eval();
        if(flag)
            cout << num.top() << endl;

        printf("请问是否继续计算， 请输入数字 1 或 0：");
        scanf("%s",&choose);
        while(choose != '0' && choose != '1') {
            printf("无效的输入请重试：");
            scanf("%s",&choose);
        }
    }
    printf("感谢使用！\n");
    system("pause");
    return 0;
}