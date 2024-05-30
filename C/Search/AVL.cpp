#include <iostream>

using namespace std;

// 定义树节点类
class TreeNode {
public:
    int val;            // 节点值
    TreeNode* left;     // 左子节点指针
    TreeNode* right;    // 右子节点指针
    int height;         // 节点高度

    // 构造函数，初始化节点值和左右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

// 定义AVL树类
class AVLTree {
private:
    TreeNode* root; // 树的根节点

    // 获取节点高度
    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    // 获取平衡因子
    int getBalance(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // 右旋转
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // 进行旋转
        x->right = y;
        y->left = T2;

        // 更新高度
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // 返回新的根节点
        return x;
    }

    // 左旋转
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // 进行旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // 返回新的根节点
        return y;
    }

    // 插入节点的私有递归函数
    TreeNode* insert(TreeNode* node, int val) {
        // 1. 执行普通的BST插入操作
        if (!node) return new TreeNode(val);
        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);
        else
            return node;

        // 2. 更新节点的高度
        node->height = 1 + max(height(node->left), height(node->right));

        // 3. 获取节点的平衡因子
        int balance = getBalance(node);

        // 4. 检查是否需要进行旋转以保持AVL树的平衡

        // 左左情况
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 查找节点的私有递归函数
    TreeNode* search(TreeNode* node, int val) {
        if (!node || node->val == val)
            return node;
        if (val < node->val)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // 查找树中最小值节点的私有函数
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    // 删除节点的私有递归函数
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. 执行标准的BST删除操作
        if (!root)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        // 2. 如果树中只有一个节点，直接返回
        if (!root)
            return root;

        // 3. 更新节点的高度
        root->height = 1 + max(height(root->left), height(root->right));

        // 4. 获取节点的平衡因子
        int balance = getBalance(root);

        // 5. 检查是否需要进行旋转以保持AVL树的平衡

        // 左左情况
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // 左右情况
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // 右右情况
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // 右左情况
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
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
    AVLTree() : root(nullptr) {}

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
    AVLTree avl;

    // 插入节点
    avl.insert(50);
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(70);
    avl.insert(60);
    avl.insert(80);

    // 打印中序遍历结果
    cout << "Inorder traversal of the given tree: ";
    avl.inorder();

    // 删除节点并打印中序遍历结果
    cout << "\nDelete 20\n";
    avl.deleteNode(20);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    cout << "\nDelete 30\n";
    avl.deleteNode(30);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    cout << "\nDelete 50\n";
    avl.deleteNode(50);
    cout << "Inorder traversal of the modified tree: ";
    avl.inorder();

    // 查找节点
    cout << "\nSearch for 40: " << (avl.search(40) ? "Found" : "Not Found") << endl;
    system("pause");
    return 0;
}
