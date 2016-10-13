#include <fstream>
#include <vector>
// #include <cstdio>

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"brackets.in"};
std::ofstream fout{"brackets.out"};

int main()
{
    std::vector<char> stack;
    long int top = 0;

    std::string result;
    std::string line;
    while (std::getline(fin, line))
    {
        stack.clear();
        result = "YES";
        for (auto it = line.begin(); it != line.end(); ++it)
        {
            auto bracket = *it;
            if (bracket == '(' || bracket == '[')
            {
                stack.push_back(bracket);
            }
            else if ((stack.back() == '(' && bracket == ')') || (stack.back() == '[' && bracket == ']'))
            {
                stack.pop_back();
            }
            else
            {
                result = "NO";
                break;
            }
        }
        if (!stack.empty())
            result = "NO";
        fout << result << '\n';
    }
}
