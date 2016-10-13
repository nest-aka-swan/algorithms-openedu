#include <fstream>
// #include <cstdio>

// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;

std::ifstream fin{"stack.in"};
std::ofstream fout{"stack.out"};
// FILE* fin, fout;

int main()
{
    long int M; // число команд
    // fin = fopen("stack.in", "r");
    
    // fscanf(fin, "%d ", &M);
    fin >> M;
    long int stack[M + 1];
    long int top = 0;

    char command;
    long int number;
    for (auto i = 0; i < M; ++i)
    {
        fin >> command;
        if (command == '+')
        {
            fin >> number;
            stack[++top] = number;
        }
        else
        {
            fout << stack[top--] << '\n';
        }
    }
}
