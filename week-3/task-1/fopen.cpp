#include <cstdio>
using std::fopen;
#include <vector>

int n, m, k; // число строк, длина, сколько фаз
FILE* fp;

int main()
{
    fp = fopen("radixsort.in", "r");
    fscanf(fp, "%d%d%d ", &n, &m, &k);

    char format[8];
    sprintf(format, "%%%dc ", n);
    static const auto BUFFER_SIZE = n;
    unsigned char buf[BUFFER_SIZE + 1];

    std::vector<std::vector<unsigned char>> words;
    words.reserve(m);

    for (auto i = 0; i < m; ++i)
    {
        fscanf(fp, format, &buf);
        words.push_back(std::vector<unsigned char>(buf, buf + sizeof buf / sizeof buf[0] - 1));
    }
}
