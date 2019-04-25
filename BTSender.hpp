#pragma once
#include "BTBolid.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "BTDefines.hpp"


class BTSender
{
public:
	void send();

	void setBolidData(BTBolidData *bolidData);
	BTBolidData *getBolidData() const;
	BTSender();
	
private:
	BTBolidData *m_bolid;
	int m_fd;
};
