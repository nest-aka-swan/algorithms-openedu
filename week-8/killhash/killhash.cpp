#include <fstream>
#include <vector>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int hashOf(string s, int c) { 
    int hash = 0;
    for (int i = 0; i < s.length(); ++i) {
        hash = c * hash + s.at(i);
    }
    return hash;
}

int main() 
{
	std::ifstream fin("killhash.in");
	std::ofstream fout("killhash.out");
    // 24 'z' переполняет
    string test = "abc";

    for (auto i = 2; i < 100; ++i)
    {
        cout << hashOf(test, i) << endl;
    }

    return 0;
}