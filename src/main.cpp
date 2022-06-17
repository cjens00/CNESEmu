#include "NESConsole.h"

int main(int argc, char *argv[])
{
    std::string dirROMs = "../test/";
    std::string fileROM = "smb-test.nes";

    NESConsole console;
    console.LoadROM(dirROMs + fileROM);
    console.Start();
    console.Quit();
    return 0;
}