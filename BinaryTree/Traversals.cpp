#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int a){
        data=a;
        left=NULL;
        right=NULL;
    }
};

node* built_tree(node* root){
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting at left of "<<data<<endl;
    root->left = built_tree(root->left);
    cout<<"Enter data to insert at right of "<<data<<endl;
    root->right = built_tree(root->right);
    return root;
}
//<-----------------------------------PREORDER, POSTORDER AND INORDER TRAVERSAL------------------------------------------->
void preorder_traversal(node* root,vector<int>&ans){
    //node->left->right
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    preorder_traversal(root->left,ans);
    preorder_traversal(root->right,ans);
}

void postorder_traversal(node* root,vector<int>&ans){
    //left->right->node
    if(root== NULL){
        return;
    }
    postorder_traversal(root->left,ans);
    postorder_traversal(root->right,ans);
    
    ans.push_back(root->data);
}

void inorder_traversal(node* root,vector<int>&ans){
    //left->node->right
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left,ans);
    ans.push_back(root->data);
    inorder_traversal(root->right,ans);
}
//<--------------------------------------------LEVEL ORDER TRAVERSAL-------------------------------------------------------->
void level_order_traversal(node* root,vector<vector<int>>res){
    queue<node*>q;
    q.push(root);
    // q.push(NULL);
    
    // while(!q.empty()){
    //     node* temp = q.front();
    //     q.pop();
    //     if(temp == NULL){
    //         cout<<endl;
    //         if(!q.empty()) q.push(NULL);
    //     }else{
    //         cout<<temp->data<<" ";
    //         if(temp->left){
    //             q.push(temp->left);
    //         }
    //         if(temp->right){
    //             q.push(temp->right);
    //         }
    //     }
        
    // }
    while(!q.empty()){
        int size = q.size();
        vector<int>ans;
        for(int i = 0;i<size;i++){
            node* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        res.push_back(ans);
    }
}
//<-------------------------------------------ZIG ZAG TRAVERSAL--------------------------------------------->
vector<vector<int>> zigzagLevelOrder(node* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    queue<node*>q;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
        vector<int>v;
        int size = q.size();
        for(int i = 0;i<size;i++){
            node* temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(lefttoright == 0){
            ans.push_back(v);
            lefttoright = false;
        }else{
            reverse(v.begin(),v.end());
            ans.push_back(v);
            lefttoright = true;
        }
        
    }
    return ans;
}

//<----------------------------------BOUNDARY ORDER TRAVERSAL-------------------------------------------->
void traverseLeft(node* root,vector<int>&ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
    
    ans.push_back(root->data);
    if(root->left)  traverseLeft(root->left,ans);
    else traverseLeft(root->right,ans);
}

void traverseLeaf(node* root, vector<int>&ans){
    if(root == NULL){
        return;
    }    
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root, vector<int>&ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
    
    if(root->right) traverseRight(root->right,ans);
    else traverseRight(root->left,ans);
    
    ans.push_back(root->data);
}

vector <int> boundary(node *root){
    vector<int>ans;
    if(root== NULL) return ans;
    
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    
    traverseRight(root->right,ans);
    
    return ans;
}

//<-------------------------------------VERTICAL ORDER TRAVERSAL------------------------------>

vector<vector<int>> verticalTraversal(node* root) {
    //creating a maping of horizontal distance with levelwise nodes(map of level with nodes)
    map<int,map<int,vector<int> > >mp;
    // for level order traversal creating a queue of nodes,hd and level
    queue<pair<node*,pair<int,int>>>q;
    vector<vector<int>>ans;
    if(root== NULL) return ans;
    
    q.push({root,{0,0}});
    while(!q.empty()){
        pair<node*,pair<int,int>> temp = q.front(); // node, horizontal distance aand level
        q.pop();
        node* front = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        mp[hd][lvl].push_back(front->data);
        if(front->left){
            q.push({front->left,{hd-1,lvl+1}});
        }
        if(front->right){
            q.push({front->right,{hd+1,lvl+1}});
        }
    }
    for(auto  i : mp){
        vector<int>v;
        for(auto j : i.second){
            sort(j.second.begin(),j.second.end());
            v.insert(v.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(v);
    }

    return ans;
}

//<----------------------------------TOP VIEW OF BINARY TREE--------------------------------->
vector<int> topView(node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    
    map<int,int>mp;
    queue<pair<node*,int> >q;
    q.push({root,0});
    
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;
        
        if(mp.find(hd) == mp.end()){
            mp[hd] = frontnode->data;
        }
        if(frontnode->left) q.push({frontnode->left,hd-1});
        if(frontnode->right) q.push({frontnode->right,hd+1});
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
}

//<---------------------------------BOTTOM VIEW OF BINARY TREE------------------------------------>
vector <int> bottomView(node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    //mapping between hd and value of the node
    map<int,int>mp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        pair<node*,int>temp = q.front();
        q.pop();
        
        node* frontnode = temp.first;
        int hd = temp.second;
        
        mp[hd] = frontnode->data;
        if(frontnode->left) q.push({frontnode->left,hd-1});
        if(frontnode->right) q.push({frontnode->right,hd+1});
        
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}

//<---------------------------------------LEFT VIEW OF A BINARY TREE-------------------------------------------->
void rightview(node* root, int lvl, vector<int>&ans){
    if(root==NULL) return;

    if(lvl == ans.size()) ans.push_back(root->data);
    rightview(root->left,lvl+1,ans);
    rightview(root->right,lvl+1,ans);
}

vector<int> rightSideView(node* root) {
    vector<int>ans;
    if(root==NULL) return ans;
    rightview(root,0,ans);
    return ans;
}
//<---------------------------------------RIGHT VIEW OF A BINARY TREE-------------------------------------------->
void rightview(node* root, int lvl, vector<int>&ans){
    if(root==NULL) return;

    if(lvl == ans.size()) ans.push_back(root->data);
    rightview(root->right,lvl+1,ans);
    rightview(root->left,lvl+1,ans);
}

vector<int> rightSideView(node* root) {
    vector<int>ans;
    if(root==NULL) return ans;
    rightview(root,0,ans);
    return ans;
}

//<-------------------------------------LOWEST COMMON ANSECTOR IN A BINARY TREE-------------------------------------->
node* lowestCommonAncestor(node* root, node* p, node* q) {
    if(root==NULL || root == p || root == q) return root;

    node* leftans = lowestCommonAncestor(root->left,p,q);
    node* rightans = lowestCommonAncestor(root->right,p,q);

    if(leftans == NULL) return rightans;
    else if(rightans == NULL) return leftans;
    else return root;
}

int main()
{
    node* root =NULL;
    root = built_tree(root);
    vector<int>ans;
    vector<vector<int>>res;
    cout<<"Postorder Traversal"<<endl;
    postorder_traversal(root,ans);
    cout<<endl;
    cout<<"Preorder Traversal"<<endl;
    preorder_traversal(root,ans);
    cout<<endl;
    cout<<"Inorder Traversal"<<endl;
    inorder_traversal(root,ans);
    cout<<endl;
    cout<<"Level Order Traversal"<<endl;
    level_order_traversal(root,res);

    return 0;
}
