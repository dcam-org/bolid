#include "BTSender.hpp"


void BTSender::send()
{
	write(m_fd, static_cast<void *>(m_bolid), sizeof(BTBolidData));
}


void BTSender::setBolidData(BTBolidData *bolidData)
{
	m_bolid = bolidData;
}


BTBolidData *BTSender::getBolidData() const
{
	return m_bolid;
}
