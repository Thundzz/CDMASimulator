#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Channel.hpp"
#include "User.hpp"
#include "Sequences.hpp"
#include "SimulationSet.hpp"

std::vector<int> goldSequence = {1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1};


int main(void){
    srand ( time(NULL) );
    Sequences seq = Sequences();
    for(int i = 0; i < 10; i++){
        SimulationSet a = SimulationSet(seq._negCorr);
        a.runSimulation();

        std::cout<< "Simulation #" << i << " : " << a.getBER() <<" \n";
    }
    return 0;
}
