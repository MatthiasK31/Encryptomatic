#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <iostream>

class Encryption
{
private:
	std::string message;
	std::string keyWord;
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string encrypted;
	std::string decrypted;
	std::vector<int> randomPositions;
	std::map<char, char> unencryptEncrypt;
	bool alreadyDec = true;
public:
	Encryption();
	Encryption(std::string);
	void keyWordPicker();
	void encryptString();
	void decryptString();
	std::string getEncrypted();
	std::string getDecrypted();
	bool encryptionStatus();
};