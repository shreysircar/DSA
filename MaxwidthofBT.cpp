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

    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,int>>q; //(val,index) 
        int width=INT_MIN;
       q.push({root,0});
       while(!q.empty()){
            int size=q.size();
        int l=q.front().second;
        int r=q.back().second;
width=max(width,l-r+1);
 for (int i=0;i<size;i++) {
        auto [node,index]=q.front();
        q.pop();
        index-=l; // normalize
        if (node->left)
            q.push({node->left, 2 * index + 1});
        if (node->right)
            q.push({node->right, 2 * index + 2});
    }

       }
       return width;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    }

int main(){
    TreeNode* root = buildTree();

    printTree(root);
cout<<"width of binary tree"<<widthOfBinaryTree(root);

return 0;}
