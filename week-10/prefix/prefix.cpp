#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin{"prefix.in"};
    std::ofstream fout{"prefix.out"};

    std::string s;
    std::getline(fin, s);

    int n = (int)s.length();
	std::vector<int> pi(n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}

    for (auto i : pi)
        fout << i << " ";

    return 0;
}