#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void it(Node *root)
{
    if (!root)
        return;
    stack<Node *> ans;
    while (root or !ans.empty())
    {
        while (root)
        {
            cout << root->data << " ";
            ans.push(root);
            root = root->left;
        }
        root = ans.top();
        ans.pop();
        root = root->right;
    }
}
void rightview(Node *root)
{
    vector<int> view;
    if (!root)
        return;
    vector<int> count;
    queue<Node *> s;
    s.push(root);
    s.push(nullptr);
    view.push_back(root->data);
    while (!s.empty())
    {
        Node *cuur = s.front();
        s.pop();
        if (!cuur)
        {
            if (count.size())
                view.push_back(count.back());
            s.push(nullptr);
            count.clear();
            if (s.empty())
                break;
            continue;
        }
        if (cuur->left)
        {
            s.push(cuur->left);
            count.push_back(cuur->left->data);
        }
        if (cuur->right)
        {
            s.push(cuur->right);
            count.push_back(cuur->right->data);
        }
    }
    for (auto i : view)
        cout << i << " ";
}
void leftview(Node *root)
{
    vector<int> view;
    if (!root)
        return;
    vector<int> count;
    queue<Node *> s;
    s.push(root);
    s.push(nullptr);
    view.push_back(root->data);
    while (!s.empty())
    {
        Node *cuur = s.front();
        s.pop();
        if (!cuur)
        {
            if (count.size())
                view.push_back(count.back());
            s.push(nullptr);
            count.clear();
            if (s.empty())
                break;
            continue;
        }  if (cuur->right)
        {
            s.push(cuur->right);
            count.push_back(cuur->right->data);
        }
        if (cuur->left)
        {
            s.push(cuur->left);
            count.push_back(cuur->left->data);
        }
      
    }
    for (auto i : view)
        cout << i << " ";
}
int main()
{
    Node *d = new Node(1);
    d->left = new Node(2);
    d->right = new Node(3);
    d->left->right = new Node(4);
    d->left->left = new Node(5);
    // preorder(d);
    cout << '\n';
    // it(d);
    rightview(d);
    return 0;
}