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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		vector<TreeNode*> roots;
		if (root != NULL)
			roots.push_back(root);
		TreeNode *last = NULL;

		while (!roots.empty())
		{
			TreeNode *cur = roots.back();
			if ((cur->right == NULL && (cur->left == NULL || cur->left == last) )|| (cur->right != NULL && cur->right == last))
			{
				roots.pop_back();
				result.push_back(cur->val);
				last = cur;
			}			
			else
			{			
				if (cur->left != NULL && cur->left != last)
					roots.push_back(cur->left);
				else
					roots.push_back(cur->right);				
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
	TreeNode *a4 = new TreeNode(4);
	a1->right = a2;
	a2->left = a3;
	a2->right = a4;
	auto r = s.postorderTraversal(a1);
	for (auto i : r)
		cout << i << " ";

	getchar();
	return 0;
}