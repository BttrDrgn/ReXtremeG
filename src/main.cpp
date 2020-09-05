#include <stdafx.hpp>

#include <game/game.hpp>
#include <utils/general/general.hpp>

namespace rxg
{
	void Init()
	{

	}
};

int __stdcall WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
    FILE* file_exists;
    int result = 0;
    int first_launch;
    bool winmain_once = true;

    file_exists = fopen("firsttime", "rb");
    if (file_exists)
    {
        fclose(file_exists);
        first_launch = 1;
        std::remove("firsttime");   //  Originally system("del firsttime");
    }
    else
    {
        first_launch = 0;
    }

    rxg::utils::general::CommandLineParser(lpCmdLine);

    if (winmain_once)
    {
        winmain_once = false;

        //  The game uses DirectX 5.0+, im pretty sure we don't need a check on this
        //if (!gDirectXCheck()) return result;

        /*  These don't seem to ever be used
        dword_6DB814 = hInstance;
        dword_6DB9C8 = hPrevInstance;
        dword_6DB818 = lpCmdLine;
        dword_6DB9C4 = nShowCmd;
        */

        /*
        unknown_libname_6();
        sub_4025B8(0x80000u);
        sub_401898();
        sub_401F50();
        sub_402045();
        sub_402473("kak!");
        sub_401CB2();
        */

        rxg::Init();
    }
    return result;
}