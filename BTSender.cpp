#include "BTSender.hpp"


void BTSender::send()
{
	write(m_fd, static_cast<void *>(m_bolid), sizeof(BTBolidData));
}


void BTSender::setBolidData(BTBolidData *bolidData)
{
	m_bolid = bolidData;
}

int BTSender::getBolidFd()
{
	return m_fd;
}

BTSender::BTSender()
{
	if( mknod(BT_FIFO_NAME, S_IFIFO | 0666, 0)<0 )
	{
		printf("cant create fifo \n");
	}
	if ( (m_fd = open(BT_FIFO_NAME ,O_WRONLY)) <0)
	{
		printf("cant open fifo\n");
		_exit(-1);
	}
}


BTSender::~BTSender()
{
	close(getBolidFd());
}

BTBolidData *BTSender::getBolidData() const
{
	return m_bolid;
}
