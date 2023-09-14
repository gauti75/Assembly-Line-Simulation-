// Name: Gautam Gandotra
// Seneca Student ID: 164064214
// Seneca email: ggandotra@myseneca.ca
// Date of completion: July 10, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include <algorithm>
#include<string>
#include "Station.h"

namespace sdds {
	// Defining structure item here
	struct Item
	{
		std::string m_itemName = "";
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {

		std::string m_name = ""; // name of customer
		std::string m_product = ""; // name of product
		size_t m_cntItem = 0u; // number of items in a customer's order
		Item** m_lstItem{ nullptr }; // dynamically pointer to pointer

		static size_t m_widthField;

	public:

		CustomerOrder() = default;
		CustomerOrder(const std::string& line);

		CustomerOrder(const CustomerOrder&); // Copy Constructor for throwing an Exception

		CustomerOrder& operator=(CustomerOrder& customer) = delete; // Deleting the Copy assignment

		CustomerOrder(CustomerOrder&& moveCustomer)noexcept; // Move Constructor;

		CustomerOrder& operator=(CustomerOrder&& moveCustomer)noexcept;

		virtual ~CustomerOrder(); // Destructor

		bool isOrderFilled() const;

		bool isItemFilled(const std::string& itemName) const;

		void fillItem(Station& station, std::ostream& os);

		void display(std::ostream& os) const;


	};

}

#endif