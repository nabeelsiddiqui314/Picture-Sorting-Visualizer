#pragma once
#include "Algorithm.h"

class Shuffle : public Algorithm
{
public:
	Shuffle(const std::shared_ptr<PictureArray>& array);
	~Shuffle() = default;
public:
	void run() override;
private:
	std::vector<std::uint32_t> m_tempArray;
	std::size_t m_index;
};

