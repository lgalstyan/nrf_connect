/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2013-2017 Nest Labs, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file implements an object for Verhoeff's check-digit
 *      algorithm for base-36 strings.
 *
 */
#include "Verhoeff.h"

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef VERHOEFF36_NO_MULTIPLY_TABLE

const uint8_t Verhoeff36::sMultiplyTable[] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 18, 2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  1,  20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  1,
    2,  3,  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16,
    17, 0,  1,  2,  3,  4,  23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 6,  7,  8,  9,  10, 11, 12, 13,
    14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 7,  8,  9,  10,
    11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24,
    8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21,
    22, 23, 24, 25, 9,  10, 11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  27, 28, 29, 30, 31, 32, 33, 34, 35, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 10, 11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  28, 29, 30, 31, 32, 33,
    34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 11, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 29, 30,
    31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 12, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 30, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 13, 14, 15, 16, 17, 0,  1,  2,  3,  4,  5,  6,
    7,  8,  9,  10, 11, 12, 31, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 14, 15, 16, 17, 0,  1,  2,  3,
    4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 32, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 15, 16, 17, 0,
    1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 33, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    16, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 34, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 35, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 0,  17, 16, 15, 14, 13,
    12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 1,  0,
    17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,
    22, 21, 2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  21, 20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28,
    27, 26, 25, 24, 23, 22, 3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  22, 21, 20, 19, 18, 35, 34, 33,
    32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  23, 22, 21, 20,
    19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,
    24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11,
    10, 9,  8,  7,  25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 7,  6,  5,  4,  3,  2,  1,  0,  17, 16,
    15, 14, 13, 12, 11, 10, 9,  8,  26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 27, 8,  7,  6,  5,  4,  3,
    2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 9,  27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 31, 30, 29, 28, 9,  8,
    7,  6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 10, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 31,
    30, 29, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 11, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18,
    35, 34, 33, 32, 31, 30, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 12, 30, 29, 28, 27, 26, 25, 24, 23,
    22, 21, 20, 19, 18, 35, 34, 33, 32, 31, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14, 13, 31, 30, 29, 28,
    27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 32, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  17, 16, 15, 14,
    32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 33, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,
    0,  17, 16, 15, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 34, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,
    5,  4,  3,  2,  1,  0,  17, 16, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 35, 16, 15, 14, 13, 12, 11,
    10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  17, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,
    15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0,
};

#endif // VERHOEFF36_NO_MULTIPLY_TABLE

const uint8_t Verhoeff36::sPermTable[] = { 29, 0,  32, 11, 35, 20, 7,  27, 2,  4,  19, 28, 30, 1,  5,  12, 3,  9,
                                           16, 22, 6,  33, 8,  24, 26, 21, 14, 10, 34, 31, 15, 25, 17, 13, 23, 18 };

const int8_t Verhoeff36::sCharToValTable[] = {
    // NOTE: table starts at ASCII 30h
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  -1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1, -1, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
};

const char Verhoeff36::sValToCharTable[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char Verhoeff36::ComputeCheckChar(const char * str)
{
    return ComputeCheckChar(str, strlen(str));
}

char Verhoeff36::ComputeCheckChar(const char * str, size_t strLen)
{
    int c = 0;

    for (size_t i = 1; i <= strLen; i++)
    {
        char ch = str[strLen - i];

        int val = CharToVal(ch);
        if (val < 0)
            return 0; // invalid character

        int p = Verhoeff::Permute(val, sPermTable, Base, i);

#ifdef VERHOEFF36_NO_MULTIPLY_TABLE
        c = Verhoeff::DihedralMultiply(c, p, PolygonSize);
#else
        c = sMultiplyTable[c * Base + p];
#endif
    }

    c = Verhoeff::DihedralInvert(c, PolygonSize);

    return ValToChar(c);
}

bool Verhoeff36::ValidateCheckChar(char checkChar, const char * str)
{
    return ValidateCheckChar(checkChar, str, strlen(str));
}

bool Verhoeff36::ValidateCheckChar(char checkChar, const char * str, size_t strLen)
{
    return (ComputeCheckChar(str, strLen) == checkChar);
}

bool Verhoeff36::ValidateCheckChar(const char * str)
{
    return ValidateCheckChar(str, strlen(str));
}

bool Verhoeff36::ValidateCheckChar(const char * str, size_t strLen)
{
    if (strLen == 0)
        return false;
    return ValidateCheckChar(str[strLen - 1], str, strLen - 1);
}

int Verhoeff36::CharToVal(char ch)
{
    if (ch >= '0' && ch <= 'z')
        return sCharToValTable[static_cast<int>(ch) - '0'];
    return -1;
}

char Verhoeff36::ValToChar(int val)
{
    if (val >= 0 && val < Base)
        return sValToCharTable[val];
    return 0;
}
