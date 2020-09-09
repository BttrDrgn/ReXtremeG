#include <main.hpp>
#include <misc.hpp>

#include <utils/console/console.hpp>

namespace rxg
{
	namespace win_main
	{
		static int retn = get_variable<int>(0x006DB934);
		static int first_time = get_variable<int>(0x006DDF40);

		static bool once = get_variable<bool>(0x0065932C);
	}

	//--0x0055688A _WinMain@16_0
	auto main() -> int
	{
#ifdef _DEBUG
		MessageBoxA(nullptr, "Loading main.", "ReXtremeG", MB_OK);
#endif
		FILE* file;

		//--win_main::retn
		set_variable(0x006DB934, 0);
		file = fopen("firsttime","rb");
		if (file)
		{
			fclose(file);
			//--win_main::first_time
			set_variable(0x006DDF40, 1);
			std::remove("firsttime"); // Originally system("del firsttime");
		}
		else
		{
			//--win_main::first_time
			set_variable(0x006DDF40, 0);
		}
		command_parser(GetCommandLineA());
		print("initialising app..");
		if (!win_main::once)
		{
			//--win_main::once
			set_variable<bool>(0x0065932C,false);
			if (!directx_version()) return win_main::retn;
			print("initmain done.");
			sub_55DCA0();
			sub_4025B8(0x80000u);
			sub_401898();
			sub_401F50();
			sub_402045();
			sub_402473((int)"kak!");
			sub_401CB2();
		}
		print("WinMain - Exit");
		return win_main::retn;
	}
}