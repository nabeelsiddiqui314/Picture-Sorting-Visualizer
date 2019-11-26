#pragma once
#include "Algorithm.h"

class BubbleSort : public Algorithm
{
public:
	BubbleSort(const std::shared_ptr<PictureArray>& array);
	~BubbleSort() = default;
public:
	void run() override;
private:
	std::size_t m_index;
	std::size_t m_sortedCount;
	bool m_isScrambled;
};

