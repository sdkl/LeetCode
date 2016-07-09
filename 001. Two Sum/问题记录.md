Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.


我的思路：
2层循环遍历数组，找出2个相加等于指定值的元素。时间复杂度O（n*n），空间复杂度O(1)。



其他人的优秀思路：
用哈希表，可以用一次遍历就找到目标。时间复杂度O（n），空间复杂度O(n)。