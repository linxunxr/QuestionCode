#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <regex>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 下午4:27
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

/**
 * 解析输入的字符串
 * @param input 输入的字符串
 * @return 解析后的字符数组
 */
vector<string> handleEnglish(string &input) {
    vector<string> temp;
    regex wordRegex(R"(\b\w+('\w+)?\b)");
    auto wordBegin = sregex_iterator(input.begin(), input.end(), wordRegex);
    auto wordEnd = sregex_iterator();
    for (sregex_iterator i = wordBegin; i != wordEnd; ++i) {
        smatch match = *i;
        string word = match.str(0);
        size_t pos = word.find("'");
        if (pos != string::npos) {
            // 如果存在‘ 分隔单词
            temp.push_back(word.substr(0, pos));
            temp.push_back(word.substr(pos + 1));
        } else {
            temp.push_back(word);
        }
    }
    return temp;
}

/**
 * 过滤并排序
 * @param words 单词组
 * @param prefix 前缀
 * @return 过滤结果
 */
set<string> filterSortWords(vector<string> &words, string &prefix) {
    set<string> temp;
    for (string &word: words) {
        if (word.substr(0, prefix.size()) == prefix) {
            temp.insert(word);
        }
    }
    return temp;
}

int main() {
    string input, prefix;
    getline(cin, input);
    cin >> prefix;
    // 提取单词
    vector<string> words = handleEnglish(input);
    // 过滤并排序
    set<string> result = filterSortWords(words, prefix);
    // 输出结果
    if (result.empty()) {
        cout << prefix;
    } else {
        bool first = true;
        for (string word : result) {
            if (!first) {
                cout << " ";
            }
            cout << word;
            first = false;
        }
    }
}