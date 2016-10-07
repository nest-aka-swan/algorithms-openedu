#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

std::ifstream fin { "kth.in" };
std::ofstream fout { "kth.out" };

long n, k1, k2;
int A, B, C, a1, a2;

template <typename Iterator>
std::pair<Iterator, Iterator> partition_range(Iterator begin, Iterator end, Iterator pivot)
{
    std::pair<Iterator, Iterator> re;
    auto j = begin;
    for(auto i = begin; i != end; ++i)
        if (*i < *pivot)
        {
            if (pivot == i) pivot = j; else if (pivot == j) pivot = i;
            std::swap(*j, *i); j++;
        }
    re.first = j;
    for(auto i = j; i != end; ++i)
        if (!(*pivot < *i))
        {
            if (pivot == i) pivot = j; else if (pivot == j) pivot = i;
            std::swap(*j, *i); ++j;
        }
    re.second = j;
    return re;
}

template <typename Iterator>
Iterator bfprt(Iterator begin, Iterator end, long k)
{
    auto d = std::distance(begin, end);
    if(d < 5)
    {
        std::sort(begin, end);
        return begin + k;
    }

    auto blocks = d / 5;
    auto b = begin, c = begin;
    for(auto a = 0; a < blocks; ++a)
    {
        std::sort(b, b + 5);
        b = b + 2;
        std::swap(*c, *b); ++c;
        b = b + 3;
    }

    auto pivot = bfprt(begin, begin + blocks, blocks / 2);
    auto range = partition_range(begin, end, pivot);

    auto sz1 = std::distance(begin, range.first);
    auto sz2 = std::distance(range.first, range.second);

    if (k < sz1) return bfprt( begin, range.first, k );
    if (k < sz1 + sz2) return range.first;
    return bfprt( range.second, end, k - sz1 - sz2 );
}

int main()
{
    fin >> n >> k1 >> k2 >> A >> B >> C >> a1 >> a2;

    std::vector<int> numbers(n);
    numbers[0] = a1;
    numbers[1] = a2;

    for(auto it = numbers.begin() + 2; it != numbers.end(); ++it)
        *it = A * *(it - 2) + B * *(it - 1) + C;

    // for(auto it = numbers.begin(); it != numbers.end(); ++it)
    //     std::cout << *(it) << std::endl;
    // std::cout << std::endl;

    for(auto i = k1; i <= k2; ++i)
        fout << *(bfprt(numbers.begin(),  numbers.end(), i)) << ' ';

    // std::cout << *(bfprt(numbers.begin(),  numbers.end(), k1)) << std::endl;
    // std::cout << *(bfprt(numbers.begin(),  numbers.end(), k2));
//   bfprt(numbers.begin(),  numbers.end(), k2);

    return 0;
}
