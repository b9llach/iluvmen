// OpenSourceRustScript.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "includes.h"

int main()
{
    SetConsoleTitle(L"iluvmen");

	// getting window handle and moving / changing the console window
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		(info.srWindow.Right - info.srWindow.Left + 1),
		(info.srWindow.Bottom - info.srWindow.Top + 1)
	};
	SetConsoleScreenBufferSize(handle, new_size);
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, GetSystemMetrics(SM_CXSCREEN) / 2 - 330, GetSystemMetrics(SM_CYSCREEN) / 2 - 390, 660, 600, TRUE); } else { exit(0); }
	SetLayeredWindowAttributes(hwnd, 1000, 1000, LWA_COLORKEY);
	SetConsoleScreenBufferSize(handle, new_size);

	// init classes
	gui mgui;
	config mconf;
	weapon mweap;

	system("color 0c"); // changes color of console

	std::cout << "enter sens: ";
	std::cin >> mconf.settings["SENS"];

	std::cout << "\nenter fov: ";
	std::cin >> mconf.settings["FOV"];

	mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);

	// settings being set (could turn this into a keybind)
	// using the config system you can also load from a default config here

	mconf.settings["AK47"] = 113;
	mconf.settings["LR300"] = 114;
	mconf.settings["TOMMY"] = 115;
	mconf.settings["MP5"] = 116;
	mconf.settings["CUSTOM"] = 117;

	mconf.settings["BLATANT"] = 1;

	mconf.settings["ACTIVE"] = 1;

	while (true) {
		// keybinds for changing weapons / sights / barrels
		// add keybind settings above for the scopes and blatant / humanized and to enable / disable

#pragma region keybinds
		if (GetAsyncKeyState(mconf.settings["AK47"])) {
			mweap.cweapon = "AK47";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["LR300"])) {
			mweap.cweapon = "LR300";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["TOMMY"])) {
			mweap.cweapon = "TOMMY";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["MP5"])) {
			mweap.cweapon = "MP5";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["CUSTOM"])) {
			mweap.cweapon = "CUSTOM";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["NOSIGHT"])) {
			mweap.cscope = "NONE";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["HOLO"])) {
			mweap.cscope = "HOLO";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["8X"])) {
			mweap.cscope = "8X";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}

		if (GetAsyncKeyState(mconf.settings["16X"])) {
			mweap.cscope = "16X";
			mgui.printGUI(mweap.cweapon, mweap.cscope, mweap.cbarrel);
		}
#pragma endregion

		// some other things you can add on:
		// 
		// multiply x and y by .6 to get the hipfire / noscope values
		// add hipfire (basically check if left mouse is down and hipfire is enabled)
		// anti afk (randomly move mouse and create keyboard events to jump, look, etc.)
		// automatic door code lock system (again keyboard events)

		if (bstd::GetActiveWindowTitle() == "Rust")  { // only active while tabbed into rust
			if (mconf.settings["ACTIVE"] == 1) { // script is on
				mconf.settings["MAG"] = 0;
				mweap.get_info();
				while (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON) && mconf.settings["MAG"] < mweap.ctable.size()) {
					if (mconf.settings["BLATANT"] == 1) {
						mweap.blatant(mweap.cdelay, mweap.ccontroltime.at(mconf.settings["MAG"]), (mweap.ctable.at(mconf.settings["MAG"]).x / 2) * mweap.get_scope(), (mweap.ctable.at(mconf.settings["MAG"]).y / 2)* mweap.get_scope());
						mconf.settings["MAG"]++;
					}
					else {
						mweap.humanized(mweap.cdelay, mweap.ccontroltime.at(mconf.settings["MAG"]), (mweap.ctable.at(mconf.settings["MAG"]).x / 2) * mweap.get_scope(), (mweap.ctable.at(mconf.settings["MAG"]).y / 2) * mweap.get_scope());
						mconf.settings["MAG"]++;
					}
				}
			}
		}
	}
}

