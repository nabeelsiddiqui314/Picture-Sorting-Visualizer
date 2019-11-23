#include "stdafx.h"
#include "PictureArray.h"

PictureArray::PictureArray() {
	m_picture.loadFromFile("picture/picture.jpg");
}

void PictureArray::swap(std::uint32_t index1, std::uint32_t index2) {

}

const std::size_t PictureArray::getArraySize() const
{
	return std::size_t();
}

const sf::Image & PictureArray::getPictureBuffer() const {
	return m_picture;
}
