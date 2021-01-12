#include <algorithm>
#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <iterator>
using namespace std;

template <typename T>
vector<vector<T>> Generate(vector<T> &vec)
{
	int numOfSubsets = 1 << (vec.size());
	vector<vector<T>> ans;
	bitset<32> bits;
	for (auto i = 0; i < numOfSubsets; i++)
	{
		bits = i;
		ans.emplace_back(0);
		for (int j = 0; j < vec.size(); j++)
		{
			if (bits[j] == 1)
			{
				ans[i].push_back(vec[j]);
			}
		}
	}
	return ans;
}

int main()
{
	vector<int> vec{1, 2, 3};
	auto ans = Generate(vec);
	for_each(ans.begin(), ans.end(), [](auto &x) {
		copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	});
	cout << "Done" << endl;
}
