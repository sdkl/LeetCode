#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> size;

		vector<TreeNode*> v;
		if (root != NULL)
			v.push_back(root);
		int level = 0,curSize = 0;
		while (curSize != v.size())
		{			
			result.push_back(vector<int>());
			int n = v.size();
			size.push_back(n - curSize);			

			for (int i = curSize; i < n; i++)
			{
				TreeNode* cur = v[i];
				if (cur->left != NULL)
					v.push_back(cur->left);
				if (cur->right != NULL)
					v.push_back(cur->right);				
			}

			curSize = n;
			level++;
		}

		int num = v.size();
		for (int i = 0; i < level; i++)
		{
			int n = size[level - i - 1];
			for (int j = 0; j < n; j++)
			{
				result[i].push_back(v[num-n+j]->val);
			}
			num -= n;
		}

		return result;
	}
};

int main()
{
	Solution s;
	TreeNode head1(1);
	TreeNode head2(2);
	TreeNode head3(3);
	head1.left = &head2;
	head1.right = &head3;

	vector<vector<int>> r = s.levelOrderBottom(&head1);
	for (auto i : r)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}