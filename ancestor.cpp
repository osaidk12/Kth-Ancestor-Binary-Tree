#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


bool findKthAncestor(TreeNode* root, int target, int& k, int& ancestor) {
    if (root == nullptr) return false;


    if (root->data == target) {
        k--;
        return true;
    }


    if (findKthAncestor(root->left, target, k, ancestor)) {
        if (k == 0) {
            ancestor = root->data;
        }
        k--;
        return true;
    }


    if (findKthAncestor(root->right, target, k, ancestor)) {
        if (k == 0) {
            ancestor = root->data;
        }
        k--;
        return true;
    }

    return false;
}


int kthAncestor(TreeNode* root, int target, int k) {
    int ancestor = -1;
    findKthAncestor(root, target, k, ancestor);
    return ancestor;
}


TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    int target = 5;
    int k = 2;
    int result = kthAncestor(root, target, k);

    if (result != -1) {
        cout<<"The "<<k<<"th ancestor of node "<<target<<" is: "<<result<<endl;
    } else {
        cout<<"The "<<k<<"th ancestor of node "<<target<<" does not exist."<<endl;
    }

    return 0;
}
