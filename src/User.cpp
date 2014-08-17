#include <random>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "User.hpp"

User::User(){
}

User::User(int delay, Channel* canal, std::vector<int> spreadingCode){
    int spreadingCodeSize = spreadingCode.size();
    _canal = canal;
    _delay = delay;
    _spreadingCode = spreadingCode;
    _bits  = std::vector<int> (_nbBits, 0);
    _chips = std::vector<int> (_nbBits* spreadingCodeSize, 0);
    for(int i =0; i < _nbBits; i++){
        _bits[i] = 2*(rand() % 2)-1;
    }
}
void print(int x)
{
    std::cout << x ;
}

void User::printArray(std::vector<int> bitsOrChips){
    for_each (bitsOrChips.begin(), bitsOrChips.end(), print );
}

void User::printChips(){
    printArray(_chips);
}

void User::printBits(){
    printArray(_bits);
}

 std::vector<int> User::encode(int bit){
    int sCSize = _spreadingCode.size();
    std::vector<int> result (sCSize, 0);
    for (int i=0; i< sCSize; i++){
        result[i] = bit * _spreadingCode[i];
    }
    return result;
}

 void User::encodeAll(){
    int sCSize = _spreadingCode.size();
    std::vector<int> encoded;
    for(int i = 0; i< _nbBits; i++){
        encoded = encode(_bits[i]);
        for(int j =0; j< sCSize; j++)
        {
            _chips[i*sCSize + j] =encoded[j];
        }
    }
}

void User::sendAll(){
    _canal->send(_chips, _delay);
}

void User::transmit(){
    encodeAll();
    sendAll();
}

std::vector<int> User::decodeCanal(){
    int sCSize = _spreadingCode.size();
    std::vector<int> decodedBits (_nbBits, 0);
    int sum;
    for(int i = 0; i< _nbBits; i++){
        sum =0;
        for(int j =0; j< sCSize; j++)
        {
            for(int k=0; k< 10; k++)
            {
                sum += _canal->getIndex((i*sCSize + j)*10 + k + _delay)*_spreadingCode[j];
            }
        }
        decodedBits[i] = (sum>=0)?  1: -1 ;
    }
    return decodedBits;
}

double User::computeBER()
{
    int ber = 0;
    std::vector<int> decodedBits =  decodeCanal();
    for (int i =0 ; i< _nbBits; i++){
        if (decodedBits[i] != _bits[i]){
            ber ++;
        }
    }
    double res = (double)ber/(double)_nbBits;
    return res;
}
