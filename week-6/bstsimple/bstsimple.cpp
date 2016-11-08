#include <fstream>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

std::ifstream fin{"bstsimple.in"};
std::ofstream fout{"bstsimple.out"};

struct Node
{
    long value;
    Node *parent;
    Node *left;
    Node *right;

    Node(long value)
    {
        this->value = value;
    }
    Node(long value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class BST
{
    private:
    Node *root;

    Node* minimum(Node *x)
    {
        if (x->left == nullptr)
            return x;

        return minimum(x->left);
    }
    Node* remove1 (Node *z)
    {
        if (z->left == nullptr)
            return z->right;
        else
            return z->left;
    }
    Node* remove2 (Node *z)
    {
        auto y = minimum(z->right);
        z->right = remove(z->right, y);
        y->right = z->right;
        y->left = z->left;

        return y;
    }
    Node* search(Node *x, long value)
    {
        if (x == nullptr || value == x->value)
            return x;
        if (value < x->value)
            return search(x->left, value);
        else
            return search(x->right, value);
    }

    public:
    Node* next(Node *x)
    {
        if (x->right != nullptr)
            return minimum(x->right);

        auto y = x->parent;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
    }
    Node* insert(Node *x, Node *z)
    {
        if (x == nullptr)
            return z;

        if (z->value < x->value)
            x->left = insert(x->left, z);
        else
            x->right = insert(x->right, z);
    }
    Node* remove(Node *x, Node *z)
    {
        if (z->value < x->value)
        {
            x->left = remove(x->left, z);
            return x;
        }
        else if (z->value > x->value)
        {
            x->right = remove(x->right, z);
            return x;
        }
        else
        {
            if (x->left == nullptr || x->right == nullptr)
                return remove1(x);
            else
                return remove2(x);
        }
    }

    BST(long value) {
        this->root = new Node(value);
    }
};

int main()
{
    std::string cmd;
    long x;
    auto tree = new BST(5);
    tree.insert()
    // while (fin >> cmd && fin >> x)
    // {
    //     cout << cmd << endl;
    //     if (cmd == "insert")
    //     {
    //         tree->add(x);
    //         continue;
    //     }
    //     if (cmd == "delete")
    //     {
    //         tree->remove(x);
    //         continue;
    //     }
    //     if (cmd == "exists")
    //     {
    //         tree->exists(x);
    //         continue;
    //     }
    //     if (cmd == "next")
    //     {
    //         tree->next(x);
    //         continue;
    //     }
    //     if (cmd == "prev")
    //     {
    //         tree->prev(x);
    //         continue;
    //     }
    // }
    return 0;
}
