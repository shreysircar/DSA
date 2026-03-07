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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int, map<int, multiset<int>>> nodes;

        // A queue is used for BFS, storing node and its coordinates
        queue<pair<TreeNode*, pair<int, int>>> todo;

        // Push the root node with vertical = 0 and level = 0
        todo.push({root, {0, 0}});

        // Perform BFS traversal
        while (!todo.empty()) {
            // Get the front element in queue
            auto p = todo.front();
            todo.pop();

            // Extract node
            TreeNode* temp = p.first;
            // Extract vertical (x)
            int x = p.second.first;
            // Extract level (y)
            int y = p.second.second;

            // Insert the node into map by vertical and level
            nodes[x][y].insert(temp->val);

            // If left child exists, push with updated coordinates
            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // If right child exists, push with updated coordinates
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Final answer vector
        vector<vector<int>> ans;

        // Iterate through verticals in map
        for (auto p : nodes) {
            vector<int> col;
            // Collect all nodes in order of levels
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Push the column into result
            ans.push_back(col);
        }

        // Return final vertical order traversal
        return ans;
    }

int main(){
    TreeNode* root = buildTree();

    printTree(root);

    vector<vector<int>> ans = verticalTraversal(root);

    cout << "\nVertical Traversal:\n";
    for (auto &level : ans) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
  return 0;}
