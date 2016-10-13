#include <fstream>
#include <vector>
#include <algorithm>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

std::ifstream fin{"quack.in"};
std::ofstream fout{"quack.out"};

int main()
{
    std::vector<int> queue(65536);
    std::iota(queue.rbegin(), queue.rend(), 0);

    std::vector<int> registers(26);

    std::string line;
    while (std::getline(fin, line))
    {
        break;
    }
    cout << queue.back() << ' ';
    // for (auto it=queue.begin(); it!=queue.end(); ++it)
    //     cout << *it << ' ';
}
