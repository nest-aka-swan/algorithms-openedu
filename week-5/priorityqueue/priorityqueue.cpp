#include <fstream>
#include <vector>
using std::vector;
#include <climits>
#include <string>
#include <stdexcept>

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"priorityqueue.in"};
std::ofstream fout{"priorityqueue.out"};

vector<std::pair<long, int>> heap; // key, string idx

long parent(long idx)
{
    return (idx - 1) / 2;
}
long left(long idx)
{
    return 2 * idx + 1;
}
long right(long idx)
{
    return 2 * (idx + 1);
}

void min_heapify(long idx)
{
    auto l = left(idx);
    auto r = right(idx);
    long min;

    if (l < heap.size() && heap.at(l).first < heap.at(idx).first)
    {
        min = l;
    }
    else
    {
        min = idx;
    }
    if (r < heap.size() && heap.at(r).first < heap.at(min).first)
        min = r;
    if (min != idx)
    {
        std::swap(heap.at(idx), heap.at(min));
        min_heapify(min);
    }
}

void heap_decrease_key(long idx, long key)
{
    // if (key > heap.at(idx))
    //     throw std::logic_error("New key is greater than previous");

    // cout << "DEBUG! idx: " << idx << "key: " << key << endl;

    heap.at(idx).first = key;
    while (idx > 0 && heap.at(parent(idx)).first > heap.at(idx).first)
    {
        std::swap(heap.at(parent(idx)), heap.at(idx));
        idx = parent(idx);
    }
}

void heap_insert_min(long key, int str_idx)
{
    heap.push_back(std::pair<long, int>(LONG_MAX, str_idx));
    heap_decrease_key(heap.size() - 1, key);
}

long heap_extract_min()
{
    if (heap.size() < 1)
        throw std::logic_error("Heap is empty");
    auto min = heap.front();
    heap.at(0) = heap.back();
    heap.pop_back();

    min_heapify(0);

    return min.first;
}

int main()
{
    std::string cmd;
    long key, min, str_idx, idx;
    int str_count = 0;
    while (fin >> cmd)
    {
        str_count++;
        if (cmd == "push")
        {
            fin >> key;
            heap_insert_min(key, str_count);
            continue;
        }
        if (cmd == "extract-min")
        {
            try
            {
                min = heap_extract_min();
            }
            catch (std::logic_error err)
            {
                fout << "*\n";
                continue;
            }
            fout << min << "\n";
            continue;
        }
        if (cmd == "decrease-key")
        {
            fin >> str_idx >> key;
            // find idx by str_idx
            for (auto i = 0; i < heap.size(); ++i)
            {
                if (heap.at(i).second == str_idx)
                {
                    idx = i;
                    break;
                }
            }
            heap_decrease_key(idx, key);
            continue;
        }
    }

    // for (const auto &s : heap)
    // {
    //     cout << s << ' ';
    // }
}
