#include <iostream>

#include "Channel.hpp"
#include "User.hpp"


Channel::Channel()
{
    _storage= std::vector<int>((User::_N)*(User::_nbBits)*10 + User::_maxDelay, 0);
    int len2 = _storage.size();
}

void Channel::send(std::vector<int> data, int delay){
    int len = data.size();
    for (int i =0; i < len; i++)
    {
        for(int k=0; k< 10; k++)
        {
            _storage[delay + 10* i +k] +=data[i];
        }

    }
}

int Channel::getIndex(int index){
    return _storage[index];
}

int Channel::size()
{
    return _storage.size();
}
