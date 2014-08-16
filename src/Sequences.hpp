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
    std::vector<double> posCorr(double index);
    std::vector<double> negCorr(double index);
    std::vector<double> unCorr(double index);
    std::vector<double> goldSequence(double index);
public:

};


#endif // SEQ_H
