#pragma once
#include "PictureArray.h"
#include "Algorithm.h"

class Application
{
public:
	Application();
	~Application() = default;
public:
	void run();
private:
	void handleEvents();
	void applyTextureToImage();
	void runAlgorithmFor(std::uint32_t times);
private:
	sf::RenderWindow m_window;

	std::unique_ptr<Algorithm> m_algorithm;
	std::shared_ptr<PictureArray> m_array;

	sf::Texture m_pictureTexture;
	sf::RectangleShape m_pictureQuad;

	sf::Clock m_frameClock;
};

