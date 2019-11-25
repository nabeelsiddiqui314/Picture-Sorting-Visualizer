#include "stdafx.h"
#include "Algorithm.h"

Algorithm::Algorithm(const std::shared_ptr<PictureArray>& array) 
	: p_array(array), m_hasCompleted(false) {}

bool Algorithm::hasCompleted() const {
	return m_hasCompleted;
}

void Algorithm::markComplete() {
	m_hasCompleted = true;
}