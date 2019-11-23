#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class PictureArray
{
public:
	PictureArray();
	~PictureArray() = default;
public:
	void swap(std::uint32_t index1, std::uint32_t index2);
	const std::size_t getArraySize() const;

	const sf::Image& getPictureBuffer() const;
private:
	sf::Image m_picture;
	std::unique_ptr<std::uint32_t[]> m_array;
};

