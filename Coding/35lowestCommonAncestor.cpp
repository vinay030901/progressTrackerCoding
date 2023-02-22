#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool fun(TreeNode *root, vector<TreeNode *> &path, TreeNode *node)
{
    if (root == NULL)
        return false;
    path.push_back(root);
    if (root == node)
        return true;
    if (fun(root->left, path, node) || fun(root->right, path, node))
        return true;
    path.pop_back();
    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> ppath, qpath;
    fun(root, ppath, p);
    fun(root, qpath, q);
    TreeNode *ans = root;
    for (int i = 0; i < min(ppath.size(), qpath.size()); i++)
    {
        if (ppath[i]->val == qpath[i]->val)
            ans = ppath[i];
        else
            break;
    }
    return ans;
}
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};