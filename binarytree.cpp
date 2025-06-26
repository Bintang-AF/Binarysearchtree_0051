#include <iostream>
using namespace std;

class node 
{
    public:
    int info;
    node *leftchild;
    node *rightchild;

    node ()
    {
        leftchild = nullptr;
        rightchild = nullptr;
    }
};

class BinaryTree
{
    public :
    node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr;
    }

    void insert ()
    {
        int x;
        cout << "masukkan nilai: ";
        cin >> x;

        node *newnode = new node ();
        newnode->info = x;

        newnode->leftchild = nullptr;
        newnode -> rightchild= nullptr;

        node *parent = nullptr;
        node *currentnode = nullptr;
        search(x, parent, currentnode);

        if (parent == nullptr)
        {
            ROOT = newnode;
            return;
        }

        if (x < parent->info)
        {
            parent ->leftchild = newnode ;

            return ;
        }
    }
}