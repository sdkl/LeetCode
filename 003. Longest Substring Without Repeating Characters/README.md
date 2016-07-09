Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

思路：
建一个数组统计每个字符到下一个相同字符的长度，再从这个数组选出最大值。注意字符串长度小于2的情况。
注意子串中是否有更短的情况



别人的优秀代码：
int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = maxLen > i - start ? maxLen : i - start;
		}
		return maxLen;
	}

思路简洁高效