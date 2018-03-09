#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <cstdint>
#include <QString>

//Changing this number will modify the range of possible task-ids
#define NUM_OFFSET 4

#define CHAR_OFFSET 2

namespace FileManager
{
    quint32 QCharToHexa(QChar newChar);
    quint32 QCharToInt(QChar *array, quint32 offset);

    QChar *NumberToQChar(quint32 Number);
    QChar *CharToQChar(char Char);
}

#endif // FILEMANAGER_HPP
