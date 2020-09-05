workspace "RXG"
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

	syslibdirs {
	
	}

	includedirs {
		".\\src\\",
	}

	buildoptions {
		"/Zm200",
		"/utf-8",
		"/std:c++latest",
	}

	flags {
		"no64bitchecks",
		"shadowedvariables",
		"noincrementallink",
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
	
	--[[
	postbuildcommands {
		"if \"%COMPUTERNAME%\" == \"<PC-NAME>\" ( copy /y \"$(TargetPath)\" \"<PATH\\TO\\FOLDER\\\" )",
	}
	--]]

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

		files {
			".\\src\\**.h",
			".\\src\\**.c",
			".\\src\\**.hpp",
			".\\src\\**.cpp",
		}
		
		links {
		
		}

		includedirs {
			".\\src\\",
		}
