//
// Created by Npc on 2024/5/28.
//
#include <iostream>

using namespace std;

// 定义树节点类
class TreeNode {
public:
    int val;            // 节点值
    TreeNode* left;     // 左子节点指针
    TreeNode* right;    // 右子节点指针

    // 构造函数，初始化节点值和左右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 定义二叉排序树类
class BST {
private:
    TreeNode* root; // 树的根节点

    // 插入节点的私有递归函数
    TreeNode* insert(TreeNode* node, int val) {
        // 如果当前节点为空，则创建新节点
        if (!node) return new TreeNode(val);
        // 如果值小于当前节点值，递归插入到左子树
        if (val < node->val)
            node->left = insert(node->left, val);
        // 如果值大于当前节点值，递归插入到右子树
        else if (val > node->val)
            node->right = insert(node->right, val);
        // 返回当前节点
        return node;
    }

    // 查找节点的私有递归函数
    TreeNode* search(TreeNode* node, int val) {
        // 如果当前节点为空或节点值等于查找值，则返回当前节点
        if (!node || node->val == val) return node;
        // 如果查找值小于当前节点值，递归查找左子树
        if (val < node->val)
            return search(node->left, val);
        // 如果查找值大于当前节点值，递归查找右子树
        else
            return search(node->right, val);
    }

    // 删除节点的私有递归函数
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 如果树为空，返回空
        if (!root) return root;
        // 如果删除值小于当前节点值，递归删除左子树的节点
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        // 如果删除值大于当前节点值，递归删除右子树的节点
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        // 找到要删除的节点
        else {
            // 如果节点只有右子节点或没有子节点
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 如果节点只有左子节点
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 如果节点有两个子节点，找到右子树中的最小值节点
            TreeNode* temp = minValueNode(root->right);
            // 用最小值节点替换当前节点值
            root->val = temp->val;
            // 递归删除右子树中的最小值节点
            root->right = deleteNode(root->right, temp->val);
        }
        // 返回当前节点
        return root;
    }

    // 查找树中最小值节点的私有函数
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        // 循环查找最左叶子节点，即最小值节点
        while (current && current->left)
            current = current->left;
        return current;
    }

    // 中序遍历打印树节点值的私有递归函数
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);      // 递归遍历左子树
            cout << root->val << " "; // 打印当前节点值
            inorder(root->right);     // 递归遍历右子树
        }
    }

public:
    // 构造函数，初始化根节点为空
    BST() : root(nullptr) {}

    // 插入节点的公共函数
    void insert(int val) {
        root = insert(root, val);
    }

    // 查找节点的公共函数
    bool search(int val) {
        return search(root, val) != nullptr;
    }

    // 删除节点的公共函数
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // 中序遍历打印树节点值的公共函数
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

// 测试函数
int main() {
    BST bst;
    // 插入节点
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // 打印中序遍历结果
    cout << "Inorder traversal of the given tree: ";
    bst.inorder();

    // 删除节点并打印中序遍历结果
    cout << "\nDelete 20\n";
    bst.deleteNode(20);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    cout << "\nDelete 30\n";
    bst.deleteNode(30);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    cout << "\nDelete 50\n";
    bst.deleteNode(50);
    cout << "Inorder traversal of the modified tree: ";
    bst.inorder();

    // 查找节点
    cout << "\nSearch for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}

