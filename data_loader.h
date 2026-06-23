 #ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <iostream>
#include <vector>
#include <string>

class Question {
private:
    int id;                           
    std::string question_text;        
    std::vector<std::string> options; 
    char correct_answer;              

public:
    Question() : id(0), correct_answer(' ') {}
    Question(int id, const std::string& text, const std::vector<std::string>& opts, char answer)
        : id(id), question_text(text), options(opts), correct_answer(answer) {}

    int getId() const { return id; }
    std::string getQuestionText() const { return question_text; }
    std::vector<std::string> getOptions() const { return options; }
    char getCorrectAnswer() const { return correct_answer; }
};

class DataLoader {
public:
    static std::vector<Question> loadData(const std::string& filename);
    static void printQuestions(const std::vector<Question>& questions);
};

#endif 
