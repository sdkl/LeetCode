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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		vector<TreeNode*> s;
		s.push_back(root);

		while (!s.empty())
		{
			TreeNode *cur = s.back();
			s.pop_back();
			if (cur != NULL)
			{
				result.push_back(cur->val);
				s.push_back(cur->right);
				s.push_back(cur->left);
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	TreeNode *a1 = new TreeNode(1);
	TreeNode *a2 = new TreeNode(2);
	TreeNode *a3 = new TreeNode(3);
	a1->right = a2;
	a2->left = a3;

	auto r = s.preorderTraversal(a1);
	for (auto i : r)
		cout << i << " ";

	getchar();
	return 0;
}