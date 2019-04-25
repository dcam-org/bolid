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

/// Set/get

    void setBolidData(BTBolidData *bolidData);
    BTBolidData *getBolidData() const;

/// Recieve function gets BTBolidData* from FIFO and sets m_bolid

    void recieve();

private:
    
    BTBolidData *m_bolid;
    int m_fd;
};

#endif