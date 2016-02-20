#include <iostream>
#include <string>
#include <algorithm>

enum relation { less, greater, none };

int main()
{
  std::string line;
  std::getline(std::cin, line);
  size_t numLines = stoi(line);
  std::vector<size_t> lines;
  lines.reserve(numLines);
  for (size_t i = 0; i < numLines; ++i) {
    std::getline(std::cin, line);
    lines.push_back(stoi(line));
  }
  std::vector<relation> relations(numLines);
  for (size_t i = 0; i < numLines - 1; ++i) {
    size_t cur  = lines[i];
    size_t next = i < numLines - 1 ? lines[i + 1] : 0;
    if (cur < next) {
      relations[i] = greater;
    } else if (cur > next) {
      relations[i] = less;
    } else {
      relations[i] = none;
    }
  }
  relations[numLines - 1] = none;
  for (size_t i = 0; i < numLines; ++i) {
    if (greater == relations[i]) {
      if ((i == 0) || (i != 0 && greater != relations[i - 1])) {
        lines[i] = 1;
      } else {
        lines[i] = lines[i - 1] + 1;
      }
    }
  }
  for (size_t i = numLines - 1; i > 0; --i) {
    if (less == relations[i - 1]) {
      if ((i == numLines - 1) || (i != numLines - 1 && less != relations[i])) {
        lines[i] = 1;
      } else {
        lines[i] = lines[i + 1] + 1;
      }
    }
  }
  for (size_t i = 0; i < numLines; ++i) {
    if (0 == i && none == relations[0]) {
      lines[0] = 1;
    } else if (none == relations[i - 1] && none == relations[i]) {
      lines[i] = 1;
    }
  }
  std::cout << std::accumulate(lines.begin(), lines.end(), 0) << std::endl;
}
