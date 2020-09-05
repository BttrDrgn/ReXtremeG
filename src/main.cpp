#include <stdafx.hpp>
#include <game/game.hpp>

namespace rxg
{
    //  Temporary
    int graphics_device_index, parsed_window_height, parsed_window_width, window_height, window_width;
    double height_ratio, width_ratio, width_half, height_half;

    int CommandLineParse(char* lpCmdLine)
    {
        int result;
        int parsed;

        for (char* i = strtok(lpCmdLine, " -"); i; i = strtok(0, " -"))
        {
            if (sscanf(i, "d%d", &parsed) == 1)
            {
                graphics_device_index = parsed;
            }
            else if (sscanf(i, "w%d", &parsed) == 1)
            {
                parsed_window_width = parsed;
            }
            else if (sscanf(i, "h%d", &parsed) == 1)
            {
                parsed_window_height = parsed;
            }
        }

        window_width = parsed_window_width;
        window_height = parsed_window_height;

        height_ratio = (parsed_window_width / 640);
        width_ratio = (parsed_window_height / 480);

        width_half = (parsed_window_width / 2);
        result = parsed_window_height / 2;
        height_half = (parsed_window_height / 2);

        return result;
    }

	void Init()
	{

	}
};

int WinMain(
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
        system("del firsttime");
    }
    else
    {
        first_launch = 0;
    }

    rxg::CommandLineParse(lpCmdLine);

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