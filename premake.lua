workspace "ReXtremeG"
	location ".\\build\\"
	startproject "ReXtremeG"

	targetdir "%{wks.location}\\bin\\%{cfg.buildcfg}\\"
	objdir "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}\\"
	buildlog "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "mbcs"
	architecture "x86"
	warnings "extra"

	buildoptions {
		"/Zm200",
		"/utf-8",
		"/std:c++latest",
		"/bigobj",
	}

	flags {
		"noincrementallink",
		"no64bitchecks",
		"shadowedvariables",
		"undefinedidentifiers",
		"multiprocessorcompile",
	}

	defines {
		"NOMINMAX",
		"WIN32_LEAN_AND_MEAN",
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS",
	}

	platforms {
		"x86",
	}

	configurations {
		"Debug",
		"Release",
	}

	configuration "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	configuration "Release"
		defines "NDEBUG"
		optimize "full"
		runtime "release"
		symbols "off"

	project "ReXtremeG"
		language "c++"
		kind "windowedapp"

		pchheader "stdafx.hpp"
		pchsource "src/stdafx.cpp"
		forceincludes "stdafx.hpp"

		files ".\\src\\**"

		includedirs {
			".\\src\\",
		}
		
		linkoptions "/NXCOMPAT:NO /IGNORE:4254 /DYNAMICBASE:NO /SAFESEH:NO /LARGEADDRESSAWARE /LAST:.main"