#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <vector>

class Channel {

    std::vector<int> _storage;

public:
    Channel();
    void send(std::vector<int> data, int delay);
    int getIndex(int index);
    int size();
};

#endif // CHANNEL_HPP
