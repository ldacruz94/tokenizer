
#include "tokenizer.h"
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

Tokenizer::Tokenizer() {
  std::ifstream file("data/encoder.json");
  nlohmann::json rankLookUp = nlohmann::json::parse(file);
  this->setVocabTable(rankLookUp);
}

std::vector<int> Tokenizer::tokenize(std::string tokenSequence) {

  if (tokenSequence.empty()) return {};

  std::vector<std::string> tokenSplit;
  for (char &c : tokenSequence) {
    tokenSplit.push_back(std::string(1, c));
  }

  std::string mergePair;
  int lowestRank = INT_MAX;
  bool iterate = true;
  std::unordered_map<int, std::string> pairs = {};

  while (iterate) {

    for (int i = 0; i < tokenSplit.size() - 1; i++) {

      if (mergePair == "") {
        mergePair = tokenSplit[i] + tokenSplit[i+1];

        if (this->vocabTable.contains(mergePair)) {
          int rank = this->vocabTable[mergePair];
          lowestRank = rank;
          pairs[rank] = mergePair;
        } 

        continue;
      }

      mergePair = tokenSplit[i] + tokenSplit[i+1];
      if (mergePair.size() == 1) {
        break;
      } 

      if (this->vocabTable.contains(mergePair)) {
        int rank = this->vocabTable[mergePair];

        if (lowestRank > rank) {
          lowestRank = rank;
        }

        pairs[rank] = mergePair;
      }
    }

    if (pairs.empty()) {
      break;
    }

    std::string winnerPair = pairs[lowestRank];

    std::vector<std::string> newSplit = {};
    for (int i = 0; i < tokenSplit.size(); i++) {
      if ( i+1 < tokenSplit.size() && tokenSplit[i] + tokenSplit[i+1] == winnerPair ) {
        newSplit.push_back(winnerPair);
        i++;
      } 
      else {
        newSplit.push_back(tokenSplit[i]);
      }
    }

    tokenSplit = std::move(newSplit);

    mergePair = "";
    lowestRank = INT_MAX;
    pairs.clear();
  }

  // final rankLookUp
  std::vector<int> vectors = {};
  for (auto token : tokenSplit) {
    vectors.push_back(this->vocabTable[token]);
  }

  return vectors;
}

void Tokenizer::setVocabTable(std::unordered_map<std::string, int> vocab) {
  vocabTable = vocab;
}
