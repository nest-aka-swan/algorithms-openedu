#include <fstream>
#include <vector>
#include <algorithm>
// #include <utility>
// #include <iostream>

// using namespace std;

std::ifstream fin { "sort.in" };
std::ofstream fout { "sort.out" };
std::vector<int> numbers();

void merge_sort(int start, int end)
{
    if(end - start < 2)
    {
        fout << start << ' ' << end << ' ' << numbers[start] << endl;
        return
    }

    int mid = (end + start) / 2;

    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end, mid);
}

void merge(int start, int end, int mid)
{
    int i = 0, j = 0;
    while(i < len(arr_l) and j < len(arr_r))
    {
        
    }
}

int main()
{
    // variables
    int n;
    std::vector<int> result(10);
    result[0] = 42;

    //fin >> vars;

    //output
    for(auto it=result.begin();it!=result.end();++it)
        fout << *it << ' ';
}