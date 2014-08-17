#ifndef SEQ_H
#define SEQ_H

#include <vector>

class Sequences{

public:
    static const int _number = 129;
    static const int _length = 127;

public:
    std::vector<std::vector<double>> _goldSequences;
    std::vector<std::vector<double>> _posCorr;
    std::vector<std::vector<double>> _negCorr;
    std::vector<std::vector<double>> _unCorr;

public:
    Sequences();
    std::vector<double> posCorr(int index);
    std::vector<double> negCorr(int index);
    std::vector<double> unCorr(int index);
    std::vector<double> goldSequence(int index);
public:

};


#endif // SEQ_H
