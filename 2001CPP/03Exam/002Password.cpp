/**
 * Copyright (C), 2024-07-17
 * @author LinXun
 * @date 24-7-17 下午2:18
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <regex>
#include <string>
using namespace std;

/**
 * 解析密码
 * @param input 密码
 * @return 解密后的明文
 */
string getPassword(string input) {
    for (int i = 26; i > 0; --i) {
        string key = to_string(i) + (i >= 10 ? "\\*" : "");
        char value = static_cast<char>(96 + i);
        input = regex_replace(input, regex(key), string(1, value));
    }
    return input;
}
int main() {
    string input;
    getline(cin, input);
    string result = getPassword(input);
    cout << result << endl;
    return 0;
}