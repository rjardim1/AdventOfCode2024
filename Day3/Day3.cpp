
// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"

using namespace std;

int main()
{
    string line;
    ifstream file("D:\\AdventOfCode2024\\Day3\\TestData.txt");
    int result = 0;

    while (getline(file, line))
    {
        std::regex mul_regex(R"(mul\(([0-9]+),([0-9]+)\))");
        auto words_end = std::sregex_iterator();
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            cout << match_str << endl;
            
            stringstream line_stream(line);
            const char seperator = ',';
            string number = "";
            vector<int> list;

            while (getline(line_stream, number, seperator))
            {
                list.push_back(stoi(number));
            }
        }

    }

    cout << result << endl;
}