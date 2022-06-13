#include "NESBinary.h"

NESBinary::NESBinary(const std::string &pathToBinary)
{
    filePath = pathToBinary;
    header = nullptr;
    trainer = nullptr;
    PRGROM = nullptr;
    CHRROM = nullptr;
    PlayChoiceINSTROM = nullptr;
    PlayChoicePROM = nullptr;
    optionalTitle = nullptr;
}

bool NESBinary::Read()
{

}

