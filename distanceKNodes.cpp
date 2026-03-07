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

 unordered_map<TreeNode*, TreeNode*> parent;
    void addParent(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
            parent[root->left] = root;
        
        addParent(root->left);
        
        if(root->right)
            parent[root->right] = root;
        
        addParent(root->right);
    }
    
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParent(root);
        
        collectKDistanceNodes(target, k, result);
        return result;
    }
int main(){
    TreeNode* root = buildTree();

    printTree(root);
//cout<<"width of binary tree"<<widthOfBinaryTree(root);

return 0;}
