#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <filesystem>

using namespace std;

/// @brief regex matches type
using regex_matches_type = vector<vector<string>>;

/// @brief 
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

/// @brief 
enum EDataType
{
    eTestData,
    eRealData,
};

/// @brief Reads the data file for a day and type
/// @param day The day of AoC file to read
/// @param type Test data or Real data file used
/// @return The file content in a string
string ReadFile(const EDay day, const EDataType type);

/// @brief 
/// @param data 
/// @param regex_str 
/// @return 
regex_matches_type GetRegexMatches(const string data, const regex regex_str);

/// @brief 
/// @param data 
/// @return 
bool StringContainsOnlyNumbers(const string data);
