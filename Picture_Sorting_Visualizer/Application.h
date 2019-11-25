#pragma once
#include "PictureArray.h"

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
private:
	sf::RenderWindow m_window;

	PictureArray m_array;
	sf::Texture m_pictureTexture;
	sf::RectangleShape m_pictureQuad;
};

