#include "stdafx.h"
#include "PictureArray.h"

PictureArray::PictureArray() {
	m_imageBuffer.loadFromFile("picture/picture.jpg");
}

void PictureArray::swap(std::uint32_t index1, std::uint32_t index2) {

}

const std::size_t PictureArray::getArraySize() const {
	return m_imageBuffer.getSize().x * m_imageBuffer.getSize().y;
}

const sf::Image& PictureArray::getImageBuffer() const {
	return m_imageBuffer;
}
