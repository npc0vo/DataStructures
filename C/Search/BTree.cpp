#include <iostream>
#include <vector>

using namespace std;

// B树的节点类
class BTreeNode {
public:
    vector<int> keys;       // 存储键值
    vector<BTreeNode*> children;  // 存储子节点指针
    int t;                  // 最小度数
    bool leaf;              // 是否为叶子节点

    // 构造函数
    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

    // 插入键值到非满节点
    void insertNonFull(int k);

    // 分裂子节点
    void splitChild(int i, BTreeNode* y);

    // 查找键值
    BTreeNode* search(int k);

    // 打印B树
    void traverse();

    // 获取索引为idx的前驱
    int getPred(int idx);

    // 获取索引为idx的后继
    int getSucc(int idx);

    // 从兄弟节点借键值
    void fill(int idx);

    // 从前一个兄弟节点借键值
    void borrowFromPrev(int idx);

    // 从后一个兄弟节点借键值
    void borrowFromNext(int idx);

    // 合并节点
    void merge(int idx);

    // 删除键值
    void remove(int k);

    // 删除非叶子节点的键值
    void removeFromNonLeaf(int idx);

    // 删除叶子节点的键值
    void removeFromLeaf(int idx);

    // 查找键值的位置
    int findKey(int k);
};

// B树类
class BTree {
public:
    BTreeNode* root; // 树的根节点
    int t;           // 最小度数

    // 构造函数
    BTree(int _t) : t(_t), root(nullptr) {}

    // 插入键值
    void insert(int k);

    // 查找键值
    BTreeNode* search(int k);

    // 删除键值
    void remove(int k);

    // 打印B树
    void traverse() {
        if (root) root->traverse();
    }
};

// BTreeNode类成员函数实现

// 中序遍历B树
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf) {
            children[i]->traverse();  // 递归遍历子树
        }
        cout << " " << keys[i];        // 打印键值
    }
    if (!leaf) {
        children[i]->traverse();      // 递归遍历最后一个子树
    }
}

// 在B树中搜索键值
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < keys.size() && k > keys[i]) {
        i++;
    }
    if (i < keys.size() && keys[i] == k) {
        return this;                  // 找到键值，返回当前节点
    }
    if (leaf) {
        return nullptr;               // 如果是叶子节点且未找到，返回空
    }
    return children[i]->search(k);    // 递归搜索子树
}

// 在B树中插入键值
void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(t, true);  // 如果树为空，创建根节点
        root->keys.push_back(k);        // 插入键值
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);  // 如果根节点满了，分裂根节点
            s->children.push_back(root);             // 新根节点指向旧根节点
            s->splitChild(0, root);                  // 分裂旧根节点
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            s->children[i]->insertNonFull(k);        // 插入键值到适当子树
            root = s;                                // 更新根节点
        } else {
            root->insertNonFull(k);                  // 根节点未满，直接插入
        }
    }
}

// 插入键值到非满节点
void BTreeNode::insertNonFull(int k) {
    int i = keys.size() - 1;
    if (leaf) {
        keys.push_back(0);              // 为新键值腾出空间
        while (i >= 0 && keys[i] > k) { // 找到插入位置
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;                // 插入键值
    } else {
        while (i >= 0 && keys[i] > k) {
            i--;
        }
        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);  // 子节点满了，分裂子节点
            if (keys[i + 1] < k) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(k);  // 递归插入键值到子节点
    }
}

// 分裂子节点
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);  // 创建新节点
    for (int j = 0; j < t - 1; j++) {
        z->keys.push_back(y->keys[j + t]);       // 拷贝键值到新节点
    }
    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->children.push_back(y->children[j + t]);  // 拷贝子节点指针到新节点
        }
    }
    y->keys.resize(t - 1);  // 缩减原节点的键值数
    y->children.resize(t);  // 缩减原节点的子节点数
    children.insert(children.begin() + i + 1, z);  // 插入新子节点指针
    keys.insert(keys.begin() + i, y->keys[t - 1]);  // 提升键值到父节点
}

// 从B树中删除键值
void BTree::remove(int k) {
    if (!root) {
        cout << "树是空的\n";
        return;
    }
    root->remove(k);
    if (root->keys.size() == 0) {  // 如果根节点为空，更新根节点
        BTreeNode* tmp = root;
        if (root->leaf) {
            root = nullptr;
        } else {
            root = root->children[0];
        }
        delete tmp;
    }
}

// 从节点中删除键值
void BTreeNode::remove(int k) {
    int idx = findKey(k);
    if (idx < keys.size() && keys[idx] == k) {  // 找到键值
        if (leaf) {
            removeFromLeaf(idx);  // 如果是叶子节点，直接删除
        } else {
            removeFromNonLeaf(idx);  // 如果是非叶子节点，删除非叶子节点的键值
        }
    } else {
        if (leaf) {
            cout << "键值 " << k << " 不在树中\n";
            return;
        }
        bool flag = (idx == keys.size());
        if (children[idx]->keys.size() < t) {
            fill(idx);  // 如果子节点键值数小于t，填充子节点
        }
        if (flag && idx > keys.size()) {
            children[idx - 1]->remove(k);  // 如果最后一个子节点被合并，递归删除
        } else {
            children[idx]->remove(k);  // 递归删除键值
        }
    }
}

