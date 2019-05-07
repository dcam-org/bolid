#pragma once
#include "BTBolide.hpp"
#include <vector>


class BTDataset
{
public:
	std::vector<std::vector<BTBolideData *>> getDataset() const;

private:
	std::vector<std::vector<BTBolideData *>> m_dataset;
};