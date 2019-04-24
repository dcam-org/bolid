#ifndef BTRECIEVER_H
#define BTRECIEVER_H

#include "BTBolid.hpp"
#include <unistd.h>


class BTReciever 
{
public:

    void recieve();

private:
    
    BTBolidData *m_bolid;
    int m_fd;
    size_t size;
};

#endif