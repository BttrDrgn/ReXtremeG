#include <main.hpp>

#include <utils/console/console.hpp>

namespace rxg
{
	namespace win_main
	{
		static int retn = get_variable<int>(0x006DB934);
		static int first_time = get_variable<int>(0x006DDF40);

		static bool once = get_variable<bool>(0x0065932C);
	}

	auto command_parser(LPSTR commands) -> int
	{
		PRINT_INFO("%s", commands);
		return call_function<int(LPSTR)>(0x004029F5)(commands);
	}

	auto print(char* msg) -> void
	{
		PRINT_GAME("%s", msg);
	}

	auto directx_version() -> int
	{
		return call_function<int()>(0x00401541)();
	}

	auto sub_55DCA0() -> int
	{
		return call_function<int()>(0x0055DCA0)();
	}

	auto sub_4025B8(std::uint32_t unk) -> int
	{
		return call_function<int(std::uint32_t)>(0x004025B8)(unk);
	}

	auto sub_401898() -> int
	{
		return call_function<int()>(0x00401898)();
	}

	auto sub_401F50() -> void
	{
		call_function<void()>(0x00401F50)();
	}

	auto sub_402045() -> void
	{
		call_function<void()>(0x00402045)();
	}

	auto sub_402473(int unk) -> int
	{
		return call_function<int(int)>(0x00402473)(unk);
	}

	auto sub_401CB2() -> void
	{
		call_function<void()>(0x00401CB2)();
	}

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

			/* These are never used, not a priority to implement
			dword_6DB764 = (int)hInstance;
			dword_6DB918 = (int)hPrevInstance;
			dword_6DB768 = (int)lpCmdLine;
			dword_6DB914 = nShowCmd;
			*/

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