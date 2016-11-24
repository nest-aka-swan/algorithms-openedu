#include <fstream>
#include <vector>
#include <map>
using std::string;
using std::pair;
using std::map;

#include <iostream>
using std::cout;
using std::endl;

pair<string, string> hackHashInit()
{
	return pair<string, string>("a", "b");
}

int getHash(const string &s, int a)
{
	int res = 0;
    for (int i = 0; i < s.length(); ++i)
	    res = res * a + s[i];
	return res;
}

bool hackHash(pair<string, string> v, pair<string, string> &ans, int a)
{
	const int len = 22;
	map<int, string> mp;

    for (int i = 0; i < (1<<len); ++i)
	{
		string s;
		s.reserve(len * v.first.length());
		for (int j = 0; j < len; ++j)
        {
			if (i & (1 << j))
				s += v.first;
			else
				s += v.second;
        }
		
		int h = getHash(s, a);
		if (mp.find(h) != mp.end())
		{
			ans.first = mp[h];
			ans.second = s;
			return true;
		}

		mp.insert(make_pair(h, s));
	}
	return false;
}

// http://pastebin.com/JfTEUwCe
int main() 
{
	std::ifstream fin("killhash.in");
	std::ofstream fout("killhash.out");

	pair<string, string> collision;
	if (!hackHash(hackHashInit(), collision, 2))
	{
		std::cout << "FAIL!";
		return 0;
	}
	std::cout << "First OK!\n";
	if (!hackHash(collision, collision, 4))
	{
		std::cout << "FAIL!";
		return 0;
	}
	std::cout << "Second OK!\n";
	if (!hackHash(collision, collision, 6))
	{
		std::cout << "FAIL!";
		return 0;
	}
	std::cout << "Third OK!\n";

	// cout << collision.first << endl;
	cout << getHash(collision.first,  2) << endl;
	cout << getHash(collision.first,  4) << endl;
	cout << getHash(collision.first,  6) << endl;
	
	// cout << collision.second << endl;
	cout << getHash(collision.second,  2) << endl;
	cout << getHash(collision.second,  4) << endl;
	cout << getHash(collision.second,  6) << endl;

    return 0;
}