#include "stdafx.h"
#include "Shuffle.h"

Shuffle::Shuffle(const std::shared_ptr<PictureArray>& array)
 : Algorithm(array), m_index(0) {
	for (std::uint32_t i = 0; i < p_array->getArraySize(); i++) {
		m_tempArray.emplace_back(i);
	}

	srand(time(NULL));
}

void Shuffle::run() {
	std::size_t selectedIndex = rand() % m_tempArray.size();
	p_array->swap(m_index, m_tempArray[selectedIndex]);
	m_tempArray.erase(m_tempArray.begin() + selectedIndex);

	m_index++;

	if (m_index == p_array->getArraySize() - 1) {
		markComplete();
	}
}