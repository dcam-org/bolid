#include "BTReceiver.hpp"




void BTReceiver::receive()
{


    size_t size = read(m_fd, (void *)m_bolid, sizeof(BTBolidData));
    if (m_bolid == nullptr)
    {
        std::cout << "Someone fucked up\nDidn't receive any data\n";
    }
    assert(m_bolid);
    assert(size);

}

void BTReceiver::openFifo()
{
    if((m_fd = open(BT_FIFO_NAME, O_RDONLY)) < 0)
    {
        std::cout << "Can\'t open FIFO for reading\n";
    }
}

void BTReceiver::closeFifo()
{
    close(m_fd);
}

void BTReceiver::setBolidData(BTBolidData *bolidData)
{
    m_bolid = bolidData;
}

BTBolidData *BTReceiver::getBolidData() const
{
    return m_bolid;
}