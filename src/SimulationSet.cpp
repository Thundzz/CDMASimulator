#include <iostream>
#include <vector>
#include "SimulationSet.hpp"
#include <algorithm>
#include <cstdlib>

std::vector<int> sequenceId(int maxi){
    std::vector<int> numbers = std::vector<int> (maxi, 0);
    for(int i =0; i < maxi; i++)
    {
        numbers[i]=i;
    }
    random_shuffle ( numbers.begin(), numbers.end() );
    return numbers;
}

SimulationSet::SimulationSet(std::vector<std::vector<double>>& spreadingCode){

    double possibleNbUsers[] = {15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65};
    std::vector<int> userSSeq = sequenceId(127);
    std::vector<double> currentSeq;

    _seq = spreadingCode;
    _canal = Channel();
    _nbUsers = possibleNbUsers[rand() % 11];
    User unUsed = User();
    _users = std::vector<User>(_nbUsers, unUsed );

    for(int i =0; i < _nbUsers; i++)
    {
        currentSeq = _seq[userSSeq[i]];
        std::vector<int> seq_int( currentSeq.begin(),  currentSeq.end());
        _users[i] = User(rand() % User::_maxDelay, &_canal , seq_int);
    }
}

void SimulationSet::runSimulation(){
    for(int i =0; i < _nbUsers; i++)
    {
        _users[i].transmit();
    }
}

double SimulationSet::getBER(){
    return _users[0].computeBER();;
}
