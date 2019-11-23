#pragma once
#include "Application.h"

class MainWindow
{
public:
	MainWindow(std::uint32_t width, std::uint32_t height, const std::string& title, Application* app);
	~MainWindow() = default;
public:
	void run();
private:
	sf::RenderWindow m_window;
	Application* p_app;
};

