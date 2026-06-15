
#include <unordered_map>
#include <string>
#include <vector>

class Tokenizer {

  public:
    Tokenizer();
    std::vector<int> tokenize(std::string tokenSequence);

    std::unordered_map<std::string, int> getMergeRules() const;
    void setMergeRules(std::unordered_map<std::string, int> rules);
    
    std::unordered_map<std::string, int> getVocabTable() const;
    void setVocabTable(std::unordered_map<std::string, int> vocab); 

  private:
    std::unordered_map<std::string, int> mergeRules;  
    std::unordered_map<std::string, int> vocabTable;
};

