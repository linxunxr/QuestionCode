//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。 
//
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 返回容器可以储存的最大水量。 
//
// 说明：你不能倾斜容器。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
//解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 示例 2： 
//
// 
//输入：height = [1,1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 2 <= n <= 10⁵ 
// 0 <= height[i] <= 10⁴ 
// 
//
// Related Topics 贪心 数组 双指针 👍 5042 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int result = 0;
        while (leftIndex <= rightIndex) {
            int currentHeight = min(height[leftIndex], height[rightIndex]);
            result = max(result, currentHeight * (rightIndex - leftIndex));
            if (height[leftIndex] == currentHeight) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
