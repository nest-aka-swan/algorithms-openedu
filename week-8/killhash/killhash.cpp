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

long long getHash(const string &s, long long a)
{
	long long res = 0;
    for (int i = 0; i < s.length(); ++i)
	    res = (res * a + s[i]) % 1000000000000000; // тут был % p
	return res;
}

bool hackHash(pair<string, string> v, pair<string, string> &ans, long long a)
{
	const int len = 22;
	map<long long, string> mp;

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
		
		long long h = getHash(s, a);
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

int main() 
{
	std::ifstream fin("killhash.in");
	std::ofstream fout("killhash.out");

	pair<string, string> collision;
	if (!hackHash(hackHashInit(), collision, 51))
	{
		std::cout << "FAIL!";
		return 0;
	}
	std::cout << "First OK!";
	if (!hackHash(collision, collision, 59))
	{
		std::cout << "FAIL!";
		return 0;
	}

	cout << collision.first << endl;
	cout << getHash(collision.first,  51) << endl;
	cout << getHash(collision.first,  59) << endl;
	
	cout << collision.second << endl;
	cout << getHash(collision.second,  51) << endl;
	cout << getHash(collision.second,  59) << endl;

    return 0;
}