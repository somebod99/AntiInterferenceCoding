#ifndef GILBERMOORPARITYCHECK_H
#define GILBERMOORPARITYCHECK_H

#include "Tools.h"

class GilberMoorEncoder
{
public:
    GilberMoorEncoder(const std::string& alphabet_path);
    ~GilberMoorEncoder();

    std::vector<bool> EncodeFromTxtFile(const std::string& encode_path) const;
    std::vector<bool> EncodeFromTxtFileWithParityCheck(const std::string& encode_path) const;
    std::vector<bool> EncodeString(const std::string& encoding_string) const;

    const std::map<std::string, std::vector<bool>>& getCodes() const;

private:
    std::vector<bool> DoubleToBinary(double, const int&) const;

    std::map<std::string, std::vector<bool>> codes;
    int max_length_alphabet;
};

class Node
{
public:
    Node* r;
    Node* l;
    std::string symbol;

    Node() : r(nullptr), l(nullptr) {}
    ~Node()
    {
        delete r;
        delete l;
    }
};

class GilberMoorDecoder
{
public:
    GilberMoorDecoder(const std::string& alphabet_path);
    ~GilberMoorDecoder();

    std::string DecodeFromBinaryFile(const std::string& decode_path) const;
    std::string DecodeFromBinaryFileWithParityCheck(const std::string& decode_path, std::string& errors) const;
    std::string DecodeBinarySequence(const std::vector<bool>& decode_sequence) const;

private:
    Node* HaffmanTree;
    int code_length;
};

#endif // GILBERMOORPARITYCHECK_H
