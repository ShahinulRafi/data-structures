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
Node* input_tree()
{
    int val;
    cin >> val;
    Node* root = new Node(val);
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        //1. ber kore ana
        Node* p = q.front();
        q.pop();

        //2. oi node niye kaj
        int l, r;
        cin >> l >> r;
        Node* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        p->left = myLeft;
        p->right = myRight;

        //3. children push kora
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

void print_left(Node* root, vector<int>& v)
{
    if(root == NULL) return;
    if(root->left) print_left(root->left,v);
    else print_left(root->right,v);
    v.push_back(root->val);
}
void print_right(Node* root, vector<int>& v)
{
    if(root == NULL) return;
    v.push_back(root->val);
    if(root->right) print_right(root->right, v);
    else print_right(root->left, v); 
}

vector<int> print_outer(Node* root)
{
    vector<int> v;
    if(root == NULL) return v;
    
    print_left(root->left, v);
    v.push_back(root->val);
    print_right(root->right, v);
    
    return v;
}

int main()
{
    //int nodes = 0;
    Node* root;
    root = input_tree();
    vector<int> v;
    v = print_outer(root);
    for(auto u : v) cout << u << " ";
    return 0;
}
