#include <stdafx.hpp>

#include <game/game.hpp>
#include <utils/general/general.hpp>

namespace rxg::utils
{
    void general::CommandLineParser(char* lpCmdLine)
    {
        int parsed;

        for (char* i = strtok(lpCmdLine, " -"); i; i = strtok(0, " -"))
        {
            if (sscanf(i, "d%d", &parsed) == 1)
            {
                game::graphics_device_index = parsed;
            }
            else if (sscanf(i, "w%d", &parsed) == 1)
            {
                game::window_width = parsed;
            }
            else if (sscanf(i, "h%d", &parsed) == 1)
            {
                game::window_height = parsed;
            }
        }

        /*  Possibly entirely useless?
        dword_6DB7F8 = window_width_arg;            //  These are used, but refer to game::window_width if needed
        dword_6DB7FC = window_height_arg;           //                               game::window_height
        window_width = (window_width_arg / 640);
        window_height = (window_height_arg / 480);
        window_width_d_2 = (window_width_arg / 2);
        result = window_height_arg / 2;
        window_height_d_2 = (window_height_arg / 2);
        return result;
        */
    }
}