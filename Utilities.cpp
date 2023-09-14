// Name: Gautam Gandotra
// Seneca Student ID: 164064214
// Seneca email: ggandotra@myseneca.ca
// Date of completion: July 10, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>
#include <iomanip>
#include "Utilities.h"

using namespace std;

namespace sdds {

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string extractedToken;
		
		size_t first_delim = str.find(m_delimiter, next_pos);
		

		if (first_delim != std::string::npos) {
			extractedToken = str.substr(next_pos, first_delim - next_pos);
			next_pos = first_delim+1;
			more = true;
		}

		else {
			extractedToken = str.substr(next_pos);
			more = false;
		}

		size_t tokenStartPos = extractedToken.find_first_not_of(" ");
		size_t tokenEndPos = extractedToken.find_last_not_of(" ");
		if (tokenStartPos != std::string::npos && tokenEndPos != std::string::npos) {
			extractedToken = extractedToken.substr(tokenStartPos, tokenEndPos - tokenStartPos + 1);
		}


		if (m_widthField < extractedToken.length()) {
			m_widthField = extractedToken.length();
		}

		if (extractedToken.empty()) {
			more = false;
			throw "ERROR: Token is empty!";
		}
		
		return extractedToken;
	}


	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}