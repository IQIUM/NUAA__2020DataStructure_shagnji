/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-23 08:52:47
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-26 10:41:55
 * @FilePath       : \Exercise6\3\calculatorWidth.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data = 0, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};

queue<pair<Node *, int> > que; /* 用于存储节点及其所在的层数 */

/* 创建二叉树 */
void createBiTree(Node *&root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ' || ch == '0' || ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = new Node(ch - '0');
        createBiTree(root->left);
        createBiTree(root->right);
    }
}

Node *root = NULL;

/*** 
 * @description: 层次遍历计算宽度
 */
int levelTraverseCalculatorWidth()
{
    que.push(make_pair(root, 1));
    int lastLevel = 1; /* 记录上一次的level */
    int count = 0;
    int maxWidth = INT_MIN;
    while (!que.empty())
    {
        Node *tmp = que.front().first;
        int level = que.front().second;
        que.pop();
        if (lastLevel == level)
        {
            count++;
        }
        else
        {
            if (count > maxWidth)
            {
                maxWidth = count;
            }
            lastLevel = level;
            count = 1;
        }

        if (tmp->left != NULL)
        {
            que.push(make_pair(tmp->left, level + 1));
        }
        if (tmp->right != NULL)
        {
            que.push(make_pair(tmp->right, level + 1));
        }
    }
    return maxWidth;
}

int main()
{
    /* 测试用例：124#8##5##36##2#9## */
    printf("请输入二叉树：  ");
    createBiTree(root);
    printf("此二叉树的宽度为：  %d", levelTraverseCalculatorWidth());
    return 0;
}