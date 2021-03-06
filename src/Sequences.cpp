#include "Sequences.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>


double plm(double x,double  a){
    double b = (1.0-a)/2, x1, x2;
    if (a>=0){
        x1 = 0.5 - 1.0/(2*a);
        x2 = 0.5 + 1.0/(2*a);
    }
    else{
        x1 = 0.5 + 1.0/(2*a);
        x2 = 0.5 - 1.0/(2*a);
    }
    if (x>= x1 && x <= x2)
        return (a*x + b);
    else if (x>=0 && x < x1)
        return (1.0/x1*x);
    else if (x> x2 && x <=1)
        return plm(1-x, a);
}
double posPlm(double x){
    return plm(x, 1.5);
}
double negPlm(double x)
{
    return plm(x, -2-sqrt(3) );
}
double logisticNext(double x, double mu=4){
    return (mu* x*(1-x));
}

double logist(double x){
    return logisticNext( x, 4);
}


void Sequences::parseSequences(const char * filename, std::vector<std::vector<double>>& storage){
    std::ifstream infile(filename);
    std::string line;
    int bit;
    int lineNumber=0;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        for(int i=0; i<_length; i++)
        {
            iss >> bit;
            storage[lineNumber][i] = 2*bit-1;
        }
        lineNumber++;
    }
}

void Sequences::parseGoldSequences(const char * filename ){
    parseSequences(filename,  _goldSequences);
}

void Sequences::parseProposedSequences(const char * filename ){
    parseSequences(filename,  _proposedSequences);
}

void computeSequence( double u0 , int nbIter , double (*sequenceNext)(double), std::vector<double>& storage ){
    int current =0;
    double valNext;
    storage[0] = u0;

    while(current < nbIter-1)
    {
        valNext = sequenceNext(storage[current]);
        current ++;
        storage[current] = valNext;
    }
}
void toBinary(std::vector<double>& storage)
{
    for(int i =0; i< Sequences::_length; i++)
        storage[i] = (storage[i]>=0.5)? 1.0: -1.0;
}
Sequences::Sequences() {
    _posCorr =  std::vector<std::vector<double>>(_number);
    _negCorr =  std::vector<std::vector<double>>(_number);
    _unCorr =  std::vector<std::vector<double>>(_number);
    _goldSequences =  std::vector<std::vector<double>>(_number);
    _proposedSequences =  std::vector<std::vector<double>>(_number);

    for (int i =0 ; i< _number; i++)
    {

        _posCorr[i] = std::vector<double>(_length, 0);
        _negCorr[i] = std::vector<double>(_length, 0);
        _unCorr[i] = std::vector<double>(_length, 0);
        _goldSequences[i] =  std::vector<double>(_length, 0);
        _proposedSequences[i] =  std::vector<double>(_length, 0);

        computeSequence(0.9847 *i/_number, _length, posPlm, _posCorr[i]);
        computeSequence(0.9847 *i/_number, _length, negPlm, _negCorr[i]);
        computeSequence(0.9847 *i/_number, _length, logist, _unCorr[i]);

        toBinary(_posCorr[i]);
        toBinary(_negCorr[i]);
        toBinary(_unCorr[i]);
    }
    parseGoldSequences("../data/goldSequences.txt");
    parseProposedSequences("../data/proposedSequences.txt");
}

std::vector<double> Sequences::posCorr(int index){
    return _posCorr[index];
}
std::vector<double> Sequences::negCorr(int index){
    return _negCorr[index];
}
std::vector<double> Sequences::unCorr(int index){
    return _unCorr[index];
}
std::vector<double> Sequences::goldSequence(int index){
    return _goldSequences[index];
}



