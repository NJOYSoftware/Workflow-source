#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <cstdint>
#include <QString>

#define NUM_OFFSET 4
#define CHAR_OFFSET 2

namespace FileManager
{
    qint32 BinaryToInt(int array[]);

    int* IntToBinary(qint32 Number);

    qint32 QCharToHexa(QChar newChar);
    qint32 QCharToInt(QChar array[], qint32 offset);

    QChar *NumberToQChar(qint32 Number);
    QChar *CharToQChar(char Char);
}

#endif // FILEMANAGER_HPP
