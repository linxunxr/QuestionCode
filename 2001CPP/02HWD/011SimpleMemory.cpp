/**
 * Copyright (C), 2024-07-15
 * @author LinXun
 * @date 24-7-15 下午3:24
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SimpleMemoryPool {
public:
    SimpleMemoryPool() {
        status_ = vector<bool>(poolSize_, false);
    }

    /**
     * 申请内存
     * @param size 申请内存大小
     * @return 申请到的内容首地址
     */
    int ApplyMemory(int size) {
        int result = -1;
        if (size <= 0) {
            return result;
        }
        for (int i = 0; i <= poolSize_; ++i) {
            int j = 0;
            while (j < size) {
                if (status_[i + j]) {
                    break;
                } else {
                    j++;
                }
            }
            if (j == size) {
                result = i;
                break;
            }
        }
        if (result == -1) {
            return result;
        }
        used_[result] = size;
        for (int i = 0; i < size; ++i) {
            status_[i + result] = true;
        }
        return result;
    }

    /**
     * 释放内存
     * @param start 释放内存首地址
     * @return 是否释放成功
     */
    bool ReleaseMemory(int start) {
        if (used_.count(start) == 0) {
            return false;
        }
        int size = used_[start];
        for (int i = 0; i < start + size; ++i) {
            status_[i] = false;
        }
        used_.erase(start);
        return true;
    }
private:
     // 标记状态
    vector<bool> status_;
    // 首地址 分配长度
    map<int, int> used_;
    // 内存池总大小
    static constexpr int poolSize_ = 100;
};

int main() {
    int num;
    cin >> num;
    SimpleMemoryPool simpleMemoryPool;
    for (int i = 0; i < num; ++i) {
        string input;
        getline(cin, input);
        string cmd = input.substr(0, input.find_first_of('='));
        int param = stoi(input.substr(input.find_first_of('=') + 1));
        if (cmd == "REQUEST") {
            int size = param;
            int result = simpleMemoryPool.ApplyMemory(size);
            if (result != -1) {
                cout << result << endl;
            } else {
                cout << "error" << endl;
            }
        } else {
            int start = param;
            if (!simpleMemoryPool.ReleaseMemory(start)) {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}