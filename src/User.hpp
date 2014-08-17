#ifndef USER_HPP
#define USER_HPP

#include <vector>
#include <random>
#include "Channel.hpp"

#define STEP 10

class User {

public:
    static const int _N = 127;
    static const int _nbBits = 1000;
    static const int _minDelay = 0;
    static const int _maxDelay = STEP*_N;

private:
    int _delay;
    Channel* _canal;
    std::vector<int> _bits;
    std::vector<int> _chips;
    std::vector<int> _spreadingCode;

private:
    std::vector<int> encode(int bit);
    void printArray(std::vector<int> bitsOrChips);
    std::vector<int> decodeCanal();
    void encodeAll();
    void sendAll();

public:
    User();
    User(int delay, Channel* canal, std::vector<int> spreadingCode);
    void transmit();
    double computeBER();

public:
    void printChips();
    void printBits();

};


#endif // USER_HPP
