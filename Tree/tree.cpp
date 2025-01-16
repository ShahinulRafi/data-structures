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

void level_order(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        //1. ber kore ana
        Node* f = q.front();
        q.pop();

        //2. oi node niye kaj
        cout << f->val << " ";

        //3. children push kora
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
void input_tree()
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
    level_order(root);
}

int main()
{
     input_tree();
     
     return 0;
}