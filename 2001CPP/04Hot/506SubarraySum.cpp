/**
 * Copyright (C), 2024-07-20
 * @author LinXun
 * @date 24-7-20 下午12:02
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    int preSum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int num : nums) {
        preSum += num;
        if (map.count(preSum - k)) {
            result += map[preSum - k];
        }
        map[preSum]++;
    }
    return result;
}
int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum(nums, k) <<  endl;
}