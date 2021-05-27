#pragma once

#include "TypedefsINeed.h"

namespace Deerfox
{
	class Tab
	{
	public:
		Tab(str8 title, char url[2048]) : m_Title(title)
		{ strcpy_s(m_URL, url); }

		inline void ImGuiRender();

		inline void SetURL(char url[2048])
		{ strcpy_s(m_URL, url); }
		inline char* GetURL()
		{ return m_URL; }

	private:
		str8 m_Title;
		char m_URL[2048] = "";
	};
}
