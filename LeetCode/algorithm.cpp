#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    private:
	void quickSort(vector<int>& nums, int lef, int rit) {
		if (lef >= rit) return;
		int l = lef;
		int r = rit;
		int tmp = nums[l];
		while (l < r) {
			while (nums[r] < tmp && l < r) r--;
			while (nums[l] >= tmp && l < r) l++;
			if (l < r) swap(nums[l], nums[r]);
		}
		swap(nums[lef], nums[l]);
		quickSort(nums, lef, l - 1);
		quickSort(nums, l + 1, rit);
	}

	int binarySearch(const vector<int>& nums, int target, int start,
			 int end) {
		while (start <= end) {
			int m = (start + end) / 2;
			int c = nums[m];
			if (c > target) {
				end = m - 1;
			} else if (c < target) {
				start = m + 1;
			} else if (c == target) {
				return m;
			}
		}
		return -1;
	}

    public:
	// 1.两数之和
	//枚举(n^2)|哈希表(n)
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); i++) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) return {it->second, i};
			hashtable[nums[i]] = i;
		}
		return {};
	}

	// 2.两数相加
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int last = 0;
		ListNode* head = nullptr;
		ListNode* tail = nullptr;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + last;
			if (sum > 9) {
				sum %= 10;
				last = 1;
			} else {
				last = 0;
			}
			if (!head) {
				head = tail = new ListNode(sum);
			} else {
				tail->next = new ListNode(sum);
				tail = tail->next;
			}
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (last) tail->next = new ListNode(last);
		return head;
	}

	// 3.无重复字符的最长字串
	int lengthOfLongestSubstring(string s) {
		if (s == "") return 0;
		int ans = 1;
		int tmp = 1;
		unordered_set<char> mySet;
		mySet.insert(s[0]);
		for (auto ch : s) {
			if (mySet.count(ch)) {
				tmp = 1;
				mySet.clear();
			} else {
				tmp++;
				ans = max(ans, tmp);
			}
			mySet.insert(ch);
		}
		return ans;
	}

	// 4.寻找两个正序数组的中位数
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		return 0.0;
	}

	// 5.最长回文串
	string longestPalindrome(string s) {
		int n = s.length();
		int start = 0;
		int len = 1;
		vector<vector<int>> dp(n, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i][i] = 1;
			if (s[i - 1] == s[i]) {
				dp[i - 1][i] = 1;
				start = i - 1;
				len = 2;
			}
		}
		for (int i = n - 3; i >= 0; i--)
			for (int j = i + 2; j < n; j++) {
				if (dp[i + 1][j - 1] && s[i] == s[j]) {
					dp[i][j] = 1;
					if (j - i + 1 > len) {
						start = i;
						len = j - i + 1;
					}
				}
			}
		string ans = s.substr(start, len);
		return ans;
	}

	// 6.N字形变换
	string convert(string s, int num) {
		int n = s.length();
		if (n == 1 || n == num || num == 1) return s;
		vector<char> a;
		for (int i = 0; i < num; i++) {
			int k = 0;
			for (int j = i; j < n;) {
				a.push_back(s[j]);
				if (i == 0 || i == num - 1)
					j += 2 * num - 2;
				else {
					j += k % 2 == 0 ? 2 * (num - 1 - i)
							: 2 * i;
					k++;
				}
			}
		}
		string ans(a.begin(), a.end());
		return ans;
	}

	// 7.整数反转
	int reverse(int x) {
		int ans = 0;
		while (x != 0) {
			if (abs(ans) > 214748364) return 0;
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return ans;
	}

	// 8.字符串转换整数
	int myAtoi(string s) {
		int sign = 1;
		long long int ans = 0;
		bool read = false;
		for (char c : s) {
			if (c == ' ' && !read) continue;
			if (c == '-' && !read) {
				sign = -1;
				read = true;
				continue;
			}
			if (c == '+' && !read) {
				sign = 1;
				read = true;
				continue;
			}
			if (c - '0' >= 0 && c - '0' < 10) {
				ans = ans * 10 + c - '0';
				read = true;
				if (sign == 1 && ans >= 2147483647)
					return 2147483647;
				if (sign == -1 && ans >= 2147483648)
					return -2147483648;
			} else
				break;
		}
		ans *= sign;
		return ans;
	}

	// 9.回文数
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int tmp = x;
		int y = 0;
		while (tmp) {
			y = 10 * y + tmp % 10;
			tmp /= 10;
		}
		return x == y;
	}

	// 10.正则表达式匹配
	bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (i > 0 && (p[j - 2] == '.' ||
						      p[j - 2] == s[i - 1]))
						dp[i][j] |= dp[i - 1][j];
				} else {
					if (i > 0 && (p[j - 1] == '.' ||
						      p[j - 1] == s[i - 1]))
						dp[i][j] = dp[i - 1][j - 1];
				}
			}
		return dp[n][m];
	}

	// 11.盛最多水的容器
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ans = 0;
		while (l < r) {
			int tmp = min(height[l], height[r]) * (r - l);
			ans = max(tmp, ans);
			height[l] < height[r] ? l++ : r--;
		}
		return ans;
	}

	// 12.整数转罗马数字
	string intToRoman(int num) {
		string ans;
		vector<int> nums = {1000, 900, 500, 400, 100, 90, 50,
				    40,	  10,  9,   5,	 4,   1};
		vector<string> symbols = {"M",	"CM", "D",  "CD", "C",
					  "XC", "L",  "XL", "X",  "IX",
					  "V",	"IV", "I"};
		for (int i = 0; i < 13 && num; i++) {
			while (num >= nums[i]) {
				ans += symbols[i];
				num -= nums[i];
			}
		}

		// 第二种解法
		string ans1;
		string thousands[] = {"", "M", "MM", "MMM"};
		string hundreds[] = {"",  "C",	"CC",  "CCC",  "CD",
				     "D", "DC", "DCC", "DCCC", "CM"};
		string tens[] = {"",  "X",  "XX",  "XXX",  "XL",
				 "L", "LX", "LXX", "LXXX", "XC"};
		string ones[] = {"",  "I",  "II",  "III",  "IV",
				 "V", "VI", "VII", "VIII", "IX"};
		ans1 = thousands[num / 1000] + hundreds[(num / 100) % 10] +
		       tens[(num / 10) % 10] + ones[num % 10];
		return ans;
	}

	// 13.罗马数字转整数
	int romanToInt(string s) {
		int n = s.length();
		int ans = 0;
		unordered_map<char, int> symbolValues = {
		    {'I', 1},	{'V', 5},   {'X', 10},	 {'L', 50},
		    {'C', 100}, {'D', 500}, {'M', 1000},
		};
		for (int i = 0; i < n; i++) {
			int val = symbolValues[s[i]];
			if (i < n - 1 && val < symbolValues[s[i + 1]])
				ans -= val;
			else
				ans += val;
		}
		return ans;
	}

	// 14.最长公共前缀
	string longestCommonPrefix(vector<string>& strs) {
		string ans;
		int n = strs.size();
		int m = strs[0].length();
		for (int i = 0; i < m; i++) {
			char c = strs[0][i];
			bool sat = true;
			for (int j = 1; j < n; j++) {
				if (strs[j].length() < i + 1 ||
				    strs[j][i] != c) {
					sat = false;
					break;
				}
			}
			if (sat)
				ans += c;
			else
				return ans;
		}
		return ans;
	}

	// 15.三数之和
	vector<vector<int>> threeSum(vector<int>& nums) {

	}

	// 309.买卖股票的最佳时机含冷冻期
	int maxProfit(vector<int>& prices) {
		int a = 0;	     //未持有股票和非冷冻期
		int b = -prices[0];  //持有股票和非冷冻期
		int c = 0;	     //未持有股票和冷冻期
		for (int i = 0; i < prices.size(); i++) {
			int tmp = b;
			b = max(b, a - prices[i]);
			a = max(a, c);
			c = tmp + prices[i];
		}
		return max(a, c);
	}
};

int main() {
	Solution test;
	string s1;
	string s2;
	int n1;
	cin >> s1 >> s2;
	cout << test.isMatch(s1, s2) << endl;
	return 0;
}
