// Copyright 2022 UNN-IASR
#include <iostream>
#include <cstring>
#include <cmath>

#include "fun.h"

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool in_word = false;
    bool has_digit = false;

    while (*str) {
        if ((*str >= '0') && (*str <= '9')) {
            has_digit = true;
        }
        else if (isalpha(*str)) {
            if (!in_word) {
                in_word = true;
            }
        }
        else {
            if (in_word && !has_digit) {
                count++;
            }
            in_word = false;
            has_digit = false;
        }
        str++;
    }

    if (in_word && !has_digit) {
        count++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    int i = 0;
    int count = 0;
    int in = 0;
    int F = 0;
    while (str[i] != '\0') {
        if (in == 0 && str[i] >= 65 && str[i] <= 90) {
            in = 1;
            F = 1;
        }
        else if (in == 1) {
            if ((str[i] != ' ') && (F == 1)) {
                if ((str[i] >= 65) && (str[i] <= 90)) {
                    F = 0;
                }
                else if ((str[i] > 122) || (str[i] < 97)) {
                    F = 0;
                }
            }
            else if (str[i] == ' ') {
                if (F == 1) {
                    count++;
                }
                F = 0;
                in = 0;
            }
            else if ((F == 1) && (str[i + 1] == '\0')) {
                count++;
            }
        }
        i++;
    }

    return count;
}
unsigned int faStr3(const char* str) {
    unsigned int word_count = 0;
    unsigned int character_count = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            in_word = true;
            character_count++;
        }
        else {
            if (c >= 'a' && c <= 'z') {
                in_word = true;
                character_count++;
            }
            else {
                if (in_word) {
                    word_count++;
                    in_word = false;
                }
            }
        }

        if (in_word) {
            word_count++;
        }

        float average = static_cast<float>(character_count) / static_cast<float>(word_count);
        int rounded_average = static_cast<int>(round(average));

        return rounded_average;
    }
