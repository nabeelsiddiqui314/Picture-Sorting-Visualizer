#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class PictureArray
{
public:
	PictureArray();
	~PictureArray() = default;
public:
	void shuffle();
	void swap(std::uint32_t index1, std::uint32_t index2);
	const std::size_t getArraySize() const;

	const sf::Image& getImageBuffer() const;
private:
	inline std::size_t getRandomIndex(std::size_t maxSize) const;
	inline std::uint32_t getX(std::size_t index) const;
	inline std::uint32_t getY(std::size_t index) const;
private:
	sf::Image m_imageBuffer;
	std::unique_ptr<std::uint32_t[]> m_array;
};

