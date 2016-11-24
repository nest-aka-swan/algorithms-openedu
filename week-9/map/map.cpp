#include <vector>
#include <fstream>

int main()
{
	std::ifstream fin("map.in");
	std::ofstream fout("map.out");
	std::string str, tmp;

	while (fin >> tmp)
		str += tmp;
	auto n = str.length();
	long long ans = 0;
	std::vector<std::vector<int>> pref_sum(n + 1, std::vector<int>(26));
	for (int i = 1; i <= n; ++i)
	{
		pref_sum[i] = pref_sum[i - 1];
		pref_sum[i][str[i - 1] - 'a']++;
	}
	for (int i = 1; i < n - 1; i++)
		for (int j = 0; j < 26; j++)
			ans += pref_sum[i][j] * 1LL * (pref_sum[n][j] - pref_sum[i + 1][j]);
	fout << ans;
}
