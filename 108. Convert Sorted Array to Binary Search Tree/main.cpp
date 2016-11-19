#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end) {
		if (start > end)
			return NULL;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, start, mid-1);
		root->right = sortedArrayToBST(nums, mid+1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};

void printTree(TreeNode* root,string space)
{
	if (root == NULL)
		return;

	if (root->right != NULL)
		printTree(root->right,space+" ");

	cout << space.c_str() << root->val << endl;

	if (root->left != NULL)
		printTree(root->left, space + " ");
}

int main()
{
	Solution s;
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	TreeNode* head = s.sortedArrayToBST(v);
	printTree(head,"");

	getchar();
	return 0;
}