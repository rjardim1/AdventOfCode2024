#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <filesystem>

using namespace std;

using regex_matches_type = vector<vector<string>>;

enum EDay
{
    eDay1 = 1,
    eDay2,
    eDay3,
    eDay4,
    eDay5,
    eDay6,
    eDay7,
    eDay8,
    eDay9,
    eDay10,
    eDay11,
    eDay12,
    eDay13,
    eDay14,
    eDay15,
    eDay16,
    eDay17,
    eDay18,
};

enum EDataType
{
    eTestData,
    eRealData,
};

string ReadFile(const EDay day, const EDataType type);

regex_matches_type GetRegexMatches(const string data, const regex regex_str);

bool StringContainsOnlyNumbers(const string data);
