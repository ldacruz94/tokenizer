
#include <string>
#include "tokenizer.h"
#include <iostream>

int main() {

  std::string input = {"lowest"};

  Tokenizer tokenizer;
  std::vector<int> vectors = tokenizer.tokenize(input);

  std::cout << "final vector output: {";
  for (int v : vectors) {
    std::cout << v << ",";
  }
  std::cout << "}";
  std::cout << "\n";
}
