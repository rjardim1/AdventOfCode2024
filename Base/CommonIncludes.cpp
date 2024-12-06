
#include "CommonIncludes.h"

string ReadFile(const EDay day, const EDataType type)
{
    const string cwd = filesystem::current_path().string();

    string data_subdirectory = "";

    switch (type)
    {
        case EDataType::eTestData:
            data_subdirectory = "TestData";
            break;
        case EDataType::eRealData:
            data_subdirectory = "RealData";
            break;
        default:
            break;
    }

    string file_name(cwd + R"(\..\..\..\..\)" + 
        data_subdirectory + R"(\Day)" + to_string(static_cast<int>(day)) + R"(.txt)");

    ifstream source_file(file_name);
    stringstream source_file_ss;

    source_file_ss << source_file.rdbuf();
    return source_file_ss.str();

}

regex_matches_type GetRegexMatches(const string data, const regex regex_str)
{
    regex_matches_type matches;
    auto words_end = sregex_iterator();
    auto words_begin = sregex_iterator(data.begin(), data.end(), regex_str);

    for (sregex_iterator word = words_begin; word != words_end; ++word)
    {
        string str_in_file = word->str();
        smatch match;

        if (regex_search(str_in_file, match, regex_str))
        {
            vector<string> regex_matches;

            for (const auto& matched_data : match)
            {
                cout << matched_data << endl;
                regex_matches.push_back(matched_data);
            }

            matches.push_back(regex_matches);
        }
    }

    return matches;
}

bool StringContainsOnlyNumbers(const string data)
{
    return !data.empty() && all_of(data.begin(), data.end(), ::isdigit);
}

