#include <main.hpp>

#include <utils/console/console.hpp>

namespace rxg
{
	//--0x00556727
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
}