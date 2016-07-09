There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

思路：
题目本身不难，但是有个限制时间复杂度要为O(log (m+n))。log级别的只有二分法，要用二分法解这道题需要精确的设计。
关键点是只要确定nums1中截取的长度，nums2中截取的长度也可以计算得出了。