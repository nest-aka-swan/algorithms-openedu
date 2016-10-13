#include <fstream>
// #include <cstdio>

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"queue.in"};
std::ofstream fout{"queue.out"};

int main()
{
    long int M; // число команд

    fin >> M;
    long int queue[M];
    long int head = 0;
    long int tail = 0;

    char command;
    long int number;
    for (auto i = 0; i < M; ++i)
    {
        fin >> command;
        if (command == '+')
        {
            fin >> number;
            queue[tail++] = number;
        }
        else
        {
            fout << queue[head++] << '\n';
        }
    }
}
