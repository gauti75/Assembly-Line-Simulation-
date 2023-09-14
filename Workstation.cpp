// Name: Gautam Gandotra
// Seneca Student ID: 164064214
// Seneca email: ggandotra@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Workstation.h"
#include <string>
#include <iostream>
#include <algorithm>


namespace sdds
{
	// Global variables defined in workstation.
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	// filling the workstatoin if the orders existed
	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}

	}

	// Moving orers if the station is empty
	bool Workstation::attemptToMoveOrder()
	{
		bool move_result = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				else if (!m_orders.front().isOrderFilled())
					g_incomplete.push_back(std::move(m_orders.front()));
				else
					g_completed.push_back(std::move(m_orders.front()));

				move_result = true;
				m_orders.pop_front();
			}
			else if (this->getQuantity() <= 0) {

				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				else
					g_incomplete.push_back(std::move(m_orders.front()));

				move_result = true;
				m_orders.pop_front();
			}
		}

		return move_result;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	// Display function
	void Workstation::display(std::ostream& os) const
	{
		if (getNextStation())
		{
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else
		{
			os << getItemName() << " --> " << "End of Line" << std::endl;
		}
	}


	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}