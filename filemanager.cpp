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
    for(int i = 0; i < 8; i++){
        Number += pow(2, 7-i)*(array[i]);
    }
    return Number;
}


int* FileManager::IntToBinary(qint32 Number){
    static int binaryNumber[8];
    for(int i = 0; i < 8; i++){
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
