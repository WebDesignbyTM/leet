#include <iostream>
#include <vector>
using namespace std;

#define MIN_SUM -1000000001

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> sums;

    void addValues(TreeNode* node, int level) {
        if (node == nullptr)
            return;

        if (level > sums.size())
            sums.push_back(0);
        
        sums[level-1] += node->val;

        addValues(node->left, level + 1);
        addValues(node->right, level + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        addValues(root, 1);
        int max = MIN_SUM;
        int level = 0;

        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > max) {
                max = sums[i];
                level = i + 1;
            }
        }

        return level;
    }
};

int main() {
    cout << "hihi";
    return 0;
}