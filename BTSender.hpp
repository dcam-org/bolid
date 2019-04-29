#pragma once
#include "BTBolide.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "BTDefines.hpp"


class BTSender
{
public:
	void send();

	void setBolideData(BTBolideData *bolidData);
	BTBolideData *getBolideData() const;
	int getBolideFd();
	BTSender();
	~BTSender();
	
private:
	BTBolideData *m_bolid;
	int m_fd;
};
