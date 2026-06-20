
#include <unordered_map>
#include <string>
#include <vector>

class Tokenizer {

  public:
    Tokenizer();
    std::vector<int> tokenize(std::string tokenSequence);    
    void setVocabTable(std::unordered_map<std::string, int> vocab); 

  private:
    std::unordered_map<std::string, int> vocabTable;
};