// 从叶子节点删除键值
void BTreeNode::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

// 从非叶子节点删除键值
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];
    if (children[idx]->keys.size() >= t) {  // 如果前驱子节点有足够的键值
        int pred = getPred(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->keys.size() >= t) {  // 如果后继子节点有足够的键值
        int succ = getSucc(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);  // 合并子节点并删除键值
        children[idx]->remove(k);
    }
}

// 获取索引为idx的前驱
int BTreeNode::getPred(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->leaf) {
        cur = cur->children[cur->keys.size()];
    }
    return cur->keys[cur->keys.size() - 1];
}
// 获取索引为idx的后继
int BTreeNode::getSucc(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->leaf) {
        cur = cur->children[0];
    }
    return cur->keys[0];
}

// 从兄弟节点借键值
void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t) {
        borrowFromPrev(idx);  // 如果前一个兄弟节点有足够的键值，从前一个兄弟节点借键值
    } else if (idx != keys.size() && children[idx + 1]->keys.size() >= t) {
        borrowFromNext(idx);  // 如果后一个兄弟节点有足够的键值，从后一个兄弟节点借键值
    } else {
        if (idx != keys.size()) {
            merge(idx);  // 如果前后兄弟节点都没有足够的键值，合并当前节点和后一个兄弟节点
        } else {
            merge(idx - 1);  // 如果当前节点是最后一个节点，合并当前节点和前一个兄弟节点
        }
    }
}

// 从前一个兄弟节点借键值
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];
    for (int i = child->keys.size() - 1; i >= 0; i--) {
        child->keys[i + 1] = child->keys[i];  // 将当前节点的键值右移
    }
    if (!child->leaf) {
        for (int i = child->children.size() - 1; i >= 0; i--) {
            child->children[i + 1] = child->children[i];  // 将当前节点的子节点指针右移
        }
    }
    child->keys[0] = keys[idx - 1];  // 将父节点的键值下移到当前节点
    if (!child->leaf) {
        child->children[0] = sibling->children[sibling->children.size() - 1];  // 将兄弟节点的最后一个子节点指针移到当前节点的第一个位置
    }
    keys[idx - 1] = sibling->keys[sibling->keys.size() - 1];  // 将兄弟节点的最后一个键值上移到父节点
    sibling->keys.pop_back();  // 删除兄弟节点的最后一个键值
    if (!sibling->leaf) {
        sibling->children.pop_back();  // 删除兄弟节点的最后一个子节点指针
    }
}

// 从后一个兄弟节点借键值
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);  // 将父节点的键值下移到当前节点
    if (!child->leaf) {
        child->children.push_back(sibling->children[0]);  // 将兄弟节点的第一个子节点指针移到当前节点的最后一个位置
    }
    keys[idx] = sibling->keys[0];  // 将兄弟节点的第一个键值上移到父节点
    sibling->keys.erase(sibling->keys.begin());  // 删除兄弟节点的第一个键值
    if (!sibling->leaf) {
        sibling->children.erase(sibling->children.begin());  // 删除兄弟节点的第一个子节点指针
    }
}

// 合并节点
void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];
    child->keys.push_back(keys[idx]);  // 将父节点的键值下移到当前节点
    for (int i = 0; i < sibling->keys.size(); i++) {
        child->keys.push_back(sibling->keys[i]);  // 将兄弟节点的键值全部移到当前节点
    }
    if (!child->leaf) {
        for (int i = 0; i < sibling->children.size(); i++) {
            child->children.push_back(sibling->children[i]);  // 将兄弟节点的子节点指针全部移到当前节点
        }
    }
    keys.erase(keys.begin() + idx);  // 删除父节点的键值
    children.erase(children.begin() + idx + 1);  // 删除父节点的子节点指针
    delete sibling;  // 释放兄弟节点的内存
}

// 查找键值的位置
int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < keys.size() && keys[idx] < k) {
        ++idx;
    }
    return idx;  // 返回键值的位置
}

// 测试B树
int main() {
    BTree t(3); // 创建一个最小度数为3的B树
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "构建的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(6);
    cout << "删除6后的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(13);
    cout << "删除13后的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(7);
    cout << "删除7后的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(4);
    cout << "删除4后的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(2);
    cout << "删除2后的树的遍历: ";
    t.traverse();
    cout << endl;

    t.remove(16);
    cout << "删除16后的树的遍历: ";
    t.traverse();
    cout << endl;
    system("pause");
    return 0;
}
