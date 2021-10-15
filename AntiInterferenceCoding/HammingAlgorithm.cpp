#include "HammingAlgorithm.h"

#include <fstream>
#include <cmath>


HammingEncoder::HammingEncoder(const std::string& g_matrix_path, const std::string& alphabet_path) : code_length(0), max_length_alphabet(0)
{
    auto r = CreateCheckBitsVectors(g_matrix_path, &this->code_length);
    CreateCodes(alphabet_path, r);
}

HammingEncoder::~HammingEncoder()
{
}

std::vector<bool> HammingEncoder::EncodeFromTxtFile(const std::string& encode_path) const
{
    return EncodeString(ReadFromTxtFile(encode_path));
}

std::vector<bool> HammingEncoder::EncodeString(const std::string& encoding_string) const
{
    return MapEncode(encoding_string, this->max_length_alphabet, this->codes);
}

const std::map<std::string, std::vector<bool>>& HammingEncoder::getCodes() const
{
    return this->codes;
}

void HammingEncoder::CreateCodes(const std::string& alphabet_path, const std::vector<std::vector<int>>& r)
{
    std::ifstream file(alphabet_path);

    std::string symbol;
    std::string info_code;
    std::vector<bool> res_code(this->code_length);

    while (!file.eof())
    {
        file >> symbol >> info_code;

        if (this->codes.count(symbol))
        {
            std::string err = "Read alphabet error: symbol '" + symbol + "' already exist";
            throw err.c_str();
        }

        if (info_code.size() != (this->code_length - r.size()))
            throw "Read alphabet error: incorrect length of info code";

        if (symbol.size() > this->max_length_alphabet)
            this->max_length_alphabet = symbol.size();

        bool elem;
        int i = 0;

        for (const auto& bit : info_code)
        {
            if (bit == '1')
                res_code[i] = true;
            else
                res_code[i] = false;

            ++i;
        }

        for (int k = 0; i < this->code_length; ++i, ++k)
        {
            int sum = 0;

            for (int j = 0; j < r[k].size(); ++j)
                sum += res_code[r[k][j]];

            res_code[i] = sum % 2;
        }

        this->codes[symbol] = res_code;
    }
}

HammingDecoder::HammingDecoder(const std::string& g_matrix_path, const std::string& alphabet_path)
{
    auto codes = HammingEncoder(g_matrix_path, alphabet_path).getCodes();

    CreateCodes(codes);
    FillSyndromeVector(g_matrix_path);
}

HammingDecoder::~HammingDecoder()
{
}

std::string HammingDecoder::DecodeFromBinaryFile(const std::string& decode_path, std::string& errors) const
{
    return DecodeBinarySequence(ReadFromBinaryFile(decode_path), errors);
}

std::string HammingDecoder::DecodeBinarySequence(const std::vector<bool>& decode_sequence, std::string& errors) const
{
    if (decode_sequence.size() % getLengthCode() != 0)
    {
        std::string err = "Decode error: the length of the decoded sequence must be a multiple of " + std::to_string(getLengthCode());
        throw err.c_str();
    }

    std::string res;
    std::vector<bool> syndrome(this->s.size());
    errors = "";

    for (int i = 0; i < decode_sequence.size(); i += getLengthCode())
    {
        int err_index = 0;
        int s_size = this->s.size();

        for (const auto& s_i : this->s)
        {
            --s_size;
            int sum = 0;

            for (const auto& index : s_i)
                sum += decode_sequence[index + i];

            if (sum % 2)
            {
                err_index += std::pow(2, s_size);
                syndrome[syndrome.size() - s_size - 1] = true;
            }
            else
                syndrome[syndrome.size() - s_size - 1] = false;
        }

        std::vector<bool> word(decode_sequence.begin() + i, decode_sequence.begin() + i + getLengthCode());

        bool flag = false;
        int ind;

        if (err_index != 0)
        {
            err_index = 0;

            for (int w = 0; w < syndrome.size(); ++w)
            {
                if (syndrome[w])
                {
                    ind = w;

                    for (int j = 0; j < this->s.size(); ++j)
                    {
                        if (w != j && syndrome[w] != syndrome[j])
                        {
                            for (int l = err_index; l < this->s[w].size(); ++l)
                            {
                                flag = false;

                                for (int k = 0; k < this->s[j].size(); ++k)
                                {
                                    if (this->s[j][k] == this->s[w][l])
                                    {
                                        flag = true;
                                        break;
                                    }
                                }

                                if (!flag)
                                {
                                    err_index = l;
                                    break;
                                }
                                else
                                {
                                    j = -1;
                                    err_index = l + 1;
                                    break;
                                }
                            }
                        }
                    }

                    if (!flag)
                        break;
                }
            }

            errors += "Word number: " + std::to_string((i / getLengthCode()) + 1) + '\n' + "Bit index: " + std::to_string(this->s[ind][err_index] + 1) + '\n';

            word[this->s[ind][err_index]] = !word[this->s[ind][err_index]];
        }

        if (!this->codes.count(word))
            res += "?";
        else
            res += this->codes.at(word);
    }

    return res;
}

int HammingDecoder::getLengthCode() const
{
    return this->codes.begin()->first.size();
}

void HammingDecoder::CreateCodes(const std::map<std::string, std::vector<bool>>& codes)
{
    for (const auto& key_value : codes)
        this->codes[key_value.second] = key_value.first;
}

void HammingDecoder::FillSyndromeVector(const std::string& g_matrix_path)
{
    this->s = CreateCheckBitsVectors(g_matrix_path);

    int k = getLengthCode() - s.size();

    for (auto& s_i : s)
    {
        s_i.push_back(k);
        ++k;
    }
}
