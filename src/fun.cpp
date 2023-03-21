// Copyright 2022 UNN-IASR
#include <cctype>

#include <cmath>

#include "fun.h"

unsigned int faStr1(const char* str) {
	int count = 0;
	bool in_word = false;
	bool contains_letters = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (!in_word && str[i] != ' ') {
			if (!isdigit(str[i])) {
				contains_letters = true;
			}
			in_word = true;
		}
		else if (in_word && str[i] != ' ' && contains_letters) {
			if (isdigit(str[i])) {
				contains_letters = false;
				count++;
			}
		}
		else if (in_word && str[i] == ' ') {
			if (contains_letters) {
				count++;
			}
			contains_letters = false;
			in_word = false;
		}
	}
	if (in_word && contains_letters) {
		count++;
	}
	return count;
}

unsigned int faStr2(const char* str) {
	int count = 0;
	bool in_word = false;
	bool contains_uppercase = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (!in_word && isupper(str[i])) {
			in_word = true;
			contains_uppercase = true;
		}
		else if (in_word && str[i] != ' ' && contains_uppercase) {
			if (!isupper(str[i]) && isalpha(str[i])) {
				contains_uppercase = false;
				count++;
			}
		}
		else if (in_word && str[i] == ' ') {
			if (contains_uppercase) {
				count++;
			}
			contains_uppercase = false;
			in_word = false;
		}
	}
	if (in_word && contains_uppercase) {
		count++;
	}
	return count;
}

unsigned int faStr3(const char* str) {
	int count = 0;
	int length = 0;
	bool in_word = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (!in_word && str[i] != ' ') {
			count++;
			length++;
			in_word = true;
		}
		else if (in_word && str[i] != ' ') {
			length++;
		}
		else if (in_word && str[i] == ' ') {
			in_word = false;
			if (length > 0) {
				count++;
			}
			length = 0;
		}
	}
	if (in_word && length > 0) {
		count++;
	}
	return static_cast<int>(round(static_cast<float>(length) / static_cast<float>(count)));
}
