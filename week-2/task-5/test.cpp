#include <vector>
#include <fstream>
#include <algorithm>

// #include <iostream>
// using std::cout;

std::ifstream fin { "kth.in" };
std::ofstream fout { "kth.out" };

long n, k1, k2;
int A, B, C, a1, a2;

int main()
{
    fin >> n >> k1 >> k2 >> A >> B >> C >> a1 >> a2;

    std::vector<int> numbers(n);
    numbers[0] = a1;
    numbers[1] = a2;

    for(auto it = numbers.begin() + 2; it != numbers.end(); ++it)
        *it = A * *(it - 2) + B * *(it - 1) + C;

    std::nth_element(numbers.begin(), numbers.begin() + k1 - 1, numbers.end());

    if (k1 != k2)
    {
        std::nth_element(numbers.begin() + k1, numbers.begin() + k2 - 1, numbers.end());
        std::sort(numbers.begin() + k1, numbers.begin() + k2 - 1);
    }

    for(auto it = numbers.begin() + k1 - 1; it != numbers.begin() + k2; ++it)
        fout << *it << ' ';
}