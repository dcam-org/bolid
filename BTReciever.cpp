#include "BTReciever.hpp"




void BTReciever::recieve()
{
    if((m_fd = open(BT_FIFO_NAME, O_RDONLY)) < 0)
    {
        std::cout << "Can\'t open FIFO for reading\n";
    }

    size_t size = read(m_fd, (void *)m_bolid, sizeof(BTBolidData));
    if (m_bolid == nullptr)
    {
        std::cout << "Someone fucked up\nDidn't recieve any data\n";
    }
    assert(m_bolid);
    assert(size);

}

void BTReciever::setBolidData(BTBolidData *bolidData)
{
    m_bolid = bolidData;
}

BTBolidData *BTReciever::getBolidData() const
{
    return m_bolid;
}