#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <map>
#include "Header.h"

using namespace std;

Encryption::Encryption() {}

Encryption::Encryption(std::string s)
{
	alreadyDec = true;
	message = s;
 }

void Encryption::keyWordPicker() {
	std::cout << "Keyword must contain each letter A-Z exactly once, no repetition of letter should occur" << std::endl;
	std::cout << "Enter keyword: ";
	std::getline(std::cin, keyWord);
	//keyword to uppercase
	for (int i = 0; i < keyWord.length(); i++) {
		keyWord[i] = toupper(keyWord[i]);
	}

	//checking repetition of letter in keyword
	for (int i = 0; i < keyWord.length(); i++) {
		int pos = i;
		for (int j = 0; j < keyWord.length(); j++) {
			if (pos == j) {
				continue;
			}
			else if (keyWord[i] == keyWord[j]) {
				std::cout << "Letter \"" << keyWord[i] << "\" Repeating in keyword" << std::endl;
				exit(EXIT_FAILURE); // terminating the program
			}
		}
	}

	//generating alphabet with keyword
	std::string temp = "";
	for (int i = 0; i < keyWord.length(); i++) {
		temp += keyWord[i];
	}
	for (int i = 0; i < 26; i++) {
		temp += (char)(i + 65);
	}

	//removing letters of keyword from alphabet
	for (int i = 0; i < temp.length(); i++) {
		bool found = false;
		for (int j = 0; j < keyWord.length(); j++) {
			if (temp[i] == keyWord[j]) {
				found = true;
				break; // no need to iterate any further
			}
		} // inner for
		if (found == false) {
			keyWord += temp[i];
		}
	}
}

void Encryption::encryptString()
{
	//iterate through the inputted message and convert everything to uppercase
	for (int i = 0; i < message.length(); i++) {
		message[i] = toupper(message[i]);
	}

	for (int i = 0; i < message.length(); i++) {
		if (message[i] == ' ') {
			encrypted += " ";
		}
		else {
			int counter = 0;
			for (int j = 0; j < alpha.length(); j++) {
				if (message[i] == alpha[j]) {
					//character at count location of alphabet is encrypted letter in key
					encrypted += keyWord[counter];
					break;
				}
				else {
					counter++;
				}
			}
		}
	}
}

void Encryption::decryptString()
{
	//iterate through inputted message and convert to uppercase
	for (int i = 0; i < message.length(); i++) {
		message[i] = toupper(message[i]);
	}

	for (int i = 0; i < message.length(); i++) {
		if (message[i] == (char)32) {
			decrypted += " ";
		}
		else {
			int counter = 0;
			for (int j = 0; j < alpha.length(); j++) {
				if (message[i] == keyWord[j]) {
					//character at count location of alphabet is encrypted letter in key
					decrypted += alpha[counter];
					break;
				}
				else {
					counter++;
				}
			}
		}
	}

	//convert back to lowercase
	for (int i = 0; i < message.length(); i++) {
		decrypted[i] = tolower(decrypted[i]);
	}
}

//getter methods
string Encryption::getEncrypted()
{
	return encrypted;
}

string Encryption::getDecrypted()
{
	return decrypted;
}

bool Encryption::encryptionStatus() {
	return alreadyDec;
}