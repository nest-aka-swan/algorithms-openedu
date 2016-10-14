#include <vector>
#include <algorithm>
#include <cstdio>
using std::fopen;
// #include <fstream>

FILE *fin;
// std::ofstream fout{"radixsort.out"};
FILE *fout;
int n, m, k; // число строк, длина, сколько фаз

// template <typename T>
// void print_debug(std::vector<T> &vec)
// {
//     for (auto it = vec.begin(); it != vec.end(); ++it)
//         std::cout << *it << ' ';
//     std::cout << std::endl;
// }
// template <typename T>
// void print_debug_2d(std::vector<std::vector<T>> &vec)
// {
//     for (auto it1 = vec.begin(); it1 != vec.end(); ++it1)
//         print_debug(*it1);
// }

void count_sort(std::vector<std::vector<unsigned char>> &vec, std::vector<int> &order)
{
    const unsigned char offset = 97;
    std::vector<int> sorted(n);
    std::vector<int> count(26); // alphabet size

    // main loop
    int counter = 0;
    for (auto layer = vec.rbegin(); counter < k && layer != vec.rend(); ++layer, ++counter)
    {
        auto current = *layer;

        for (auto it = order.begin(); it != order.end(); ++it)
            ++(count[current[*it] - offset]);

        for (auto it = std::next(count.begin()); it != count.end(); ++it)
            *it += *(std::prev(it));

        for (auto it = order.rbegin(); it != order.rend(); ++it)
        {
            sorted[count[current[*it] - offset] - 1] = *it;
            --(count[current[*it] - offset]);
        }

        //cleanup
        std::fill(order.begin(), order.end(), 0);
        order.swap(sorted);
        std::fill(count.begin(), count.end(), 0);
    }

    // output
    fout = fopen("radixsort.out", "w");
    for (auto it = order.begin(); it != order.end(); ++it)
        fprintf(fout, "%d ", *it + 1);
    // for (auto it = order.begin(); it != order.end(); ++it)
    //     fout << *it + 1 << ' ';
}

int main()
{
    fin = fopen("radixsort.in", "r");
    fscanf(fin, "%d%d%d ", &n, &m, &k);

    char format[100];
    sprintf(format, "%%%dc ", n);
    static const auto BUFFER_SIZE = n;
    unsigned char buf[BUFFER_SIZE + 1];

    std::vector<std::vector<unsigned char>> words;
    words.reserve(m);

    std::vector<int> order(n);

    for (auto i = 0; i < m; ++i)
    {
        fscanf(fin, format, &buf);
        words.push_back(std::vector<unsigned char>(buf, buf + sizeof buf / sizeof buf[0] - 1));
    }
    fclose(fin);

    std::iota(order.begin(), order.end(), 0);

    count_sort(words, order);
}
