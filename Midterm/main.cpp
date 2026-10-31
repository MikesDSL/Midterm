#include "raylib.h"
#include <string>
#include <cmath>
#include "raymath.h"
#include <vector>
#include <time.h>
#include "drawingDot.h"
#include <vector>
#include <iostream>

void Hypotrochoid()
{
	InitWindow(500, 500, "Hypotrochoid");
	SetTargetFPS(60);

	float center = 250.0f;
	float bigRadius = 180.0f;
	float smallRadius = 50.0f;

	float drawDistance = 68.0f;

	float angle = 0.0f;

	std::vector<Dotty> dotties;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Color{ 23, 10, 35 });

		if (IsKeyDown(KEY_LEFT))
		{
			drawDistance = drawDistance >= 1.0f ? drawDistance - 1.0f : 0.0f;
			dotties.clear();
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			drawDistance = drawDistance <= 100.0f ? drawDistance + 1.0f : 100.0f;
			dotties.clear();
		}
		if (IsKeyDown(KEY_UP))
		{
			bigRadius = bigRadius >= 100.0f ? bigRadius - 1.0f : 100.0f;
			dotties.clear();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			bigRadius = bigRadius <= 250.0f ? bigRadius + 1.0f : 250.0f;
			dotties.clear();
		}

		float distance = bigRadius - smallRadius;

		angle += 0.075f;

		float xPos = distance * cos(angle);
		float yPos = distance * sin(angle);

		float drawX = xPos + drawDistance * cos((distance / smallRadius) * angle);
		float drawY = yPos - drawDistance * sin((distance / smallRadius) * angle);

		DrawCircleLines(center, center, bigRadius, Color{ 198,120,235, 250 });
		DrawCircleLines(center + xPos, center + yPos, smallRadius, Color{ 198,120,235, 200 });

		DrawCircle(center + drawX, center + drawY, 5, Color{ 255,102,204,255 });
		dotties.push_back(Dotty(center + drawX, center + drawY));

		DrawLine(center + drawX, center + drawY, center + xPos, center + yPos, Color{ 249,196,235,255 });

		for (size_t i = 1; i < dotties.size(); ++i)
		{
			DrawLine(dotties[i-1].xPos, dotties[i-1].yPos, dotties[i].xPos, dotties[i].yPos, Color{255,102,204,255});
		}

		std::string txt = "Miks";
		int fontSize = 50;
		int txtX = MeasureText(txt.c_str(), fontSize);

		EndDrawing();
	}
	CloseWindow();
}

int main()
{
	srand((unsigned)time(0));
	Hypotrochoid();
	return 0;
}