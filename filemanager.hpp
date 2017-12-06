#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <cstdint>
#include <QString>

namespace FileManager
{
    qint32 BinaryToInt(int array[]);

    int* IntToBinary(qint32 Number);
}

#endif // FILEMANAGER_HPP
