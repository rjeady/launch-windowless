#include <windows.h>
#include <string>

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
	)
{
	// by sending to cmd, we allow our first argument (the program to launch) to be resolved in PATH
	// the /S argument tells it to keep quotes inside the passed command (except the outermost ones)
	auto command = L"cmd /S /C \"" + std::wstring(lpCmdLine) + L"\"";

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	return CreateProcessW(NULL, &command[0], NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
}
