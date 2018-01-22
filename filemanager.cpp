#include "filemanager.hpp"
#include <QString>
#include <cstdio>
#include <exception>
#include <cmath>
#include <fstream>
#include <bitset>

using namespace std;

qint32 FileManager::BinaryToInt(int array[]){
    qint32 Number = 0;
    for(int i = 0; i < NUM_OFFSET; i++){
        Number += pow(2, 7-i)*(array[i]);
    }
    return Number;
}


int* FileManager::IntToBinary(qint32 Number){
    static int binaryNumber[NUM_OFFSET];
    for(int i = 0; i < NUM_OFFSET; i++){
        binaryNumber[i] = 0;
    }
    if(Number != 0){
        int numberOrder = (int)log2(Number);
        for (int i = 7; i > 6 - numberOrder; i--){
            binaryNumber[i] = Number % 2;
            Number/=2;
        }
    }
    return binaryNumber;
}

qint32 *FileManager::QCharToHexa(QChar array[CHAR_OFFSET]){
    static int hexanumber[CHAR_OFFSET];
    for(int i = 0; i < CHAR_OFFSET; i++){
        hexanumber[i] = 0;
    }
    for(int i = 0; i < CHAR_OFFSET; i++){
        char tempChar = array[i].toUpper().toLatin1();
        switch(tempChar){
            case 'A': hexanumber[i] = 10; break;
            case 'B': hexanumber[i] = 11; break;
            case 'C': hexanumber[i] = 12; break;
            case 'D': hexanumber[i] = 13; break;
            case 'E': hexanumber[i] = 14; break;
            case 'F': hexanumber[i] = 15; break;
            default: hexanumber[i] = array[i].digitValue();
        }
    }
    return hexanumber;
}

qint32 FileManager::HexaToInt(qint32 array[2]){
    qint32 Number = 0;
    for(int i = 0; i < CHAR_OFFSET; i++){
        Number += pow(16, 1 - i) * array[i];
    }
    return Number;
}

qint32* FileManager::intToHexa(qint32 Number){
    static qint32 array[CHAR_OFFSET];
    for(int i = 0; i < CHAR_OFFSET; i++){
        array[i] = 0;
    }
    if(Number != 0){
        qint32 numOrder = log2(Number)/4 + 1;
        for(int i = numOrder - 1; i >= 0; i++){
            array[i] = Number % 16;
            Number/=16;
        }
    }
    return array;
}

QChar* FileManager::HexaToQChar(qint32 array[CHAR_OFFSET]){
    static QChar charNumber[CHAR_OFFSET];
    for(int i = 0; i < CHAR_OFFSET; i++){
        charNumber[i] = 0;
    }
    for(int i = 0; i < CHAR_OFFSET; i++){
        switch(array[i]){
            case 10: charNumber[i] = QChar('A'); break;
            case 11: charNumber[i] = QChar('B'); break;
            case 12: charNumber[i] = QChar('C'); break;
            case 13: charNumber[i] = QChar('D'); break;
            case 14: charNumber[i] = QChar('E'); break;
            case 15: charNumber[i] = QChar('F'); break;
            default: charNumber[i] = QChar('0' + array[i]);
        }
    }
    return charNumber;
}
