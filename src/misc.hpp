namespace rxg
{
	auto command_parser(LPSTR commands) -> int;

	auto print(char* msg) -> void;

	auto directx_version() -> int;

	auto sub_55DCA0() -> int;

	auto sub_4025B8(std::uint32_t unk) -> int;

	auto sub_401898() -> int;

	auto sub_401F50() -> void;

	auto sub_402045() -> void;

	auto sub_402473(int unk) -> int;

	auto sub_401CB2() -> void;
}