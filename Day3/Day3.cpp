
// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"

int main()
{
    int result = 0;

    const string source_file_str = ReadFile(EDay::eDay3, EDataType::eTestData);

    regex mul_regex(R"(mul\(([0-9]+),([0-9]+)\))");

    regex_matches_type matches = GetRegexMatches(source_file_str, mul_regex);

    if (matches.size() >= 3)
    {
        for (const auto &match : matches)
        {
            string num1 = match.at(1);
            string num2 = match.at(2);

            if (StringContainsOnlyNumbers(num1) && StringContainsOnlyNumbers(num2))
            {
                result += stoi(num1) * stoi(num2);
            }
        }
    }

    cout << result << endl;
}
