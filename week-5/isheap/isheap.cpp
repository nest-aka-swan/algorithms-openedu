#include <fstream>
#include <vector>
using std::vector;

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"isheap.in"};
std::ofstream fout{"isheap.out"};

int main()
{
    long n;
    fin >> n;
    vector<long> heap(n + 1);

    for (auto i = 1; i <= n; ++i)
        fin >> heap[i];

    for (auto i = 1; i <= n; ++i)
    {
        if (2 * i <= n && !(heap[i] <= heap[2 * i]))
        {
            fout << "NO";
            return 0;
        }
        if (2 * i + 1 <= n && !(heap[i] <= heap[2 * i + 1]))
        {
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
    return 0;
}
