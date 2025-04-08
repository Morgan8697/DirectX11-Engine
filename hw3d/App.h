#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App() noexcept;
	int Start() noexcept;
private:
	void DoFrame() noexcept;
private:
	Window wnd;
	Timer timer;
};