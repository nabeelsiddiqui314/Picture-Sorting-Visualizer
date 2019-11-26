#include "stdafx.h"
#include "BubbleSort.h"

BubbleSort::BubbleSort(const std::shared_ptr<PictureArray>& array)
 : Algorithm(array), m_index(0), m_sortedCount(0), m_isScrambled(false) {}

void BubbleSort::run() {
	if ((*p_array)[m_index] > (*p_array)[m_index + 1]) {
		p_array->swap(m_index, m_index + 1);
		m_isScrambled = true;
	}

	m_index++;

	if (m_index + 1 >= p_array->getArraySize() - m_sortedCount) {
		m_index = 0;
		m_sortedCount++;

		if (!m_isScrambled) {
			markComplete(); // is sorted if everything until the end marker is sorted
		}
		else {
			m_isScrambled = false; // reset the flag for the next iteration
		}
	}

	if (m_sortedCount >= p_array->getArraySize()) {
		markComplete();
	}
}