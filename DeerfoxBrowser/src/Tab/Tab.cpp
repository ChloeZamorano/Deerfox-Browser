#include "DfPch.h"
#include "Tab.h"

#include <ImGui/ImGui.h>

namespace Deerfox
{
	void Tab::ImGuiRender()
	{
		ImGui::Begin(m_Title.c_str());
		ImGui::InputText("", m_URL, 512);
		ImGui::End();
	}
}
