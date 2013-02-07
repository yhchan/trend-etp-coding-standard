#include <iostream>
#include <vector>
#include <algorithm>

void vector_out(const std::vector<int>& vec) {
  std::for_each (vec.begin(), vec.end(), [](int e) {
      std::cout << e << ' ';
  });
  std::cout << std::endl;
}

void generate_numbers_vector_bad(std::vector<int>& vec) {
  vec.clear();
  vec.push_back(1);
  vec.push_back(2);  // If exception is thrown ...
}

void generate_numbers_vector_swap(std::vector<int>& vec) {
  std::vector<int> result;
  result.push_back(1);
  result.push_back(2);
  std::swap(vec, result);   // swap is nothrow
}

std::vector<int> generate_numbers_vector_return() {
  std::vector<int> result;
  result.push_back(1);
  result.push_back(2);
  return result;  // RVO or move statement
}

int main() {
  std::vector<int> vec;
  generate_numbers_vector_bad(vec);
  vector_out(vec);

  vec.clear();
  generate_numbers_vector_swap(vec);
  vector_out(vec);

  vec = generate_numbers_vector_return();
  vector_out(vec);

  return 0;
}
