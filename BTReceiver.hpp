#ifndef BTReceiveR_H
#define BTReceiveR_H

#include "BTBolide.hpp"
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

    void setBolideData(BTBolideData *bolidData);
    BTBolideData *getBolideData() const;

/// FIFO open/close functions

    void openFifo();
    void closeFifo();

/// Receive function gets BTBolideData* from FIFO and sets m_bolid

    void receive();

private:
    
    BTBolideData *m_bolid;
    int m_fd;
};

#endif