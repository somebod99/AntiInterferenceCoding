#include "Tools.h"

std::vector<bool> ReadFromBinaryFile(const std::string& file_path)
{
    std::ifstream file(file_path, std::ios::binary);

    int bits_count = 0;

    file.read(reinterpret_cast<char*>(&bits_count), sizeof(bits_count));

    if (!bits_count)
        return std::vector<bool>();

    std::vector<bool> res(bits_count);

    int bytes_count = bits_count / 8;

    if (bits_count % 8 != 0)
        ++bytes_count;

    std::vector<char> bytes(bytes_count, '\0');
    file.read(&bytes[0], bytes_count);

    bool bit;
    int bit_index = 7;
    int byte_index = 0;

    for (int i = 0; i < bits_count; ++i)
    {
        bit = bytes[byte_index] & (1 << bit_index--);
        res[i] = bit;

        if (bit_index == -1)
        {
            bit_index = 7;
            ++byte_index;
        }
    }

    return res;
}

std::string ReadFromTxtFile(const std::string& file_path)
{
    std::ifstream file(file_path, std::ifstream::binary);

    if (!file.is_open())
    {
        std::string error_message = "file " + file_path + " cannot be opened";
        throw error_message.c_str();
    }

    file.seekg(0, file.end);
    auto size = file.tellg();
    file.seekg(0, file.beg);

    std::string res(size, '\0');

    file.read(&res[0], size);

    return res;
}

void WriteToBinaryFile(const std::string& file_path, const std::vector<bool>& encode)
{
    int bytes_count = encode.size() / 8;

    if (encode.size() % 8 != 0)
        ++bytes_count;

    std::vector<char> bytes(bytes_count, '\0');

    int byte_index = 0;
    int bit_index = 0;

    for (const auto& bit : encode)
    {
        if (bit)
            bytes[byte_index] |= 1 << (7 - bit_index);

        ++bit_index;

        if (bit_index == 8)
        {
            ++byte_index;
            bit_index = 0;
        }
    }

    std::ofstream file(file_path, std::ios::binary);

    int size = encode.size();

    if (size)
    {
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(&bytes[0], bytes_count);
    }

    file.close();

    return;
}

std::vector<bool> MapEncode(const std::string& encoding_string, const int& max_length_alphabet, const std::map<std::string, std::vector<bool>>& codes)
{
    std::vector<bool> res;
    std::string cur;

    for (int i = 0, j = max_length_alphabet; i < encoding_string.size(); ++i, --j)
    {
        cur += encoding_string[i];

        if (codes.count(cur))
        {
            for (const auto& bit_in_code : codes.at(cur))
                res.push_back(bit_in_code);

            cur = "";
            j = max_length_alphabet;
        }

        if (j == 0)
            throw "Encoding error: incorrect symbol in sequence";
    }

    if (cur != "")
        throw "Encoding error: incorrect symbol in sequence";

    return res;
}

std::vector<std::vector<int>> CreateCheckBitsVectors(const std::string& g_matrix_path, int* code_length)
{
    std::ifstream file(g_matrix_path);

    int n = 0;
    int k = 0;
    file >> n >> k;

    if (n <= 0 || k <= 0)
        throw "Read G matrix error: sizes matrix must be bigger then 0";

    if(code_length)
        *code_length = n;

    std::vector<std::vector<int>> r(n - k);

    std::string line;
    int row = 0;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        iss.seekg(0, iss.end);

        if (iss.tellg() != (2 * n - 1))
        {
            std::string err = "Read G matrix error: the number of columns must be " + std::to_string(n);
            throw err.c_str();
        }

        iss.seekg(0, iss.beg);

        int elem;
        int column = 0;

        while (iss >> elem)
        {
            if (elem < 0 || elem > 1)
                throw "Read G matrix error: elements of G matrix must be 0 or 1";

            if (column >= k)
            {
                if (elem)
                {
                    r[column - k].push_back(row);
                }
            }
            else if (column == row)
                if (!elem)
                    throw "Read G matrix error: incorrect matrix";

            ++column;
        }

        ++row;
    }

    if (row < k)
    {
        std::string err = "Read G matrix error: the number of rows must be " + std::to_string(k);
        throw err.c_str();
    }

    file.close();

    return r;
}
