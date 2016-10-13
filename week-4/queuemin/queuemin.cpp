#include <fstream>
// #include <cstdio>

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"queuemin.in"};
std::ofstream fout{"queuemin.out"};

int main()
{
    long int M; // число команд

    fin >> M;
    long int queue[M];
    long int head = 0;
    long int tail = 0;
    long int min;
    bool is_min_ok = false;
    // long int empty = 1e9 + 10;

    char command;
    long int number;
    for (auto i = 0; i < M; ++i)
    {
        fin >> command;
        switch (command)
        {
            case '+':
                fin >> number;
                if (is_min_ok && number < min)
                    min = number;
                queue[tail++] = number;
                break;
            case '-':
                if (queue[head] == min)
                    is_min_ok = false;
                head++;
                break;
            case '?':
                if (!is_min_ok)
                {
                    min = queue[head];
                    for (auto i = head+1; i < tail; ++i)
                    {
                        if (queue[i] < min)
                            min = queue[i];
                    }
                    is_min_ok = true;
                }
                fout << min << '\n';
                break;
        }
    }
}
