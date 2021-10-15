#include "GilberMoorParityCheck.h"

#include <fstream>
#include <cmath>

GilberMoorEncoder::GilberMoorEncoder(const std::string& alphabet_path) : max_length_alphabet(0)
{
    std::ifstream file(alphabet_path);

    if (!file.is_open())
    {
        std::string error_message = "file " + alphabet_path + " cannot be opened";
        throw error_message.c_str();
    }

    std::string symbol;
    double p_k = 0.0;
    int l_k = 0;
    double q_k = 0.0;
    double sigma_k = 0.0;

    while (!file.eof())
    {
        file >> symbol >> p_k;

        if (this->codes.count(symbol))
        {
            std::string err = "Read alphabet error: symbol '" + symbol + "' already exist";
            throw err.c_str();
        }

        if (p_k == 0.0)
            throw "Creating codes for symbols error: incorrect alphabet";

        if (symbol.size() > this->max_length_alphabet)
            this->max_length_alphabet = symbol.size();

        sigma_k = q_k + p_k / 2;

        // the sum of the probabilities of occurrence of the symbols of the alphabet
        q_k += p_k;

        // k-th symbol length
        l_k = std::ceil(-std::log2(p_k / 2));

        this->codes[symbol] = DoubleToBinary(sigma_k, l_k);
    }

    file.close();
}

GilberMoorEncoder::~GilberMoorEncoder()
{
}

std::vector<bool> GilberMoorEncoder::EncodeFromTxtFile(const std::string& encode_path) const
{
    return EncodeString(ReadFromTxtFile(encode_path));
}

std::vector<bool> GilberMoorEncoder::EncodeFromTxtFileWithParityCheck(const std::string& encode_path) const
{
    std::vector<bool> res;
    int index = 0;
    int sum = 0;

    for (const auto& bit : EncodeFromTxtFile(encode_path))
    {
        if (index == 2)
        {
            res.push_back(sum % 2);

            index = 0;
            sum = 0;
        }

        sum += bit;
        ++index;

        res.push_back(bit);
    }

    res.push_back(sum % 2);

    return res;
}

std::vector<bool> GilberMoorEncoder::EncodeString(const std::string& encoding_string) const
{
    return MapEncode(encoding_string, this->max_length_alphabet, this->codes);
}

const std::map<std::string, std::vector<bool>>& GilberMoorEncoder::getCodes() const
{
    return this->codes;
}

std::vector<bool> GilberMoorEncoder::DoubleToBinary(double p, const int& l) const
{
    std::vector<bool> res;

    for (int i = 0; i < l; ++i)
    {
        p *= 2;
        res.push_back(int(p));
        p -= int(p);
    }

    return res;
}

GilberMoorDecoder::GilberMoorDecoder(const std::string& alphabet_path) : HaffmanTree(new Node()), code_length(0)
{
    auto codes = GilberMoorEncoder(alphabet_path).getCodes();
    this->code_length = codes.begin()->second.size();

    for (const auto& key_value : codes)
    {
        Node* cur = HaffmanTree;

        for (const auto& bit : key_value.second)
        {
            if (bit)
            {
                if (cur->r == nullptr)
                    cur->r = new Node();

                cur = cur->r;
            }
            else
            {
                if (cur->l == nullptr)
                    cur->l = new Node();

                cur = cur->l;
            }
        }

        cur->symbol = key_value.first;
        cur = this->HaffmanTree;
    }
}

GilberMoorDecoder::~GilberMoorDecoder()
{
    delete this->HaffmanTree;
}

std::string GilberMoorDecoder::DecodeFromBinaryFile(const std::string& decode_path) const
{
    auto decoded_sequence = ReadFromBinaryFile(decode_path);

    return DecodeBinarySequence(decoded_sequence);
}

std::string GilberMoorDecoder::DecodeFromBinaryFileWithParityCheck(const std::string& decode_path, std::string& errors) const
{
    int parity_length = this->code_length + this->code_length / 2;

    auto decoding_sequence = ReadFromBinaryFile(decode_path);

    if (!decoding_sequence.size() || decoding_sequence.size() % parity_length != 0)
        throw "Decoding error: incorrect count bits in sequence";

    std::string res;
    errors = "";

    std::vector<bool> one_code(this->code_length);
    int index_check = 1;
    int index_code = 0;
    int sum = 0;

    int size = decoding_sequence.size();

    for (int i = 0; i < size; ++i)
    {
        sum += decoding_sequence[i];

        if (index_check == parity_length)
        {
            if (sum % 2 == 1)
            {
                res += "*";
                errors += std::to_string(((i + 1) / parity_length)) + " ";
            }
            else
                res += DecodeBinarySequence(one_code);

            index_code = 0;
            index_check = 1;
            sum = 0;
            continue;
        }

        if (index_check % (parity_length / 2) == 0)
        {
            ++index_check;
            continue;
        }

        one_code[index_code] = decoding_sequence[i];

        ++index_code;
        ++index_check;
    }

    if (errors.size())
        errors.erase(errors.cend() - 1);

    return res;
}

std::string GilberMoorDecoder::DecodeBinarySequence(const std::vector<bool>& decode_sequence) const
{
    Node* cur = this->HaffmanTree;
    std::string res;

    for (const auto& bit : decode_sequence)
    {
        if (bit)
            cur = cur->r;
        else
            cur = cur->l;

        if (cur == nullptr)
            return "?";

        if (cur->symbol != "")
        {
            res += cur->symbol;
            cur = this->HaffmanTree;
        }
    }

    return res;
}
