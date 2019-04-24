#pragma once
#include "BTBolid.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


class BTSender
{
public:
	void send();

	void setBolidData(BTBolidData *bolidData);
	BTBolidData *getBolidData() const;
	
private:
	BTBolidData *m_bolid;
	int m_fd;
};
