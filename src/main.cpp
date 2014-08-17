#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>


#include "Channel.hpp"
#include "User.hpp"
#include "Sequences.hpp"
#include "SimulationSet.hpp"

#define NBSIMULATIONS 10000

void simulateSequence(const char * filename, std::vector<std::vector<double>> sequenceContainer ){
    std::cout<< "Processing: " << filename<<std::endl ;
    std::ofstream logFile;
    logFile.open (filename);
    for(int i = 0; i < NBSIMULATIONS; i++){
        SimulationSet simu = SimulationSet(sequenceContainer);
        simu.runSimulation();
        std::cout << "Simulating... (" << (double)100* i/NBSIMULATIONS << "%)" <<" \r";
        logFile << simu._nbUsers << " " << std::fixed <<simu.getBER() << std::endl;
    }
    std::cout << std::endl;
    logFile.close();
}

int main(void){
    srand ( time(NULL) );
    Sequences seq = Sequences();
    //simulateSequence("CproposedSeq.txt", seq._proposedSequences);
    //simulateSequence("CgoldSeq.txt", seq._goldSequences);
    //simulateSequence("CunCorrP.txt", seq._unCorr);
    //simulateSequence("CnegCorr.txt", seq._negCorr);

    return 0;
}
