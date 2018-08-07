/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		vector<int> dp1(n, 0);
		vector<int> dp2(n, 0);
		if (n == 1)return nums[0];
		if (n == 2)return nums[0] > nums[1] ? nums[0] : nums[1];
		// if 0 is not used
		dp1[1] = nums[1];
		for (int i = 2; i< n; i++)
		{
			if (i >= 3)
				dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
			else
				dp1[i] = max(nums[i], dp1[i - 1]);

		}
		//if 0 is used
		dp2[0] = nums[0];
		for (int i = 1; i < n - 1; i++)
		{
			if (i >= 2)
				dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
			else
				dp2[i] = max(nums[i], dp2[i - 1]);
		}
		return max(max(dp1[n - 1], dp1[n - 2]), max(dp2[n - 2], dp2[n - 3]));
	}
};
