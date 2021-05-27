#pragma once

#include "TypedefsINeed.h"

#include "Tab.h"

namespace Deerfox
{
	class TabStack
	{
	public:
		TabStack() {}
		~TabStack();

		inline std::vector<Tab*>::iterator begin()
		{ return m_Tabs.begin(); }
		inline std::vector<Tab*>::iterator end()
		{ return m_Tabs.end(); }

		inline void PushTab(Tab* tab)
		{
			m_Tabs.emplace(m_Tabs.begin() + m_TabInsertIndex, tab);
			m_TabInsertIndex++;
		}
		inline void PopTab(Tab* tab)
		{
			auto it = std::find(m_Tabs.begin(), m_Tabs.end(), tab);
			if (it != m_Tabs.end())
			{
				m_Tabs.erase(it);
				m_TabInsertIndex--;
			}
		}

	private:
		std::vector<Tab*> m_Tabs;
		u32 m_TabInsertIndex = 0;
	};
}
