#include <fstream>
#include <vector>
#include <algorithm>
// #include <utility>
// #include <iostream>

std::ifstream fin { "antiqs.in" };
std::ofstream fout { "antiqs.out" };

int main()
{
  int n;
  fin >> n;

  if(n == 1)
  {
      fout << 1;
      return 0;
  }

  std::vector<int> numbers(n);
//   for(auto it=numbers.begin();it!=numbers.end();++it)
//   {
//       *it = ++i;
//   }
  for(int i=1;i<=n;++i)
  {
      numbers[i-1] = i;
  }

  std::vector<int> result(n);

  // numbers[1:(len(numbers) // 2)]
  // [numbers[0]]
  // [max(numbers)]
  // numbers[(len(numbers) // 2):-1]

  for(int i = 1; i != n / 2; ++i)
  {
    result[i-1] = numbers[i];
  }
  result[n / 2 - 1] = numbers[0];
  result[n / 2] = numbers[n-1];
  for(int i = n / 2 + 1; i != n; ++i)
  {
    result[i] = numbers[i-1];
  }


  for(auto it=result.begin();it!=result.end();++it)
  {
      fout << *it << ' ';
  }
  
  return 0;
}
