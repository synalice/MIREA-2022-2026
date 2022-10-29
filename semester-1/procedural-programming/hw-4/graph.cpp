#define _USE_MATH_DEFINES

#include <windows.h>
#include <conio.h>
#include <cmath>


int main() {
	HDC hdc = GetDC(GetConsoleWindow());
	COLORREF penColor = RGB(255, 255, 255);
	HPEN pen = CreatePen(PS_SOLID, 4, penColor);

	SelectObject(hdc, pen);
	MoveToEx(hdc, 0, 250, NULL);
	LineTo(hdc, 1500, 250);
	MoveToEx(hdc, 400, 0, NULL);
	LineTo(hdc, 400, 1000);

	double chast = 100;
	double ampl = 100;

	for (int i = -1000; i < 1000; ++i) {
		double y = sin(M_PI * i / chast);
		LineTo(hdc, 100 + i, 250 + int(ampl * y));
		MoveToEx(hdc, 100 + i, 250 + int(ampl * y), NULL);
	}
}
