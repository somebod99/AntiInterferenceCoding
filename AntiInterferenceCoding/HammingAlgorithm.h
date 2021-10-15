#ifndef HAMMINGALGORITHM_H
#define HAMMINGALGORITHM_H

#include "Tools.h"

/*
* n - длина кодового слова (9)
* k - количество информационных бит (5)
* r = n - k - количество проверочных бит (9 - 5 = 4)
*/

/*
* G(n,k) = |I(k,k), R(k,r)|
*/

/*
*			|1 0 0 0 0|0 1 0 1|
*			|0 1 0 0 0|1 0 1 1|
*G(n,k)	=	|0 0 1 0 0|1 1 0 0|
*			|0 0 0 1 0|0 1 1 0|
*			|0 0 0 0 1|0 0 1 1|
*/

/* Кодирование
* (+ == xor)
* A = {[0-9] & 'a'-'v'} dimA = 32
*
* Пример:
* 7 -> [0 0 1 1 1] = [i0 i1 i2 i3 i4] = v
* v * G = [0 0 1 1 1 r0 r1 r2 r3] = [0 0 1 1 1 1 0 0 1]
* r0 = i1 + i2
* r1 = i0 + i2 + i3
* r2 = i1 + i3 + i4
* r3 = i0 + i1 + i4
*
* r0 = [1, 2]
* r1 = [0, 2, 3]
* r2 = [1, 3, 4]
* r3 = [0, 1, 4]
*
*										r0							r1							r2								r3
* [v[0], v[1], v[2], v[3], v[4], v[r[0]] + v[r[1]], v[r[0]] + v[r[1]] + v[r[2]], v[r[0]] + v[r[1]] + v[r[2]], v[r[0]] + v[r[1]] + v[r[2]]]
*/

class HammingEncoder
{
public:
    HammingEncoder(const std::string& g_matrix_path, const std::string& alphabet_path);
    ~HammingEncoder();

    std::vector<bool> EncodeFromTxtFile(const std::string& encode_path) const;
    std::vector<bool> EncodeString(const std::string& encoding_string) const;

    const std::map<std::string, std::vector<bool>>& getCodes() const;

private:
    void CreateCodes(const std::string& alphabet_path, const std::vector<std::vector<int>>& r);

    std::map<std::string, std::vector<bool>> codes;
    int max_length_alphabet;
    int code_length;
};

/*
* H(n,k) = |R^t(r,k), I(r,r)|
*/

/*
*			|0 1 1 0 0|1 0 0 0|
*			|1 0 1 1 0|0 1 0 0|
*H(n,k)	=	|0 1 0 1 1|0 0 1 0|
*			|1 1 0 0 1|0 0 0 1|
*/

/* Декодирование
*
* v' - искаженное кодовое слово
* v' * H^t = S
* S - синдром, dimS = n - k = r
* if S = 0-вектору -> в v' не было ошибок
* else номер разряда в котором возникла ошибка = десятичному представлению вектора S, в котором 0 разряд начинается с конца вектора
*
* Пример:
* S = [s0, s1, s2, s3]
*
* s0 = v1 + v2 + v5
* s1 = v0 + v2 + v3 + v6
* s2 = v1 + v3 + v4 + v7
* s3 = v0 + v1 + v4 + v8
*/

class HammingDecoder
{
public:
    HammingDecoder(const std::string& g_matrix_path, const std::string& alphabet_path);
    ~HammingDecoder();

    std::string DecodeFromBinaryFile(const std::string& decode_path, std::string& errors) const;
    std::string DecodeBinarySequence(const std::vector<bool>& decode_sequence, std::string& errors) const;

    int getLengthCode() const;

private:
    void CreateCodes(const std::map<std::string, std::vector<bool>>& codes);
    void FillSyndromeVector(const std::string& g_matrix_path);

    std::map<std::vector<bool>, std::string> codes;
    std::vector<std::vector<int>> s;
};

#endif // HAMMINGALGORITHM_H
