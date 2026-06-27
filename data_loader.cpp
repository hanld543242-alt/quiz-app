#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

vector<Question> DataLoader::loadData(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "[Lỗi] Không thể mở file dữ liệu: " << filename << endl;
        return questions;
    }

    string line;
    while (getline(file, line)) {
        line = trim(line);
        if (line.empty()) continue;

        if (isdigit(line[0]) && line.find("-->") == string::npos) {
            stringstream ss(line);
            int q_id;
            ss >> q_id;
            
            string q_text;
            getline(ss, q_text);
            q_text = trim(q_text);

            vector<string> q_options;
            char q_answer = ' ';
            string sub_line;

            while (getline(file, sub_line)) {
                sub_line = trim(sub_line);
                if (sub_line.empty()) continue;

                if (sub_line.find("-->") != string::npos && sub_line.find_first_not_of("0123456789--> ") != string::npos) {
                    continue; 
                }
                if (sub_line.size() == 1 && isdigit(sub_line[0])) {
                    continue; 
                }

                if (sub_line.size() == 1 && isalpha(sub_line[0])) {
                    q_answer = tolower(sub_line[0]);
                    break; 
                }

                stringstream option_ss(sub_line);
                string token;
                while (option_ss >> token) {
                    q_options.push_back(token);
                }
            }

            questions.push_back(Question(q_id, q_text, q_options, q_answer));
        }
    }

    file.close();
    return questions;
}

void DataLoader::printQuestions(const vector<Question>& questions) {
    cout << "\n========================================================" << endl;
    cout << "       KẾT QUẢ NGHIỆM THU DỮ LIỆU FEATURE/DATA-LOADER     " << endl;
    cout << "========================================================" << endl;
    cout << ">>> Tổng số câu hỏi đọc được từ file: " << questions.size() << " câu. <<<\n" << endl;

    for (const auto& q : questions) {
        cout << "--------------------------------------------------------" << endl;
        cout << " CÂU HỎI SỐ " << q.getId() << ":" << endl;
        cout << "   Nội dung: " << q.getQuestionText() << endl;
        cout << "   Danh sách các lựa chọn đáp án:" << endl;
        
        auto opts = q.getOptions();
        for (size_t i = 0; i < opts.size(); ++i) {
            cout << "     [" << (char)('a' + i) << "] " << opts[i] << endl;
        }
        
        cout << "   => CHỌN RA ĐÁP ÁN ĐÚNG: " << q.getCorrectAnswer() << endl;
    }
    cout << "========================================================\n" << endl;
}
