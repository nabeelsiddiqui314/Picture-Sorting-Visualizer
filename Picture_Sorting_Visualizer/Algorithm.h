#pragma once
#include "PictureArray.h"

class Algorithm
{
public:
	Algorithm(const std::shared_ptr<PictureArray>& array);
	virtual ~Algorithm() = default;
public:
	virtual void init() = 0;
	virtual void run() = 0;
protected:
	std::shared_ptr<PictureArray> p_array;
};

