#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int data = 0) : data(data), left(NULL), right(NULL) {}
};

class BinaryTree {
  public:
    Node *root;
    void init();
    void insert(int key);
    void insert(Node *&node, int key);
    Node *search(Node *node, int key);
    void level_traverse();
    void infixOrder(Node *node);
    void infixOrder();
    void remove(int key);
    Node *searchParent(Node *node, int key);
    Node *findLeftMaxNode(Node *node);
};
void BinaryTree::infixOrder() { infixOrder(root); }
void BinaryTree::infixOrder(Node *node) {
    if (node != NULL) {
        infixOrder(node->left);
        cout << node->data << " ";
        infixOrder(node->right);
    }
}

void BinaryTree::remove(int key) {
    Node *target = search(root, key);
    if (target == NULL) {
        cout << "未找到该值！" << endl;
        return;
    }
    Node *parent = searchParent(root, key);
    if (target->left == NULL && target->right == NULL) {
        /* 1. 待删除节点是叶子节点 */
        if (parent == NULL) {
            /* 如果根节点是叶子节点 */
            delete root;
            root = NULL;
            return;
        }
        if (parent->left == target) {
            parent->left = NULL;
        } else if (parent->right == target) {
            parent->right = NULL;
        }
        delete target;
        return;
    } else if (target->left != NULL && target->right != NULL) {
        /* 2. 待删除节点有两个孩子,循环左子树中的最大值替换 */
        Node *leftMax = findLeftMaxNode(target->left);
        Node *parent_leftmax = searchParent(target, leftMax->data);

        /* 如果待删除的节点是根节点 */
        if (parent == NULL) {

            // Node *tmp = parent_leftmax->right;
            if (leftMax == parent_leftmax->left) {
                parent_leftmax->left = leftMax->left;
            } else if (leftMax == parent_leftmax->right) {
                parent_leftmax->right = leftMax->left;
            }

            // parent_leftmax->right = leftMax->left;
            leftMax->left = target->left;
            leftMax->right = target->right;
            root = leftMax;
        } else if (target == parent->left) {
            Node *tmp = parent_leftmax->right;
            if (leftMax == parent_leftmax->left) {
                parent_leftmax->left = leftMax->left;
            } else if (leftMax == parent_leftmax->right) {
                parent_leftmax->right = leftMax->left;
            }
            parent->left = leftMax;
            leftMax->left = target->left;
            leftMax->right = tmp;
        } else if (target == parent->right) {
            Node *tmp = parent_leftmax->right;
            if (leftMax == parent_leftmax->left) {
                parent_leftmax->left = leftMax->left;
            } else if (leftMax == parent_leftmax->right) {
                parent_leftmax->right = leftMax->left;
            }
            parent->right = leftMax;
            leftMax->left = target->left;
            leftMax->right = tmp;
        }
        delete target;
        return;
    } else {
        /* 3. 待删除节点只有一个孩子 */
        if (parent == NULL) {
            /* 说明是根节点 */
            Node *p = (root->left != NULL) ? root->left : root->right;
            delete root;
            root = p;
            return;
        }
        if (parent->left == target) {
            if (target->left != NULL) {
                parent->left = target->left;
            } else if (target->right != NULL) {
                parent->left = target->right;
            }
            delete target;
        } else if (parent->right == target) {
            if (target->left != NULL) {
                parent->right = target->left;
            } else if (target->right != NULL) {
                parent->right = target->right;
            }
            delete target;
        }
        return;
    }
}

/**
 * @description: 寻找左子树中的最大值
 */
Node *BinaryTree::findLeftMaxNode(Node *node) {
    Node *p = node;
    if (p == NULL) {
        return NULL;
    }
    while (p->right != NULL) {
        p = p->right;
    }
    return p;
}

void BinaryTree::level_traverse() {
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    int pre_level = -1;
    while (!q.empty()) {
        Node *front = q.front().first;
        int cur_level = q.front().second;
        q.pop();
        if (pre_level != cur_level) {
            cout << "\n第 " << cur_level << " 层：  ";
            pre_level = cur_level;
        }
        cout << front->data << "  ";
        if (front->left != NULL) {
            q.push(make_pair(front->left, cur_level + 1));
        }
        if (front->right != NULL) {
            q.push(make_pair(front->right, cur_level + 1));
        }
    }
    cout << endl;
}

void BinaryTree::init() {
    cout << "请输入你想构建二叉排序树节点个数：  ";
    int n = 0;
    cin >> n;
    cout << "请依次输入 " << n << " 个整数 ：  ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        insert(root, key);
    }
    cout << "\n\t构建完毕！" << endl;
}

void BinaryTree::insert(int key) { insert(root, key); }

void BinaryTree::insert(Node *&node, int key) {
    if (node == NULL) {
        node = new Node(key);
        return;
    }
    if (key < node->data) {
        insert(node->left, key);
    } else if (key > node->data) {
        insert(node->right, key);
    }
}

Node *BinaryTree::search(Node *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == key) {
        return node;
    } else if (key < node->data) {
        return search(node->left, key);
    } else if (key > node->data) {
        return search(node->right, key);
    }
}

Node *BinaryTree::searchParent(Node *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left != NULL && node->left->data == key) {
        return node;
    } else if (node->right != NULL && node->right->data == key) {
        return node;
    }
    if (key < node->data) {
        return searchParent(node->left, key);
    } else if (key > node->data) {
        return searchParent(node->right, key);
    }
    return NULL;
}

void test(BinaryTree *bt) {
    cout << bt->searchParent(bt->root, 1)->data << endl;
}

int main() {
    BinaryTree *bt = new BinaryTree();
    cout << "\t初始化二叉排序树！ " << endl;
    bt->init();
    while (1) {
        cout << "\n请输入"
                "\n\t1.插入\n\t2.删除\n\t3.遍历\n\t4.退出\n上述操作序号：  ";
        int num;
        cin >> num;
        switch (num) {
        case 1: {
            cout << "\n请输入要插入的值: \n\t";
            int value = 0;
            cin >> value;
            bt->insert(value);
            break;
        }
        case 2: {
            cout << "\n请输入要删除的值: " << endl;
            int value = 0;
            cin >> value;
            bt->remove(value);
            break;
        }
        case 3: {
            bt->infixOrder();
            cout << endl;
            break;
        }
        case 4: {
            cout << "\t谢谢使用！" << endl;
            exit(0);
        }
        default:
            break;
        }
    }

    return 0;
}