#include <iostream>
#include <stack>
#include <string>
#include <regex>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 下午6:15
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

/**
 * 解析并计算表达式的值
 * @param exp 数学表达式
 * @return 计算结果
 */
long caculateExp(string exp) {
    if (exp.empty()) {
        return 0;
    }
    // 数字栈
    stack<long> numStack;
    // 操作符栈
    stack<char> opStack;
    for (int i = 0; i < exp.size(); i++) {
        // 如果当前字符是数字，则将其转成整数压栈
        if (isdigit(exp[i])) {
            numStack.push(exp[i] - '0');
        } else {
            while (!opStack.empty() && opStack.top() == '*' && (exp[i] == '+' || exp[i] == '-')) {
                long b = numStack.top();
                numStack.pop();
                long a = numStack.top();
                numStack.pop();
                char op = opStack.top();
                opStack.pop();
                if (op == '*') {
                    numStack.push(a * b);
                }
            }
            opStack.push(exp[i]);
        }
    }
    while (!opStack.empty()) {
        long b = numStack.top(); numStack.pop(); // 弹出数字栈顶的两个数字b和a
        long a = numStack.top(); numStack.pop();
        char op = opStack.top(); opStack.pop(); // 弹出操作符栈顶的操作符op
        if (op == '+') { // 根据操作符进行相应的运算，并将结果压入数字栈中
            numStack.push(a + b);
        } else if (op == '-') {
            numStack.push(a - b);
        } else if (op == '*') {
            numStack.push(a * b);
        } else if (op == '/') {
            numStack.push(a / b);
        }
    }
    return numStack.top();
}

/**
 *
 * @param s 输入字符串
 * @return 计算结果
 */
long findAndCaculate(string &s) {
    regex expRegex("(\\d+)([\\*+-]\\d+)*");
    auto wordBegin = sregex_iterator(s.begin(), s.end(), expRegex);
    auto wordEnd = sregex_iterator();
    string longestExp;
    size_t maxLength = 0;
    for (sregex_iterator i = wordBegin; i != wordEnd; ++i) {
        string matchStr = i->str();
        if (matchStr.size() > maxLength && regex_search(matchStr, regex("^(-?\\d+([+\\-*]\\d+)+)$"))) {
            maxLength = matchStr.size();
            longestExp = matchStr;
        }
    }
    if (longestExp.empty()) {
        return 0;
    } else {
        return caculateExp(longestExp);
    }
}
int main() {
    string input;
    getline(cin, input);
    cout << findAndCaculate(input) << endl;
    return 0;
}