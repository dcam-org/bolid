#ifndef BTRECIEVER_H
#define BTRECIEVER_H

#include "BTBolid.hpp"
#include "BTDefines.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>


class BTReciever 
{
public:

/// Set/get

    void setBolidData(BTBolidData *bolidData);
    BTBolidData *getBolidData() const;

/// FIFO open/close functions

    void openFifo();
    void closeFifo();

/// Recieve function gets BTBolidData* from FIFO and sets m_bolid

    void recieve();

private:
    
    BTBolidData *m_bolid;
    int m_fd;
};

#endif