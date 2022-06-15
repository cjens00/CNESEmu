#include "NESBinary.h"

NESBinary::NESBinary()
{
    filePath = "";
    format = NESBinaryFormat::iNES;
    fileSize = 0;
    header = nullptr;
    trainer = nullptr;
    PRGROM = nullptr;
    CHRROM = nullptr;
    playChoiceINSTROM = nullptr;
    playChoicePROM = nullptr;
    optionalTitle = nullptr;

    bHasTrainer = false;
    bHasPersistentMemory = false;
    bUsingCHRRAM = false;
    bMirrorVertical = false;
}

NESBinary::NESBinary(const std::string &pathToBinary)
{
    filePath = pathToBinary;
    format = NESBinaryFormat::iNES;
    fileSize = 0;
    header = nullptr;
    trainer = nullptr;
    PRGROM = nullptr;
    CHRROM = nullptr;
    playChoiceINSTROM = nullptr;
    playChoicePROM = nullptr;
    optionalTitle = nullptr;

    bHasTrainer = false;
    bHasPersistentMemory = false;
    bUsingCHRRAM = false;
    bMirrorVertical = false;
}

bool NESBinary::Read()
{
    auto ec = std::error_code();
    auto path = std::filesystem::path(filePath);
    this->fileSize = std::filesystem::file_size(path, ec);
    if (ec != std::error_code{}) return false;

    auto file = std::ifstream(path, std::ios::in | std::ios::binary);
    if (header != nullptr) return false;
    header = new char8_t[16];
    file.read(reinterpret_cast<char *>(header), 16);

    /// Interpret the header values
    szPRGROM = header[4];
    szCHRROM = header[5];
    auto flagsByte6 = std::bitset<8>(header[6]);
    auto flagsByte7 = std::bitset<8>(header[7]);
    auto flagsByte8 = std::bitset<8>(header[8]);
    auto flagsByte9 = std::bitset<8>(header[9]);
    auto flagsByte10 = std::bitset<8>(header[10]);

    if (szPRGROM > 0) PRGROM = new char8_t[16384 * szPRGROM];
    else return false;
    if (szCHRROM > 0) CHRROM = new char8_t[8192 * szCHRROM];
    else bUsingCHRRAM = true;

    bMirrorVertical = flagsByte6[0];
    bHasPersistentMemory = flagsByte6[1];
    bHasTrainer = flagsByte6[2];

    /// End interpret header values

    if (bHasTrainer)
    {
        trainer = new char8_t[512];
        file.read(reinterpret_cast<char *>(trainer), 512);
    }
    file.read(reinterpret_cast<char *>(PRGROM), 16384*szPRGROM);
    if (!bUsingCHRRAM)
    {
        file.read(reinterpret_cast<char *>(CHRROM), 8192*szCHRROM);
    }
    std::cout << "Cursor at pos " << file.tellg() << "\r\n";
    std::cout << "debug\r\n";
    return true;
}

NESBinary::~NESBinary()
{
    delete[] header;
    delete[] trainer;
    delete[] PRGROM;
    delete[] CHRROM;
    delete[] playChoiceINSTROM;
    delete[] playChoicePROM;
    delete[] optionalTitle;
}
