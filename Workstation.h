// Name: Gautam Gandotra
// Seneca Student ID: 164064214
// Seneca email: ggandotra@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_Workstation_H
#define SDDS_Workstation_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{

	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;
	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation(const std::string& src) : Station(src) {}; // one argument constructor with const reference to string with Station as a paramatarized constructor

		void fill(std::ostream& os);

		bool attemptToMoveOrder();

		void setNextStation(Workstation* station); // setter function to set the next station
		Workstation* getNextStation() const; // function to get the next station
		void display(std::ostream& os) const; // display function
		Workstation& operator+=(CustomerOrder&& newOrder); 

		// Deleting any copy or moving operations

		Workstation(const Workstation&) = delete; 
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};
}
#endif

