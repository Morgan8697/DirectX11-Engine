#pragma once
/*Window wnd(800, 300, "First Window through framework");

// Message handling
MSG msg;
BOOL gResult;
while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
{
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	/*************** TO TEST WHEEL UP/DOWN *********************/
	/*static int i = 0;
	while (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();
		switch (e.GetType())
		{
		case Mouse::Event::Type::WheelUp:
			i++;
			{
				std::ostringstream oss;
				oss << "Up: " << i;
				wnd.SetTitle(oss.str());
			}
			break;
		case Mouse::Event::Type::WheelDown:
			i--;
			{
				std::ostringstream oss;
				oss << "Down: " << i;
				wnd.SetTitle(oss.str());
			}
			break;
		}
	}*/

	/************ TO TEST MOUSE LEAVING/ENTERING **************/

	/*while (!wnd.mouse.IsEmpty())
	{
		const Mouse::Event e = wnd.mouse.Read();
		switch (e.GetType())
		{
		case Mouse::Event::Type::Leave:
			wnd.SetTitle("We're out!");
			break;
		case Mouse::Event::Type::Move:
		{
			std::ostringstream oss;
			oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
			wnd.SetTitle(oss.str());
		}
		break;
		}
	}*/
	/**************** TO TEST MOUSE MOVEMENT *****************/

	/*while (!wnd.mouse.IsEmpty())
	{
		const Mouse::Event e = wnd.mouse.Read();
		if (e.GetType() == Mouse::Event::Type::Move)
		{
			std::ostringstream oss;
			oss << "Mouse Position: (" << e.GetPosX() << "," << e.GetPosY() << ")";
			wnd.SetTitle(oss.str());
		}
	}*/
	/************** TO TEST KEYBOARD ****************/
	/*if (wnd.kbd.KeyIsPressed(VK_MENU))
	{
		MessageBox(nullptr, "Something happened", "Alt was pressed", MB_OK | MB_ICONEXCLAMATION);
	}*/