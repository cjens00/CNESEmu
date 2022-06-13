#include "NESBinary.h"

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
    headerFlags = {};
}

bool NESBinary::Read()
{
    auto ec = std::error_code();
    auto path = std::filesystem::path(filePath);
    this->fileSize = std::filesystem::file_size(path, ec);
    if (ec != std::error_code{}) return false;

    auto file = std::ifstream(path, std::ios::in | std::ios::binary);
    if (header != nullptr) return false;
    header = new uint8_t[16];

    file.read(reinterpret_cast<char *>(header), 16);

    /// Interpret the header values
    szPRGROM = header[4];
    if (szPRGROM > 0) PRGROM = new unsigned char[16384 * szPRGROM];
    else return false;
    szCHRROM = header[5];
    if (szCHRROM > 0) CHRROM = new unsigned char[8192 * szCHRROM];
    else headerFlags.usesCHRRAM = true;
    /// Header Flags: Byte 6/15
    auto flagsByteSix = header[6];
    headerFlags.verticalMirror = BitOperations::ReadBit(flagsByteSix, 0);
    headerFlags.hasPersistentMemory = BitOperations::ReadBit(flagsByteSix, 1);
    headerFlags.hasTrainer = BitOperations::ReadBit(flagsByteSix, 2);
    /// End interpret header values

    if (headerFlags.hasTrainer)
    {
        trainer = new unsigned char[512];
        file.read(reinterpret_cast<char *>(trainer), 512);
    }
    file.read(reinterpret_cast<char *>(PRGROM), 16384*szPRGROM);
    if (!headerFlags.usesCHRRAM)
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
