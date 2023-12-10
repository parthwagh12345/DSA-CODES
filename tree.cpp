#include <iostream>
using namespace std;

//----------------------Class Node----------------------//
class Node
{
    public:
        char data;
        Node *left;
        Node *right;
        Node *next = NULL;
        
        Node(char c)
        {
            this->data = c;
            left = NULL;
            right = NULL;
        }

        Node()
        {
            left = NULL;
            right = NULL;
        }
};

//----------------------Class Stack----------------------//
class Stack
{
    Node* head = NULL;

    public:
        void push(Node*);
        Node* pop();
};

void Stack::push(Node* x)
{
    if(head == NULL)
    {
        head = x;
    }
    else
    {
        x->next = head;
        head = x;
    }
}

Node* Stack::pop()
{
    Node* p = head;
    head = head->next;
    return p;
}

//----------------------Class Expression_tree----------------------//
class Expression_tree
{
    public:
        void inorder(Node*);      // left->root->right
        void preorder(Node*);     // root->left->right
        void postorder(Node*);    // left->right->root
};

void Expression_tree::inorder(Node* x)
{
    if(x != NULL)
    {
        inorder(x->left);
        cout<<x->data<<" ";
        inorder(x->right);
    }
}

void Expression_tree::preorder(Node* x)
{
    if(x != NULL)
    {
        cout<<x->data<<" ";
        preorder(x->left);
        preorder(x->right);
    }
}

void Expression_tree::postorder(Node* x)
{
    if(x != NULL)
    {
        postorder(x->left);
        postorder(x->right);
        cout<<x->data<<" ";
    }
}

bool is_operator(char c)
{
    if(c =='*' || c == '/' || c == '+' || c == '-')
        return true;
    
    else
        return false;
}
//----------------------int main()----------------------//
int main()
{
    string s;
    Stack st;
    Expression_tree ex;
    Node *x, *y, *z;
    int choice=1;

    while(choice!=0)
    {
        cout<<"Enter the postfix expression to be converted: ";
        cin>>s;
        
        for(int i=0; i<s.length(); i++)
        {
            if(is_operator(s[i]))
            {
                z = new Node(s[i]);
                x = st.pop();
                y = st.pop();
        
                z->left = y;
                z->right = x;
                st.push(z);
            }
            else
            {
                z = new Node(s[i]);
                st.push(z);
            }
        }
        cout<<"\n\n";
        cout<<"The inorder of the expression is: ";
        ex.inorder(z);
        cout<<"\n";
        
        cout<<"The preorder of the expression is: ";
        ex.preorder(z);
        cout<<"\n";
        
        cout<<"The postorder of the expression is: ";
        ex.postorder(z);
        cout<<"\n----------------------------------------------------------------\n";
        cout<<"----------------------------------------------------------------\n";

        cout<<"Do you want to continue? (0->no/1->yes) : ";
        cin>>choice;
        cout<<"\n\n";
    }
}