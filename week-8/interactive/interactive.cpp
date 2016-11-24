#include <vector>
#include <algorithm>
#include <fstream>

const auto HASH_CAPACITY = 20000023;
long long* hash;

long h1(long long k) {
	return k % HASH_CAPACITY;
}

long h2(long long k) {
	return (k % 20000022) + 1;
}

void insert(long long item) {
	auto x = h1(item);
	auto y = h2(item);
	for (auto i = 0; i < HASH_CAPACITY; ++i) {
		if (hash[x] == -1) {
			hash[x] = item;
			return;
		}
		x = (x + y) % HASH_CAPACITY;
	}
}

bool find(long long item) {
	auto x = h1(item);
	auto y = h2(item);
	for (auto i = 0; i < HASH_CAPACITY; ++i) {
		if (hash[x] == item)
			return true;
		if (hash[x] == -1)
			break;
		x = (x + y) % HASH_CAPACITY;
	}
	return false;
}

int main() {
	std::ifstream fin{"interactive.in"};
	std::ofstream fout{"interactive.out"};

    const auto TEN_BY3  = 1000LL;
    const auto TEN_BY15 = 1000000000000000LL;
	hash = new long long[HASH_CAPACITY];
	std::fill_n(hash, HASH_CAPACITY, -1);
    long long N, X, A, B;
    long long Ac, Bc, Ad, Bd;
    fin >> N >> X >> A >> B;
    fin >> Ac >> Bc >> Ad >> Bd;

	for (auto i = 0; i < N; ++i) {
		if (find(X)) {
			A = (A + Ac) % TEN_BY3;
            B = (B + Bc) % TEN_BY15;
		}
		else {
            insert(X);
            A = (A + Ad) % TEN_BY3;
            B = (B + Bd) % TEN_BY15;			
		}
		X = (X * A + B) % TEN_BY15;
	}

	fout << X << " " << A << " " << B;
	return 0;
}
