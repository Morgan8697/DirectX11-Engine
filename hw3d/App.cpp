#include "App.h"

App::App() : wnd(800, 600, "First App") {}

int App::Start()
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

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time Elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}