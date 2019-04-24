#include "BTSender.hpp"


void BTSender::send()
{
}


void BTSender::setBolidData(BTBolidData *bolidData)
{
	m_bolid = bolidData;
}


BTBolidData *BTSender::getBolidData() const
{
	return m_bolid;
}
