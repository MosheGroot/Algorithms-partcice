#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<size_t> Z_Algorithm(const std::string& str)
{
  std::vector<size_t> z;
	z.resize(str.size(), 0u);

  size_t l = 0, r = 0;
  for (size_t i = 1; i < str.size(); ++i)
  {
    // Set the lower boundary to `z[i]`
    // or leave it at zero
    if (i < r)
      z[i] = std::min(z[i - l], r - i + 1);

    // try to calculate `z[i]` after already known
    // (or 0) value
    while (i + z[i] < str.size() && str[i + z[i]] == str[z[i]])
      z[i] += 1;

    // update `[l, r]` boundaries for
    // easy calc of inner z-values
    if (r < i + z[i] - 1)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

void solve()
{
	std::string str;
	std::cin >> str;

  const auto z = Z_Algorithm(str);

  for (size_t i = 0; i < z.size() - 1; ++i)
    std::cout << z[i] << ' ';
  std::cout << z.back() << std::endl;
}

int main()
{
	int t = 1;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		solve();

	return 0;
}