#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *leftchild;
    node *rightchild;

    node()
    {
        leftchild = nullptr;
        rightchild = nullptr;
    }
};

class BinaryTree
{
public:
    node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr;
    }

    void insert()
    {
        int x;
        cout << "masukkan nilai: ";
        cin >> x;

        node *newnode = new node();
        newnode->info = x;

        newnode->leftchild = nullptr;
        newnode->rightchild = nullptr;

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
            parent->leftchild = newnode;

            return;
        }

        else if (x > parent->info)
        {
            parent->rightchild = newnode;

            return;
        }
    }

    void search(int element, node *&parent, node *&currentnode)
    {
        currentnode = ROOT;
        parent = nullptr;
        while ((currentnode != nullptr) && (currentnode->info != element))
        {
            parent = currentnode;
            if (element < currentnode->info)
            currentnode = currentnode->leftchild;
            else 
            currentnode = currentnode->rightchild;
        }
    }

    void inorder(node *ptr)
    {
        if (isempty())
        {
            cout << "tree is empty"<< endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info <<" ";
        inorder(ptr->rightchild);
    }
    void preorder(node *ptr)
    {
        if (isempty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        cout << ptr->info<< " ";
        preorder(ptr->leftchild);
        preorder (ptr->rightchild);
    }

    void  postorder(node *ptr)
    {
        if (isempty())
        {
            cout << "tree is empty" << endl;
            return;
        }

            if (ptr == nullptr)
            
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info<< " ";
        
    }
