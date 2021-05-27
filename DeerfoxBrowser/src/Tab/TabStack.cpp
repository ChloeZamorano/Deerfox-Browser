#include "DfPch.h"
#include "TabStack.h"

namespace Deerfox
{
	TabStack::~TabStack()
	{
		for (auto& tab : m_Tabs)
			delete tab;
	}
}
