#include "NESBinary.h"

NESBinary::NESBinary(const std::string &pathToBinary)
{
    filePath = pathToBinary;
    fileSize = 0;
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
    auto ec = std::error_code();
    auto path = std::filesystem::path(filePath);
    this->fileSize = std::filesystem::file_size(path, ec);
    if(ec != std::error_code{}) return false;

}

