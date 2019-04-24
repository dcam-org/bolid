#include "BTReciever.hpp"
#include "BTDefines.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>



void recieve(){
    int fd;
    if((fd = open(BT_FIFO_NAME, O_RDONLY)) < 0){
        std::cout << "Can\'t open FIFO for reading\n";
        exit(-1);
    }
    size_t size;
    size = read(fd, static_cast<void *>(m_bolid), sizeof(BTBolidData));

}