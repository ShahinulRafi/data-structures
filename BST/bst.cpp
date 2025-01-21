#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

void bst_insert(Node* root, int val)
{
    if(root == NULL) root = new Node(val);

    if(root->val < val)
    {
        if(root->right == NULL) root->right = new Node(val);
        else bst_insert(root->right, val);
    }
    else
    {
        if(root->left == NULL) root->left = new Node(val);
        else bst_insert(root->left, val);
    }

}

void tree_level_print(Node* root)
{
    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

bool bst_search(Node* root, int val)
{
    if(root == NULL) return false;
    if(root->val == val) return true;

    if(val > root->val) bst_search(root->right, val);
    else bst_search(root->left, val);
}

int main()
{
     Node* root;
     
     return 0;
}