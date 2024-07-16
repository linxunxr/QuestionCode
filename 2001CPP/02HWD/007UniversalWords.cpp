#include <iostream>
#include <vector>
/**
 * Copyright (C), 2024-07-12
 * @author LinXun
 * @date 24-7-12 下午7:20
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

/**
 * 判断是否可以拼写单词
 * @param wordCount 字符库
 * @param count 想要拼写的单词
 * @param universalWord 万能字符数量
 * @return
 */
bool isCanSpell(vector<int> &wordCount, vector<int> &count, int universalWord) {
    for (int i = 0; i < 26; ++i) {
        if (wordCount[i] > count [i]) {
            universalWord -= wordCount[i] - count[i];
            if (universalWord < 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int num;
    cin >> num;
    cin.ignore();
   // 想要拼写的单词
    vector<string> words(num);
    for (int i = 0; i < num; ++i) {
        getline(cin, words[i]);
    }
    // 字符库
    string chars;
    getline(cin, chars);
    vector<int> count(26, 0);
    // 万能字符
    int universalWords = 0;
    // 获取字符库 万能字符个数
    for (char c : chars) {
        if (c != '?') {
            count[c - 'a']++;
        } else {
            universalWords++;
        }
    }
    int result = 0;
    for (string& word : words) {
        vector<int> wordCount(26, 0);
        // 计数当前单词
        for (char c : word) {
            wordCount[c - 'a']++;
        }
        if (isCanSpell(wordCount, count, universalWords)) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}