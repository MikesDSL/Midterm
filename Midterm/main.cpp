#include "raylib.h"
#include <string>
#include <cmath>
#include "raymath.h"
#include <vector>
#include <time.h>

void FirstDrawing()
{
	int polyRotation = -18;

	

	DrawCircle(250, 250, 80, Color{ 255,102,204 , 200 });

	DrawPoly(Vector2{ 250,250 }, 5, 80, polyRotation, Color{ 0,0,0, 100 });

	DrawPolyLinesEx(Vector2{ 250, 250 }, 5, 75, polyRotation, 2, Color{ 255,102,204,255 });

	std::string txt = "Miks";
	int fontSize = 50;
	int txtX = MeasureText(txt.c_str(), fontSize);
	//DrawText(txt.c_str(), 250 - (txtX / 2), 250 - (fontSize / 2), fontSize, Color{ 255,234,242, 220 });
}

void TestDraw()
{
	InitWindow(500, 500, "My Test Game");
	SetTargetFPS(60);

	int polyRotation = -18;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Color{ 23, 10, 35 });

		FirstDrawing();

		EndDrawing();
	}
	CloseWindow();
}

int main()
{
	srand((unsigned)time(0));
	TestDraw();
	return 0;
}