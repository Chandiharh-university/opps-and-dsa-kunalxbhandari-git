#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root) {
            findPaths(root, "", paths);
        }
        return paths;
    }

private:
    void findPaths(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;

        // Append current node value to path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf node, add the path to the result
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }

        // Recurse on left and right child
        if (node->left) findPaths(node->left, path, paths);
        if (node->right) findPaths(node->right, path, paths);
    }
};

// Helper function to build a tree from a vector representation
TreeNode* buildTree(const vector<int*>& nodes) {
    if (nodes.empty() || !nodes[0]) return nullptr;

    vector<TreeNode*> treeNodes;
    for (auto val : nodes) {
        treeNodes.push_back(val ? new TreeNode(*val) : nullptr);
    }

    for (size_t i = 0, j = 1; j < treeNodes.size(); ++i) {
        if (treeNodes[i]) {
            if (j < treeNodes.size()) treeNodes[i]->left = treeNodes[j++];
            if (j < treeNodes.size()) treeNodes[i]->right = treeNodes[j++];
        }
    }

    return treeNodes[0];
}

int main() {
    // Example input
    vector<int*> nodes = {new int(1), new int(2), new int(3), nullptr, new int(5)};
    TreeNode* root = buildTree(nodes);

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);

    // Output results
    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : result) {
        cout << path << endl;
    }

    // Cleanup dynamically allocated nodes
    for (auto val : nodes) {
        if (val) delete val;
    }

    return 0;
}
