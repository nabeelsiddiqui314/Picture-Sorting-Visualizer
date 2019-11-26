#include "stdafx.h"
#include "PictureArray.h"

PictureArray::PictureArray() {
	m_imageBuffer.loadFromFile("picture/picture.jpg");
	m_array = std::make_unique<std::uint32_t[]>(getArraySize());
}

std::uint32_t PictureArray::operator[](std::size_t index) const {
	return m_array[index];
}

void PictureArray::swap(std::uint32_t index1, std::uint32_t index2) {
	auto tempValue = m_array[index1];
	auto tempColor = m_imageBuffer.getPixel(getX(index1), getY(index1));

	m_array[index1] = m_array[index2];
	m_imageBuffer.setPixel(getX(index1), getY(index1), m_imageBuffer.getPixel(getX(index2), getY(index2)));

	m_array[index2] = tempValue;
	m_imageBuffer.setPixel(getX(index2), getY(index2), tempColor);
}

const std::size_t PictureArray::getArraySize() const {
	return m_imageBuffer.getSize().x * m_imageBuffer.getSize().y;
}

const sf::Image& PictureArray::getImageBuffer() const {
	return m_imageBuffer;
}

inline std::uint32_t PictureArray::getX(std::size_t index) const {
	return index % m_imageBuffer.getSize().x;
}

inline std::uint32_t PictureArray::getY(std::size_t index) const {
	return (index - getX(index)) / m_imageBuffer.getSize().x;
}