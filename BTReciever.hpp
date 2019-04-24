#ifndef BTRECIEVER_H
#define BTRECIEVER_H

#include "BTBolid.hpp"
#include "BTDefines.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>


class BTReciever 
{
public:

    void recieve();

private:
    
    BTBolidData *m_bolid;
    int m_fd;
};

#endif