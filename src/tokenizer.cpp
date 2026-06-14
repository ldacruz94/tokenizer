
#include "tokenizer.h"

Tokenizer::Tokenizer() {}

void Tokenizer::tokenize(std::vector<std::string> tokenSequence) {}

std::unordered_map<std::string, int> Tokenizer::getMergeRules() const {
  return mergeRules;
}

void Tokenizer::setMergeRules(std::unordered_map<std::string, int> rules) {
  mergeRules = rules;
}

std::unordered_map<std::string, int> Tokenizer::getVocabTable() const {
  return vocabTable;
}

void Tokenizer::setVocabTable(std::unordered_map<std::string, int> vocab) {
  vocabTable = vocab;
}
