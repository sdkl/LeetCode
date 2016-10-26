#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int last = m + n,cm = m - 1,cn = n - 1;
		while (last-- > 0 && (cm >= 0 || cn >= 0))
		{
			if (cm < 0)
				nums1[last] = nums2[cn--];
			else if (cn < 0)
				nums1[last] = nums1[cm--];
			else
				nums1[last] = nums2[cn] > nums1[cm] ? nums2[cn--] : nums1[cm--];
		}
	}
};

int main()
{
	Solution s;
	vector<int> a = { 1, 2, 3, 0, 0, 0 };
	vector<int> b = { 4, 5, 6 };
	s.merge(a, 3, b, 3);
	for (auto i : a)
		cout << i << " ";

	getchar();
	return 0;
}