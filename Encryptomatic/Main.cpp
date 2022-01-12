/*
Matthias Kim
Encryptomatic
1/12/2021

This app uses a keyword cipher to encrypt and decrypt a message that the user inputs.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Header.h"


int main()
{
	//variables
	std::string input;
	std::string temp;
	std::string runAgain;
	int operationChoice;

	//while loop to run infinitely until user breaks the loop
	while (true) {
		std::cout << "Enter a message to be encrypted:  ";
		std::getline(std::cin, input);
		Encryption e(input);
		std::cout << "What would you like to do?\n1. Encrypt String\n2. Decrypt String" << std::endl;
		std::getline(std::cin, temp);
		operationChoice = stoi(temp);

		//call function depending on input
		switch (operationChoice) {
		case 1:
			e.keyWordPicker(); //get a keyword to encrypt with
			e.encryptString();
			std::cout << "Original: " << input << "\nEncrypted: " << e.getEncrypted() << std::endl << std::endl;;
			break;
		case 2:
			e.keyWordPicker();
			e.decryptString();
			std::cout << "Original: " << input << "\nDecrypted: " << e.getDecrypted() << std::endl << std::endl;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			return(0);
		}

		//ask user to run again
		std::cout << "Would you like to encrypt or decrypt another word?  ";
		std::getline(std::cin, runAgain);
		std::transform(runAgain.begin(), runAgain.end(), runAgain.begin(), ::toupper);

		if (runAgain == "YES" || runAgain == "Y")
			continue;
		else
			break;
	}

	//closing message
	std::cout << "Thank you for using Encryptomatic!" << std::endl;
	return(0);
}