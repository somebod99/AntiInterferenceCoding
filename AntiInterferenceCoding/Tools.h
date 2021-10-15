#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

std::vector<bool> ReadFromBinaryFile(const std::string& file_path);
std::string ReadFromTxtFile(const std::string& file_path);
void WriteToBinaryFile(const std::string& file_path, const std::vector<bool>& encode);

std::vector<bool> MapEncode(const std::string& encoding_string, const int& max_length_alphabet,
    const std::map<std::string, std::vector<bool>>& codes);

std::vector<std::vector<int>> CreateCheckBitsVectors(const std::string& g_matrix_path, int* code_length = nullptr);

#endif // TOOLS_H
