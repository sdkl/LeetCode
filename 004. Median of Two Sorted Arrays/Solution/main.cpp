#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);

		int mid = (len1 + len2) / 2;
		int min = 0, max = len1 + 1, curX = 0, curY = 0;
		bool boo1, boo2;
		while (min < max)
		{
			curX = (min + max) / 2;
			curY = mid - curX;

			boo1 = curX == 0 ? true : nums1[curX - 1] <= nums2[curY];
			boo2 = curX == len1 ? true : nums2[curY - 1] <= nums1[curX];

			if (boo1 && boo2)
				break;

			!boo1 ? max = curX : min = curX;
		}

		int midX, midY;
		if (curX == 0)
			midX = nums2[curY - 1];
		else if (curY == 0)
			midX = nums1[curX - 1];
		else
			midX = nums1[curX - 1] > nums2[curY - 1] ? nums1[curX - 1] : nums2[curY - 1];

		if (curX == len1)
			midY = nums2[curY];
		else if (curY >= len2)
			midY = nums1[curX];
		else
			midY = nums1[curX] < nums2[curY] ? nums1[curX] : nums2[curY];

		return (len1 + len2) % 2 != 0 ? (double)midY : (double)(midX + midY) / 2;
	}
};

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(2);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);

	vector<int> v4;
	v4.push_back(3);
	v4.push_back(4);

	Solution s;
	cout << s.findMedianSortedArrays(v1, v2)<<endl;
	cout << s.findMedianSortedArrays(v3, v4)<<endl;

	system("PAUSE");
	return 0;
}