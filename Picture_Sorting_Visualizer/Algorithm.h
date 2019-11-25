#pragma once
#include "PictureArray.h"

class Algorithm
{
public:
	Algorithm(const std::shared_ptr<PictureArray>& array);
	virtual ~Algorithm() = default;
public:
	virtual void run() = 0;
	bool hasCompleted() const;
protected:
	void markComplete();
protected:
	std::shared_ptr<PictureArray> p_array;
private:
	bool m_hasCompleted;
};

