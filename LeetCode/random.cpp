#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
	void quickSort(vector<int>& nums, int lef, int rit) {
		if (lef >= rit) return;
		int l = lef;
		int r = rit;
		int tmp = nums[(l + r)/2];
		while (l <= r) {
			while (nums[r] > tmp ) r--;
			while (nums[l] < tmp ) l++;
			if (l <= r) 	{
				swap(nums[l],nums[r]);
				l++;
				r--;
			}	

		}
		if(lef<r) {
			quickSort(nums,lef, r+1);
		}
		if(l<rit) {
			quickSort(nums,l,rit);
		}
	}

    public:
	int hardestWorker(int n, vector<vector<int>>& logs) {
		int time = logs[0][1];
		int id = logs[0][0];
		for (int i = 1; i < logs.size(); i++) {
			int tmp = logs[i][1] - logs[i - 1][1];
			int idx = logs[i][0];
			if (tmp > time || (tmp == time && id > idx)) {
				time = tmp;
				id = idx;
			}
		}
		return id;
	}

	// 2279.装满石头的背包的最大数量
	int maximumBags(vector<int>& capacity, vector<int>& rocks,
			int additionalRocks) {
		int n = capacity.size();
		for (int i = 0; i < n; i++) capacity[i] -= rocks[i];
		quickSort(capacity, 0, n - 1);
		if (capacity[0] > additionalRocks) return 0;
		for (int i = 1; i < n; i++) {
			capacity[i] += capacity[i - 1];
			if (capacity[i] > additionalRocks) return i;
		}
		return n;
	}

	// 11.盛最多水的容器
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ans = 0;
		while (l < r) {
			int area = min(height[l], height[r]) * (r - l);
			ans = max(area, ans);
			if (height[l] < height[r])
				l++;
			else
				r--;
		}
		return ans;
	}
}
