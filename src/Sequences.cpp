#include "Sequences.hpp"
#include <iostream>

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
    return plm(x, -1.5);
}
double logisticNext(double x, double mu=4){
    return (mu* x*(1-x));
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
void toBinary(std::vector<double> storage)
{
    for(int i =0; i< Sequences::_length; i++)
        storage[i] = (storage[i]>=0.5)? 1.0: -1.0;
}
Sequences::Sequences() {
    _posCorr =  std::vector<std::vector<double>>(_number);
    _negCorr =  std::vector<std::vector<double>>(_number);
    _unCorr =  std::vector<std::vector<double>>(_number);
    _goldSequences =  std::vector<std::vector<double>>(_number);

    for (int i =0 ; i< _number; i++)
    {

        _posCorr[i] = std::vector<double>(_length, 0);
        _negCorr[i] = std::vector<double>(_length, 0);
        _unCorr[i] = std::vector<double>(_length, 0);
        _goldSequences[i] =  std::vector<double>(_length, 0);

        computeSequence(0.9847 *i/_number, _length, posPlm, _posCorr[i]);
        computeSequence(0.9847 *i/_number, _length, negPlm, _negCorr[i]);
        computeSequence(0.9847 *i/_number, _length, negPlm, _unCorr[i]);

        toBinary(_posCorr[i]);
        toBinary(_negCorr[i]);
        toBinary(_negCorr[i]);
    }
}

std::vector<double> Sequences::posCorr(double index){
    return _posCorr[index];
}
std::vector<double> Sequences::negCorr(double index){
    return _negCorr[index];
}
std::vector<double> Sequences::unCorr(double index){
    return _unCorr[index];
}
std::vector<double> Sequences::goldSequence(double index){
    return _goldSequences[index];
}



