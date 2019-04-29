#include "BTReceiver.hpp"




void BTReceiver::receive()
{

    assert(m_bolid);
    size_t size = read(m_fd, (void *)m_bolid, sizeof(BTBolideData));
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

void BTReceiver::setBolideData(BTBolideData *bolidData)
{
    m_bolid = bolidData;
}

BTBolideData *BTReceiver::getBolideData() const
{
    return m_bolid;
}