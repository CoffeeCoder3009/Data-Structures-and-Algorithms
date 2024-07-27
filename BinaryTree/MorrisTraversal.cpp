#include<iostream>
#include<vector>

using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

//<-------------------------------------------------MORRIS INORDER TRAVERSAL--------------------------------------------->
vector<int> inorderTraversal(TreeNode* root) {
    // traversal with space complexity as O(1) as it uses concept of threaded binary tree
    TreeNode* curr = root;
    vector<int>inorder;

    while(curr != NULL){
        if(curr->left == NULL){
            //no left, move towards the right subtree
            inorder.push_back(curr->val);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            //move to the end to connect a thread with the curr node
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            // connecting a thread
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                // cut the thread if prev->right == curr
                prev->right = NULL;
                inorder.push_back(curr->val);
                //move to the right
                curr = curr->right;
            }
        }
    }
    return inorder;
}

//<----------------------------------------MORRIS PREORDER TRAVERSAL---------------------------------------------------->
vector<int> preorderTraversal(TreeNode* root) {
    // traversal with space complexity as O(1) as it uses concept of threaded binary tree
    TreeNode* curr = root;
    vector<int>preorder;

    while(curr != NULL){
        if(curr->left == NULL){
            //no left, move towards the right subtree
            preorder.push_back(curr->val);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            //move to the end to connect a thread with the curr node
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            // connecting a thread
            // while marking a thread push the node in vector, as this is the root node of preorder traversal(root,left,right)
            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }else{
                // cut the thread if prev->right == curr
                prev->right = NULL;
                //move to the right
                curr = curr->right;
            }
        }
    }
    return preorder;
}
