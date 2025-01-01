#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
     Node* newnode = new Node(1);
     cout << newnode->val << endl;

     return 0;
}