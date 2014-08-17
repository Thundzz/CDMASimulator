#include <iostream>

#include "Channel.hpp"
#include "User.hpp"


Channel::Channel()
{
    _storage= std::vector<int>((User::_N)*(User::_nbBits) + User::_maxDelay, 0);
    int len2 = _storage.size();
}

void Channel::send(std::vector<int> data, int delay){
    int len = data.size();
    for (int i =0; i < len; i++)
    {
        _storage[delay +i] +=data[i];
        //TODOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        //std::cout << data[i] << " ";
    }
}

int Channel::getIndex(int index){
    return _storage[index];
}

int Channel::size()
{
    return _storage.size();
}
