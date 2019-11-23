#pragma once
#include "PictureArray.h"

class Application
{
public:
	Application();
	~Application() = default;
public:
	void onEvent(const sf::Event& event);
	void render(sf::RenderTarget& renderer);
private:
	void updatePicture();
private:
	PictureArray m_array;
	sf::Texture m_pictureTexture;
	sf::RectangleShape m_pictureQuad;
};

