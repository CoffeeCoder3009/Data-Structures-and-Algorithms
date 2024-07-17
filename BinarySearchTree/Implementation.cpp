#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
//<------------------------------------INSERT A NODE-------------------------------------------->
node* insertIntoBST(node* root, int val) {
    node* newnode = new node(val);
    if(root == NULL){
        root = newnode;
        return root;
    }
    if(root->data > val){
        root->left = insertIntoBST(root->left, val);
    }
    if(root->data < val){
        root->right = insertIntoBST(root->right, val);
    }

    return root;

}

//<-----------------------------------DELETE A NODE--------------------------------------->
node* findmax(node* root){
    while(root != NULL && root->right!=NULL){
        root = root->right;
    }
    return root;
}
node* findmin(node* root){
    while(root != NULL && root->left!=NULL){
        root= root->left;
    }
    return root;
}
node* deleteNode(node* root, int key) {
    if(root==NULL) return root;
    if(root->data == key){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        //1 child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete(root);
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete(root);
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right != NULL){
            node* mini = findmin(root->right);
            root->data = mini->data;
            root->right = deleteNode(root->right,mini->data);
            return root;
            // int maxi = findmax(root->left)->val;
            // root->val = maxi;
            // root->left = deleteNode(root->left,maxi);
            // return root;

        }
    }else if(root->data > key){
        root->left = deleteNode(root->left,key);
        return root;
    }else{
        root->right = deleteNode(root->right,key);
        return root;
    }
    return NULL;
}

//<--------------------------------------------------SEARCH IN A BST---------------------------------------------->
node* searchBST(node* root, int val) {
    if(root == NULL) return NULL;

    if(root->data > val) return searchBST(root->left,val);
    if(root->data < val) return searchBST(root->right,val);
    else return root;
}

//<--------------------------------------LOWEST COMMON ANSECTOR IN A BST--------------------------------------------->
node* lowestCommonAncestor(node* root,node* p,node* q) {
    if(root == NULL) return NULL;
    if(root->data > p->data && root->data > q->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    if(root->data < p->data && root->data < q->data){
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
}

int main(){

    return 0;
}
