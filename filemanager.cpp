#include "filemanager.hpp"
#include <QString>
#include <cstdio>
#include <exception>
#include <cmath>
#include <fstream>
#include <bitset>

using namespace std;

quint32 FileManager::QCharToHexa(QChar newChar){
    quint32 hexanumber = 0;
    char tempChar = newChar.toUpper().toLatin1();
    switch(tempChar){
        case 'A': hexanumber = 10; break;
        case 'B': hexanumber = 11; break;
        case 'C': hexanumber = 12; break;
        case 'D': hexanumber = 13; break;
        case 'E': hexanumber = 14; break;
        case 'F': hexanumber = 15; break;
        default: hexanumber = newChar.digitValue();
    }
    return hexanumber;
}

quint32 FileManager::QCharToInt(QChar *array, quint32 offset){
    quint32 Number = 0;
    for(unsigned int i = 0; i < offset; i++){
        Number += FileManager::QCharToHexa(array[i])*pow(16, offset - i - 1);
    }
    return Number;
}

QChar *FileManager::NumberToQChar(quint32 Number){
    static QChar array[NUM_OFFSET];
    for(int i = 0; i < NUM_OFFSET; i++){
        array[i] = '0';
    }
    if(Number != 0){
        quint32 numOrder = log2(Number)/log2(16);
        quint32 remainder = 0;
        for(int i = numOrder; i >= 0; i--, Number /= 16){
            remainder = Number % 16;
            switch(remainder){
                case 10: array[i] = 'A'; break;
                case 11: array[i] = 'B'; break;
                case 12: array[i] = 'C'; break;
                case 13: array[i] = 'D'; break;
                case 14: array[i] = 'E'; break;
                case 15: array[i] = 'F'; break;
                default: array[i] = '0' + remainder;
            }
        }
    }
    return array;
}

QChar *FileManager::CharToQChar(char Char){
    static QChar array[CHAR_OFFSET];
    for(int i = 0; i < CHAR_OFFSET; i++){
        array[i] = '0';
    }
    if(Char != 0){
        quint32 numOrder = log2(Char)/log2(16);
        quint32 remainder = 0;
        for(int i = numOrder; i >= 0; i--, Char /= 16){
            remainder = Char % 16;
            switch(remainder){
                case 10: array[i] = 'A'; break;
                case 11: array[i] = 'B'; break;
                case 12: array[i] = 'C'; break;
                case 13: array[i] = 'D'; break;
                case 14: array[i] = 'E'; break;
                case 15: array[i] = 'F'; break;
                default: array[i] = '0' + remainder;
            }
        }
    }
    return array;
}
