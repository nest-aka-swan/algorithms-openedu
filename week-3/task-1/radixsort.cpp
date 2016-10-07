#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>

std::ifstream fin { "radixsort.in" };
std::ofstream fout { "radixsort.out" };

int n, m, k; // число строк, длина, сколько фаз

template<typename T>
void print_debug(std::vector<std::vector<T>> &vec)
{
    for(auto it1=vec.begin();it1!=vec.end();++it1)
    {
        for(auto it2=it1->begin();it2!=it1->end();++it2)
            std::cout << *it2 << ' ';
        std::cout << std::endl;
    }  
}

void count_sort(std::vector<std::vector<unsigned char>> &vec, std::vector<int> &order)
{
    std::vector<int> sorted(n);
    const unsigned char offset = 97;
    std::vector<int> count(26); // alphabet size

    // main loop
    for(auto loop=0;loop<k;++loop)
    {
        auto word_idx = m - loop - 1;

        // std::cout<<"im in loop!"<<std::endl;
        // std::cout<<word_idx<<std::endl;

        for(auto word=vec.begin();word!=vec.end();++word)
        {
            ++(count.at((*word)[word_idx] - offset)); // counting
        }
        for(auto i=1;i<count.size();++i)
        {
            count[i] = count[i] + count[i-1];
        }
        for(auto word=vec.rbegin();word!=vec.rend();++word)
        {
            sorted[count[(*word)[word_idx] - offset] - 1] = word - vec.rbegin() + 1;
            count[(*word)[word_idx] - offset] -= 1;
        }

        // output
        std::cout << std::endl;
        for(auto it=sorted.begin();it!=sorted.end();++it)
            std::cout << *it << ' ';
        std::cout << std::endl;

        //cleanup
        std::fill(order.begin(), order.end(), 0);
        order.swap(sorted);
        std::fill(count.begin(), count.end(), 0);
    }
}

int main()
{
    fin >> n >> m >> k;

    std::vector<int> order(n);
    std::vector<std::vector<unsigned char>> words(n, std::vector<unsigned char>(m));
    
    for(auto j=0;j<m;++j)
        for(auto i=0;i<n;++i)
            fin >> words[i][j];

    std::iota(order.begin(), order.end(), 1); // fill order with word numbers
    
    // print_debug(words);
    // std::cout << words.size();

    count_sort(words, order);
}