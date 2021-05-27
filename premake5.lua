workspace "DeerfoxBrowser"
	architecture "x64"
	startproject "DeerfoxBrowser"

	configurations
	{
		"Debug",
		"Release",
		"Deploy"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"]		= "DeerfoxBrowser/deps/GLFW/include"
IncludeDir["Glad"]		= "DeerfoxBrowser/deps/Glad/include"
IncludeDir["ImGui"]		= "DeerfoxBrowser/deps/imgui"


group "Dependencies"
	include "DeerfoxBrowser/deps/GLFW"
	include "DeerfoxBrowser/deps/Glad"
	include "DeerfoxBrowser/deps/imgui"
group ""


project "DeerfoxBrowser"
	location "DeerfoxBrowser"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/DeerfoxBrowser")
	objdir ("bin-int/" .. outputdir .. "/DeerfoxBrowser")

	pchheader "DfPch.h"
	pchsource "DeerfoxBrowser/src/DfPch.cpp"

	files
	{
		"DeerfoxBrowser/src/**.h",
		"DeerfoxBrowser/src/**.cpp"
	}

	includedirs
	{
		"DeerfoxBrowser/src/disarRay",
		"DeerfoxBrowser/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DFOX_PLAT_WIN",
			"DFOX_BUILD",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DFOX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DFOX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Deploy"
		defines "DFOX_DEPLOY"
		runtime "Release"
		optimize "on"
