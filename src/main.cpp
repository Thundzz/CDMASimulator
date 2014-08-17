#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>


#include "Channel.hpp"
#include "User.hpp"
#include "Sequences.hpp"
#include "SimulationSet.hpp"

int main(void){
    std::ofstream logFile;
    logFile.open ("negCorr.txt");

    srand ( time(NULL) );
    Sequences seq = Sequences();
    for(int i = 0; i < 1000; i++){
        SimulationSet simu = SimulationSet(seq._negCorr);
        simu.runSimulation();
        //std::cout<< "Simulation #" << i << " : " << simu.getBER() <<" \n";
        logFile << "Simulation #" << i << " : " << simu.getBER() <<" \n";
    }
    logFile.close();
    return 0;
}
