
// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"

using namespace std;

int main()
{
    int result = 0;
    string file_name(R"(E:\AdventOfCode2024\Day3\TestData.txt)");
    ifstream source_file(file_name);
    stringstream source_file_ss;
    source_file_ss << source_file.rdbuf();
    const string source_file_str = source_file_ss.str();

    std::regex mul_regex(R"(mul\(([0-9]+),([0-9]+)\))");
    auto words_end = std::sregex_iterator();
    auto words_begin = std::sregex_iterator(source_file_str.begin(), source_file_str.end(), mul_regex);

    for (std::sregex_iterator word = words_begin; word != words_end; ++word)
    {
        string str_in_file = word->str();
        std::smatch match;

        if (std::regex_search(str_in_file, match, mul_regex))
        {
            vector<int> regex_matches;

            for (const auto& matched_data : match)
            {
                string data = matched_data.str();

                if (!data.empty() && std::all_of(data.begin(), data.end(), ::isdigit))
                {
                    regex_matches.push_back(stoi(data));
                }
            }

            result += regex_matches.at(0) * regex_matches.at(1);
        }
    }

    cout << result << endl;
}
