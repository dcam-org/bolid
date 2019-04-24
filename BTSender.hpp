#pragma once
#include "BTBolid.hpp"


class BTSender
{
public:
	void send();

	void setBolidData(BTBolidData *bolidData);
	BTBolidData *getBolidData() const;
	
private:
	BTBolidData *m_bolid;
};
