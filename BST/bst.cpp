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

Node* array_to_bst(int a[], int n, int l, int r)
{
    if( l > r ) return NULL;

    int mid = (l+r) / 2;

    Node* root = new Node(a[mid]);
    Node* left_root = array_to_bst(a, n, l, mid-1);
    Node* right_root = array_to_bst(a, n, mid+1, r);

    root->left = left_root;
    root->right = right_root;

    return root;
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