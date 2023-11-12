#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  private:
    string phonemap[8] = {"abc", "def",  "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};

    void mergeSort(vector<int> &num, int lo, int hi) {
        if (hi - lo < 2)
            return;
        int mi = (lo + hi) >> 1;
        mergeSort(num, lo, mi);
        mergeSort(num, mi, hi);
    }

    void quickSort(vector<int> &nums, int lef, int rit) {
        if (lef >= rit)
            return;
        int l = lef;
        int r = rit;
        int tmp = nums[l];
        while (l < r) {
            while (nums[r] < tmp && l < r)
                r--;
            while (nums[l] >= tmp && l < r)
                l++;
            if (l < r)
                swap(nums[l], nums[r]);
        }
        swap(nums[lef], nums[l]);
        quickSort(nums, lef, l - 1);
        quickSort(nums, l + 1, rit);
    }

    int binarySearch(const vector<int> &nums, int target, int start, int end) {
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
    // 枚举(n^2)|哈希表(n)
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
                return {it->second, i};
            hashtable[nums[i]] = i;
        }
        return {};
    }

    // 2.两数相加
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int last = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
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
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (last)
            tail->next = new ListNode(last);
        return head;
    }

    // 3.无重复字符的最长字串
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
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
        if (n == 1 || n == num || num == 1)
            return s;
        vector<char> a;
        for (int i = 0; i < num; i++) {
            int k = 0;
            for (int j = i; j < n;) {
                a.push_back(s[j]);
                if (i == 0 || i == num - 1)
                    j += 2 * num - 2;
                else {
                    j += k % 2 == 0 ? 2 * (num - 1 - i) : 2 * i;
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
            if (abs(ans) > 214748364)
                return 0;
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
            if (c == ' ' && !read)
                continue;
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
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
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
                    if (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                        dp[i][j] |= dp[i - 1][j];
                } else {
                    if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1]))
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        return dp[n][m];
    }

    // 11.盛最多水的容器
    int maxArea(vector<int> &height) {
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
                            40,   10,  9,   5,   4,   1};
        vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                  "XL", "X",  "IX", "V",  "IV", "I"};
        for (int i = 0; i < 13 && num; i++) {
            while (num >= nums[i]) {
                ans += symbols[i];
                num -= nums[i];
            }
        }

        // 第二种解法
        string ans1;
        string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
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
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
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
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        int n = strs.size();
        int m = strs[0].length();
        for (int i = 0; i < m; i++) {
            char c = strs[0][i];
            bool sat = true;
            for (int j = 1; j < n; j++) {
                if (strs[j].length() < i + 1 || strs[j][i] != c) {
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

    // NOTE: 15.三数之和
    // NOTE: 暴力枚举 O(n^3)
    vector<vector<int>> threeSum0(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0)
                        ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }

    // NOTE: 二分搜索 O(n^2 log(n))
    vector<vector<int>> threeSum1(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = binarySearch(nums, -nums[i] - nums[k], j + 1, n);
                if (k > 0)
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }

    // PERF: 双指针法 O(n^2)
    vector<vector<int>> threeSum2(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int target = nums[i] + nums[l] + nums[r];
                if (target > 0)
                    r--;
                else if (target < 0)
                    l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (r > l && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return ans;
    }

    // NOTE: 16.最接近的三数之和
    // PERF: 和15题一样的思路，排序加双指针
    int threeSumClosest(vector<int> &nums, int target) {
        int ans = nums[0] + nums[1] + nums[2] - target;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r] - target;
                if (abs(ans) > abs(tmp))
                    ans = tmp;
                if (tmp > 0)
                    r--;
                else if (tmp < 0)
                    l++;
                else
                    return target;
            }
        }
        return ans + target;
    }

    // NOTE: 17.电话号码的字母组合
    // NOTE: 用数组去存储对应字母的选择
    vector<string> letterCombinations1(string digits) {
        if (digits == "")
            return {};
        unordered_map<char, string> phoneMap{
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int n = digits.length();
        int sum = 1;
        vector<int> up(n);
        vector<int> curr(n, 0);
        for (int i = 0; i < n; i++) {
            if (digits[i] == '7' || digits[i] == '9') {
                up[i] = 4;
                sum *= 4;
            } else {
                up[i] = 3;
                sum *= 3;
            }
        }
        vector<string> ans(sum);
        for (int i = 0; i < sum; i++) {
            vector<char> tmp(n);
            for (int j = 0; j < n; j++)
                tmp[j] = phoneMap[digits[j]][curr[j]];
            ans[i] = string(tmp.begin(), tmp.end());
            int l = n - 1;
            curr[l]++;
            while (curr[l] == up[l]) {
                curr[l] = 0;
                l--;
                if (l < 0)
                    break;
                curr[l]++;
            }
        }
        return ans;
    }

    // PERF: 回溯法递归
    vector<string> letterCombinations2(string digits) {
        if (digits == "")
            return {};
        vector<string> ans;
        string last;
        backTrack(last, digits, 0, ans);
        return ans;
    }

    void backTrack(string &last, const string &digits, int num,
                   vector<string> &ans) {
        if (num == digits.length()) {
            ans.push_back(last);
            return;
        }
        for (char c : phonemap[digits[num] - '2']) {
            last.push_back(c);
            backTrack(last, digits, num + 1, ans);
            last.pop_back();
        }
    }

    // NOTE: 18.四数之和
    // PERF: 和三数之和一样，排序加双指针
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    long long int tmp =
                        (long long int)nums[i] + (long long int)nums[j] +
                        (long long int)nums[l] + (long long int)nums[r] -
                        (long long int)target;
                    if (tmp > 0)
                        r--;
                    else if (tmp < 0)
                        l++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return ans;
    }

    // NOTE: 19.删除链表的倒数第n个节点
    // NOTE: 计算链表的长度
    ListNode *removeNthFromEnd1(ListNode *head, int n) {
        ListNode *h = head;
        int num = 0;
        while (h) {
            num++;
            h = h->next;
        }
        num -= n;
        if (!num) {
            head = head->next;
            return head;
        }
        h = head;
        for (int i = 0; i < num - 1; i++)
            h = h->next;
        ListNode *tmp = h->next;
        h->next = tmp->next;
        tmp = nullptr;
        return head;
    }

    // PERF: 双指针
    ListNode *removeNthFromEnd2(ListNode *head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n && fast; i++)
            fast = fast->next;
        if (!fast) {
            head = head->next;
            return head;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }

    // NOTE: 20.有效的括号
    // NOTE: 栈
    bool isValid1(string s) {
        stack<char> sta;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                sta.push(c);
            else {
                if (sta.empty())
                    return false;
                if (c == ')') {
                    if (sta.top() == '(')
                        sta.pop();
                    else
                        return false;
                } else if (c == ']') {
                    if (sta.top() == '[')
                        sta.pop();
                    else
                        return false;
                } else if (c == '}') {
                    if (sta.top() == '{')
                        sta.pop();
                    else
                        return false;
                }
            }
        }
        return sta.empty();
    }

    // PERF: 栈 + map
    bool isValid2(string s) {
        int n = s.length();
        if (n % 2 == 1)
            return false;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (char c : s) {
            if (pairs.count(c)) {
                if (stk.empty() || stk.top() != pairs[c])
                    return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }

    // NOTE: 21.合并两个有序链表
    // NOTE: 迭代实现
    ListNode *mergeTwoLists1(ListNode *list1, ListNode *list2) {
        ListNode *ans = nullptr;
        ListNode *p = nullptr;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list2->val < list1->val) {
            ans = list2;
            p = ans;
            list2 = list2->next;
        } else {
            ans = list1;
            p = ans;
            list1 = list1->next;
        }
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        if (list1)
            p->next = list1;
        else if (list2)
            p->next = list2;
        return ans;
    }

    // NOTE: 递归实现
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }
    }

    // PERF: 迭代优化 避免空数组
    ListNode *mergeTwoLists3(ListNode *list1, ListNode *list2) {
        ListNode *ans = new ListNode(-1);
        ListNode *p = ans;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 == nullptr ? list2 : list1;
        return ans->next;
    }

    // NOTE: 22.括号生成
    // NOTE: 回溯 + 去重
    void backPairs(unordered_set<string> &ans, string &str, int n) {
        if (!n) {
            ans.insert(str);
            return;
        }
        string tmp = str;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            str = tmp.substr(0, i) + "()" + tmp.substr(i, len - i);
            backPairs(ans, str, n - 1);
            str = tmp;
        }
    }

    // NOTE: 23.合并k个升序链表
    // NOTE: 两两排序 O(k^2*n)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (!n)
            return nullptr;
        for (int i = n - 2; i >= 0; i--) {
            lists[i] = mergeTwoLists3(lists[i], lists[i + 1]);
        }
        return lists[0];
    }

    vector<string> generateParenthesis(int n) {
        unordered_set<string> ans;
        string str = "()";
        backPairs(ans, str, n - 1);
        return vector<string>(ans.begin(), ans.end());
    }

    // NOTE: 26.删除有序数组中的重复项
    // NOTE: 借助额外数组
    int removeDuplicates1(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++)
            if (nums[i] != ans.back())
                ans.push_back(nums[i]);
        int k = ans.size();
        nums.resize(k);
        for (int i = 0; i < k; i++)
            nums[i] = ans[i];
        return k;
    }

    // PERF: 双指针
    int removeDuplicates2(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int slow = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[slow]) {
                slow++;
                nums[slow] = nums[i];
            }
        slow++;
        nums.resize(slow);
        return slow;
    }

    // 309.买卖股票的最佳时机含冷冻期
    int maxProfit(vector<int> &prices) {
        int a = 0;          // 未持有股票和非冷冻期
        int b = -prices[0]; // 持有股票和非冷冻期
        int c = 0;          // 未持有股票和冷冻期
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
    vector<string> str1;
    string s1;
    string s2;
    int n1;
    cin >> s1;
    str1 = test.letterCombinations1(s1);
    for (int i = 0; i < str1.size(); i++)
        cout << str1[i] << endl;
    return 0;
}
