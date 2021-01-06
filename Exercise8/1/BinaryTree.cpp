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
        cout << "δ�ҵ���ֵ��" << endl;
        return;
    }
    Node *parent = searchParent(root, key);
    if (target->left == NULL && target->right == NULL) {
        /* 1. ��ɾ���ڵ���Ҷ�ӽڵ� */
        if (parent == NULL) {
            /* ������ڵ���Ҷ�ӽڵ� */
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
        /* 2. ��ɾ���ڵ�����������,ѭ���������е����ֵ�滻 */
        Node *leftMax = findLeftMaxNode(target->left);
        Node *parent_leftmax = searchParent(target, leftMax->data);

        /* �����ɾ���Ľڵ��Ǹ��ڵ� */
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
        /* 3. ��ɾ���ڵ�ֻ��һ������ */
        if (parent == NULL) {
            /* ˵���Ǹ��ڵ� */
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
 * @description: Ѱ���������е����ֵ
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
            cout << "\n�� " << cur_level << " �㣺  ";
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
    cout << "���������빹�������������ڵ������  ";
    int n = 0;
    cin >> n;
    cout << "���������� " << n << " ������ ��  ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        insert(root, key);
    }
    cout << "\n\t������ϣ�" << endl;
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
    cout << "\t��ʼ�������������� " << endl;
    bt->init();
    while (1) {
        cout << "\n������"
                "\n\t1.����\n\t2.ɾ��\n\t3.����\n\t4.�˳�\n����������ţ�  ";
        int num;
        cin >> num;
        switch (num) {
        case 1: {
            cout << "\n������Ҫ�����ֵ: \n\t";
            int value = 0;
            cin >> value;
            bt->insert(value);
            break;
        }
        case 2: {
            cout << "\n������Ҫɾ����ֵ: " << endl;
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
            cout << "\tллʹ�ã�" << endl;
            exit(0);
        }
        default:
            break;
        }
    }

    return 0;
}