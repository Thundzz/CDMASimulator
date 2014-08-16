#ifndef SIMULATION_SET_HPP
#define SIMULATION_SET_HPP

#include "Channel.hpp"
#include "User.hpp"
#include "Sequences.hpp"
#include <vector>

class SimulationSet{
public:
    int _nbUsers;
    std::vector<User> _users;
    Channel _canal;
    std::vector<std::vector<double>> _seq;

public:
    SimulationSet(std::vector<std::vector<double>>& spreadingCode);
    void runSimulation();
    int getBER();
};


#endif
