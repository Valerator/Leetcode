// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true
  
  
// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) //если корень nullptr, то дерево симметрично
            return true;
        return foo(root->left, root->right);
        
    }

    bool foo(TreeNode *tree_1, TreeNode *tree_2) {
        if (tree_1 == nullptr && tree_2 == nullptr) { //если оба потомка nullptr, то дерево симметрично
            return true;
        }
        if((tree_1 != nullptr && tree_2 != nullptr) && (tree_1->val != tree_2->val) ) { //если потомки есть и они не равны
            return false;
        }
        return (tree_1 != nullptr && tree_2 != nullptr) && //если потомки есть
            foo(tree_1->left, tree_2->right) && //проверяем на симметрию
            foo(tree_1->right, tree_2->left); //прверяем на симметрию в другую сторону
    }
};


               root_0                                            root_0
              /      \                                          /      \
        root_1        root_1                              root_1        root_1
        /   \          /   \                              /   \          /   \
 root_2   root_3   root_2  root_3                   root_2   root_3   root_2  root_3
 несеммитрично                                      симметрично
