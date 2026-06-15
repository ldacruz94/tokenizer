
#include "tokenizer.h"
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

Tokenizer::Tokenizer() {}

std::vector<int> Tokenizer::tokenize(std::string tokenSequence) {

  std::vector<std::string> tokenSplit;
  for (char &c : tokenSequence) {
    tokenSplit.push_back(std::string(1, c));
  }

  std::string mergePair;
  std::ifstream file("data/encoder.json");
  nlohmann::json rankLookUp = nlohmann::json::parse(file);
  int lowestRank = 0;
  bool iterate = true;
  std::unordered_map<int, std::string> pairs = {};

  while (iterate) {

    for (int i = 0; i < tokenSplit.size() - 1; i++) {

      if (mergePair == "") {
        mergePair = tokenSplit[i] + tokenSplit[i+1];

        if (rankLookUp.contains(mergePair)) {
          int rank = rankLookUp[mergePair];
          lowestRank = rank;
          pairs[rank] = mergePair;
        } 

        continue;
      }

      mergePair = tokenSplit[i] + tokenSplit[i+1];
      if (mergePair.size() == 1) {
        break;
      } 

      if (rankLookUp.contains(mergePair)) {
        int rank = rankLookUp[mergePair];

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
    lowestRank = 0;
    pairs.clear();
  }

  // final rankLookUp
  std::vector<int> vectors = {};
  for (auto token : tokenSplit) {
    vectors.push_back(rankLookUp[token]);
  }

  return vectors;
}

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
