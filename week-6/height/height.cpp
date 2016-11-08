#include <fstream>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

std::ifstream fin{"height.in"};
std::ofstream fout{"height.out"};

// struct Node
// {
//     long value;
//     Node *left;
//     Node *right;

//     Node(long value)
//     {
//         this->value = value;
//     }
//     Node(long value, Node *left, Node *right)
//     {
//         this->value = value;
//         this->left = left;
//         this->right = right;
//     }
// };

// class BST
// {
//     private:
//     Node *root;
//     void addHelper(Node *root, long value)
//     {
//         if (root->value > value)
//         {
//             if(!root->left)
//                 root->left = new Node(value);
//             else
//                 addHelper(root->left, value);
//         }
//         else
//         {
//             if(!root->right)
//                 root->right = new Node(value);
//             else
//                 addHelper(root->right, value);
//         }
//     }

//     public:
//     void add(long value)
//     {
//         if (root)
//             this->addHelper(root, value);
//         else
//             root = new Node(value);
//     }
// };

// struct Node* search(Node *from, long key)
// {
// 	if (from == nullptr || key == from->key)
//         return from;
//     if (key < from->key)
//         return search(from->left, key);
//     else
//         return search(from->right, key);
// }
vector<vector<long>> nodes;
vector<bool> visited;
void dfs(int node_idx)
{
    visited[node_idx] = true;
    for (const auto& i : nodes[node_idx])
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int n;
    fin >> n;
    nodes.reserve(n);

    long tmp_val;
    int tmp_left, tmp_right;
    for (auto i = 0; i < n; ++i)
    {
        fin >> tmp_val >> tmp_left >> tmp_right;
        nodes.push_back(vector<long> {tmp_val, tmp_left, tmp_right});
    }

    visited.reserve(n);
    // implement DFS with queue
    dfs(0);


    // for (const auto &el : nodes)
    //     cout << el[0] << ' ' << el[1] << ' ' << el[2] << endl;

    return 0;
}
