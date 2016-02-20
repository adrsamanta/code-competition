#include <iostream>
#include <cmath>

typedef unsigned long long asdf;

asdf compute(asdf n)
{
  asdf square_root = floor(sqrt(n));
  asdf cur    = 1;
  asdf rest_n = 0;
  while (cur * square_root < n && square_root != 1) {
    cur *= square_root;
    ++rest_n;
  }
  asdf rest = n - (rest_n * square_root);
  return cur * rest;
}

int main()
{
  asdf n;
  std::cin >> n;
  std::cout << compute(n) << std::endl;
}
