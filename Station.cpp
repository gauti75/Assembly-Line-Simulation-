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
#include "Station.h"
#include "Utilities.h"
#include <string>

using namespace std;

namespace sdds {


	Station::Station(const std::string& file_line) {
		Utilities U;
		size_t next_pos = 0;
		bool more = true;

		item_name = U.extractToken(file_line, next_pos, more);
		serial_num = std::stoi(U.extractToken(file_line, next_pos, more));
		item_num = std::stoi(U.extractToken(file_line, next_pos, more));
		m_widthField = std::max(m_widthField, U.getFieldWidth());
		item_desc = U.extractToken(file_line, next_pos, more);

		id_station = static_cast<int>(++id_generator);

	}

	const std::string& Station::getItemName() const {
		return item_name;
	}

	size_t Station::getNextSerialNumber() {
		return serial_num++;

	}

	size_t Station::getQuantity() const {
		return item_num;
	}

	void Station::updateQuantity() {
		if (item_num < 0) {
			item_num = item_num;
		}
		else {
			item_num = item_num - 1;
		}

	}

	void Station::display(std::ostream& os, bool full) const {
		if (!full) {

			os << std::setfill('0') << std::right << std::setw(3) << id_station << " | ";
			os << std::setw(m_widthField) << std::left << std::setfill(' ') << item_name<< " | ";
			os << std::setw(6) << std::right << std::setfill('0') << serial_num << " | ";
		}
		
		else if (full) {
			os << std::setfill('0') << std::right << std::setw(3) << id_station<< " | ";
			os << std::setw(m_widthField) << std::left << std::setfill(' ') << item_name<< " | ";
			os << std::setw(6) << std::right << std::setfill('0') << serial_num << " | ";
			os << std::setfill(' ') << std::setw(4) << std::right << item_num << " | ";
			os << std::left << item_desc;
		}
		os << std::endl;
	}




}