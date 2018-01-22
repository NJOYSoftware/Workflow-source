#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <cstdint>
#include <QString>

#define NUM_OFFSET 8
#define CHAR_OFFSET 2

namespace FileManager
{
    qint32 BinaryToInt(int array[]);

    int* IntToBinary(qint32 Number);

    qint32* QCharToHexa(QChar array[NUM_OFFSET]);

    qint32 HexaToInt(qint32 array[]);

    qint32* intToHexa(qint32 Number);

    QChar* HexaToQChar(qint32 array[CHAR_OFFSET]);
}

#endif // FILEMANAGER_HPP
