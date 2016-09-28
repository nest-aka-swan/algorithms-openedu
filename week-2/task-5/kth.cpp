#include <fstream>
#include <vector>
#include <algorithm>
// #include <utility>
// #include <iostream>

std::ifstream fin { "kth.in" };
std::ofstream fout { "kth.out" };

long n, k1, k2;
int A, B, C, a1, a2;

template <typename Iterator>
void bfprt(Iterator begin, long nth, Iterator end)
{
  std::vector<int> numbers(n);
  for(Iterator it=begin; it!=end;)
  {
    if(it + 5 <= end)
    {
      std::nth_element(it, it + 3, it + 5);
      it += 5;
    }
  }
}

int main()
{
  fin >> n >> k1 >> k2 >> A >> B >> C >> a1 >> a2;

  std::vector<int> numbers(n);
  // int *numbers = new int[n];
  numbers[0] = a1;
  numbers[1] = a2;

  std::vector<int>::iterator it;
  for(it = numbers.begin() + 2; it != numbers.end(); ++it)
    *it = A * *(it - 2) + B * *(it - 1) + C;
  // for(long i = 2; i < n; ++i)
  //   numbers[i] = A * numbers[i-2] + B * numbers[i-1] + C;

  bfprt(numbers.begin(), 5, numbers.end());
  // for(it = numbers.begin() + k1 - 1; it != numbers.begin() + k2; ++it)
  // {
  //   std::nth_element(numbers.begin(), it, numbers.end(), std::less<int>());
  //   fout << *it << ' ';
  // }

  return 0;
}
