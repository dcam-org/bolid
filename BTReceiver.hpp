#ifndef BTReceiveR_H
#define BTReceiveR_H

#include "BTBolid.hpp"
#include "BTDefines.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>


class BTReceiver 
{
public:

/// Set/get

    void setBolidData(BTBolidData *bolidData);
    BTBolidData *getBolidData() const;

/// FIFO open/close functions

    void openFifo();
    void closeFifo();

/// Receive function gets BTBolidData* from FIFO and sets m_bolid

    void receive();

private:
    
    BTBolidData *m_bolid;
    int m_fd;
};

#endif