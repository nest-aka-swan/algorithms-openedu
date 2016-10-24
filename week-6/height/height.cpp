#include <fstream>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

std::ifstream fin{"height.in"};
std::ofstream fout{"height.out"};

struct Node
{
    long key;
    Node *parent;
    Node *left;
    Node *right;
};

// struct Node *newNodeNode(long key) 
// {
// 	Node *node = new Node;
// 	node->key = key;
// 	// node->left = NULL;
// 	// node->right = NULL;
// 	// node->parent = NULL;

// 	return node;
// }

struct Node* search(Node *from, long key)
{
	if (from == nullptr || key == from->key)
        return from;
    if (key < from->key)
        return search(from->left, key);
    else
        return search(from->right, key);
}

int main()
{
    int n;
    fin >> n;
    vector<vector<long>> tree;
    for (auto i = 0; i < n; ++i)
    {   
        
    }

    return 0;
}
