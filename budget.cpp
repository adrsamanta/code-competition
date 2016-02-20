#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>

typedef unsigned long long asdf;

asdf do_knapsack(asdf cap,
                 const std::vector<asdf> & weight,
                 const std::vector<asdf> & value)
{
  asdf n = weight.size();
  asdf K[weight.size() + 1][cap + 1];
  assert(weight.size() == value.size());
  for (asdf i = 0; i <= n; ++i) {
    for (asdf w = 0; w <= cap; ++w) {
      if (0 == i || 0 == w) {
        K[i][w] = 0;
      } else if (weight[i - 1] <= w) {
        K[i][w] =
            std::max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
      } else {
        K[i][w] = K[i - 1][w];
      }
    }
  }
  return K[n][cap];
}

int main()
{
  std::vector<asdf> weights;
  std::vector<asdf> values;
  asdf n;
  std::cin >> n;
  asdf cap;
  std::cin >> cap;
  asdf cur;
  for (asdf i = 0; i < n; ++i) {
    std::cin >> cur;
    values.push_back(cur);
    std::cin >> cur;
    weights.push_back(cur);
  }
  std::cout << do_knapsack(cap, weights, values) << std::endl;
}
