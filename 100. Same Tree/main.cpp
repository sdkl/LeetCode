#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;     
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {		
		if (p != NULL && q != NULL && p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		if ((p == NULL || q == NULL))
			return p == q;
		return false;
	}
};

int main()
{
	Solution s;
	TreeNode* head1 = new TreeNode(1);
	TreeNode* head2 = new TreeNode(2);
	TreeNode* head3 = new TreeNode(3);
	head1->left = head2;
	head1->right = head3;

	cout << s.isSameTree(head1, head1);

	getchar();
	return 0;
}