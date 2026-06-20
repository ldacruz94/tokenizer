
#include <string>
#include "tokenizer.h"
#include <iostream>
#include <sstream>

int main() {
  std::cout << "Enter your string: ";

  std::string input;
  std::getline(std::cin, input);

  std::istringstream ss(input);
  std::string word;
  std::vector<std::string> words;

  while (ss >> word) {
    words.push_back(word);
  }

  Tokenizer tokenizer;
  std::vector<int> vectors;
  for (auto w : words) {
    std::vector<int> results = tokenizer.tokenize(w);
    vectors.insert(vectors.end(), results.begin(), results.end());
  }

  std::cout << "final vector output: { ";
  for (int i = 0; i < vectors.size(); i++) {
    
    if (i+1 >= vectors.size()) {
      std::cout << vectors[i];
      break;
    }

    std::cout << vectors[i] << ",";
  }
  std::cout << " }";
  std::cout << "\n";
}
