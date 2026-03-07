#include <bits/stdc++.h>
using namespace std;
 class TreeNode {
  public:
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
TreeNode* buildTree() {
    cout << "Enter values in level order (-1 for NULL):\n";
    int val;
    cin >> val;

    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;

        if (!(cin >> leftVal)) break;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        if (!(cin >> rightVal)) break;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}


void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "\nTree (Level Order):\n";

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << endl;
    }
}

TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx){
if(start>end){return NULL;}
int rootVal=preorder[idx];
int i=start;
for(;i<preorder.size();i++){
    if(inorder[i]==rootVal){break;}
}
idx++;
TreeNode* root=new TreeNode(rootVal);
root->left=solve(preorder,inorder,start,i-1,idx);
root->right=solve(preorder,inorder,i+1,end,idx);
return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);
    }
	

     TreeNode* buildBT(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int root_candidate = root->val;
        int i = inStart;
      
        //YOu can optimize this by storing index of inorder values in a map for direct access
        for(; i<=inEnd; i++) {
            if(inorder[i] == root_candidate) {
                break;
            }
        }
        int leftSize  = i-inStart;
        int rightSize = inEnd-i;
      
        root->left = buildBT(inorder, postorder, inStart, i-1, postStart, postStart+leftSize-1);
        root->right  = buildBT(inorder, postorder, i+1, inEnd, postEnd-rightSize, postEnd-1);
      
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        int n          = postorder.size();
        int inStart    = 0;
        int inEnd      = n-1;
        int postStart  = 0;
        int postEnd    = n-1;
        root           = buildBT(inorder, postorder, inStart, inEnd, postStart, postEnd);
        return root;
    }

int main(){
    TreeNode* root = buildTree();

    printTree(root);

return 0;}
