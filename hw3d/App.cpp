#include "App.h"
#include "Timer.h"

App::App() noexcept : wnd(800, 600, "First App") {}

int App::Start() noexcept
{
	MSG msg;
	BOOL gResult;
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			// If we got a value, it means were quitting so return
			return *ecode;
		}

		DoFrame();
	}
}

void App::DoFrame() noexcept
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}