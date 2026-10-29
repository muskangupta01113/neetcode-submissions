/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

int diameter=0;
 int height(TreeNode* root){
     if(root == NULL){
    return 0;
    
}

    int  leftNode= height(root->left);
    int  rightNode= height(root->right);

    diameter = max(diameter,leftNode+rightNode);
    

        return 1 + max(leftNode,rightNode);

}

    int diameterOfBinaryTree(TreeNode* root) {

       height(root);
       return diameter;

    }
};
