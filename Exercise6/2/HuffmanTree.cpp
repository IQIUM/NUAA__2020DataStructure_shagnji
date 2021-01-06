/*** 
 * @Author         : IQIUM
 * @Date           : 2020-11-23 08:36:41
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-23 08:36:42
 * @FilePath       : \Exercise6\2\HuffmanTree.cpp
 */
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
 
//测验Deque容器
class Node
{
public:
    int weight;
    Node* left;
    Node* right;
 
    explicit Node(int weight) : weight(weight)
    {
        left = NULL;
        right = NULL;
    }
 
     explicit Node( Node& node)
    {
        this->weight = node.weight;
        this->left = node.left;
        this->right = node.right;
    }
 
    void preOrder()
    {
        cout << *this;
        if (left != NULL)
        {
            left->preOrder();
        }
        if (right != NULL)
        {
            right->preOrder();
        }
    }
 
private:
    friend ostream& operator << (ostream & cout, Node & node);
};
 
ostream& operator << (ostream & cout, Node & node)
{
    cout << "node { weight = " << node.weight << " } " << endl;
    return cout;
}
 
bool myCompare(Node* node1, Node* node2)
{
    return node1->weight < node2->weight;
}
void print(deque<Node*>& d)
{
    for (deque<Node*>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << **it << " ";
    }
    cout << endl;
}
 
deque<Node*> createNodes(int array[],int length)
{
    deque<Node*> deq;
    for (int x = 0;x < length;++x)
    {
        Node* node = new Node(array[x]);
        deq.push_back(node);
    }
    return deq;
}
 
deque<Node*> createHuffmanTree(deque<Node*> deq)
{
    while (deq.size() > 1)
    {
        sort(deq.begin(), deq.end(), myCompare);
        //print(deq);
        Node* leftNode = deq[0];
        Node* rightNode = deq[1];
 
        Node *parent = new Node(leftNode->weight + rightNode->weight);
 
        parent->left = leftNode;
        parent->right = rightNode;
 
        deq.pop_front();
        deq.pop_front();
 
        deq.push_back(parent);
    }
    //print(deq);
    return deq;
}
 
void preOrder(Node* root)
{
    if (root != NULL)
    {
        root->preOrder();
    }
    else
    {
        cout << "根结点为空!不可遍历" << endl;
    }
}
 
 
 
int main()
{
    int array[] = { 13, 7, 8, 3, 29, 6, 1 };
 
    //获取结点deque
    //deque<Node*> deq = createNodes(array,7);
 
    //deque<Node*> result = createHuffmanTree(deq);
 
    //print(result);
 
    //Node* root = result[0];
 
    //preOrder(root);
 
 
    //简化版
    preOrder(createHuffmanTree(createNodes(array, 7))[0]);
 
 
 
    return 0;
} 
