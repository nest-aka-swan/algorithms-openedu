#include <fstream>
#include <vector>
#include <algorithm>

// #include <iostream>
// using std::cin;
// using std::cout;
// using std::endl;

std::ifstream fin{"interactive.in"};
std::ofstream fout{"interactive.out"};

const auto HT_SIZE = 20000003; // must be prime
long long* ht;

long h1(long long k)
{
	return k % HT_SIZE;
}

long h2(long long k)
{
	return 1 + (k % 20000002); // less than HT_SIZE
}

void insert(long long item)
{
	auto x = h1(item); // key
	auto y = h2(item); // key

	for (auto i = 0; i < HT_SIZE; ++i)
	{
		if (ht[x] == -1) // uninitalized
		{
			ht[x] = item;
			return;
		}
		x = (x + y) % HT_SIZE;
	}
}

bool find(long long item)
{
	auto x = h1(item); // key
	auto y = h2(item); // key

	for (auto i = 0; i < HT_SIZE; ++i)
	{
		if (ht[x] != -1)
		{
			if (ht[x] == item) // keys
				return true;
			else
				return false;
		}
		x = (x + y) % HT_SIZE;
	}

	return false;
}

int main()
{
    const auto TEN_TO_3  = 1000LL;
    const auto TEN_TO_15 = 1000000000000000LL;

	// std::vector<long long> ht(HT_SIZE, -1);
	ht = new long long[HT_SIZE];
	std::fill_n(ht, HT_SIZE, -1);

    long long N, X, A, B;
    long long Ac, Bc, Ad, Bd;
    fin >> N >> X >> A >> B;
    fin >> Ac >> Bc >> Ad >> Bd;

	for (auto i = 0; i < N; ++i)
	{
		if (find(X))
		{
			A = (A + Ac) % TEN_TO_3;
            B = (B + Bc) % TEN_TO_15;
		}
		else
		{
            insert(X);
            A = (A + Ad) % TEN_TO_3;
            B = (B + Bd) % TEN_TO_15;			
		}

		X = (X * A + B) % TEN_TO_15;
	}

	fout << X << " " << A << " " << B;

	return 0;
}
