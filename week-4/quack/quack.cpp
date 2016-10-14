#include <fstream>
#include <vector>
using std::vector;
#include <regex>
using std::regex;
#include <map>
using std::map;

using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

std::ifstream fin{"quack.in"};
std::ofstream fout{"quack.out"};

regex add("\\+$");
regex sub("^-$");
regex mul("^\\*$");
regex division("^/$");
regex mod("^%$");

regex set_register("^>([a-z])$");
regex get_register("^<([a-z])$");

regex print("^P$");
regex print_register("^P([a-z])$");

regex print_as_char("^C$");
regex print_as_char_register("^C([a-z])$");

regex label("^:\\w+$");
regex jmp("^J(\\w+)$");
regex jz("^Z([a-z])(\\w+)$");
regex je("^E([a-z])([a-z])(\\w+)$");
regex jg("^G([a-z])([a-z])(\\w+)$");

regex quit("^Q$");

regex number("^\\d+$");

void tick(string cmd)
{
    
}

int main()
{
    vector<unsigned short> queue;
    queue.reserve(100000);
    vector<unsigned short> registers(26);

    string line;
    while (std::getline(fin, line))
    {
        tick(line);
    }
    cout << queue.back() << ' ';
    // for (auto it=queue.begin(); it!=queue.end(); ++it)
    //     cout << *it << ' ';
}
