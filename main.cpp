#include <iostream>
#include <vector>
#include "raylib.h"

class Square
{
private:
	bool isClicked = false;
	Vector2 pos;

public:
	Square(int x, int y);
	void checkClick();
	void drawSquare();
};

void Square::drawSquare()
{
	if (!isClicked)
	{
		DrawRectangleLines(100 + pos.x * 200, 100 + pos.y * 200, 200, 200, BLACK);
	}
	else
	{
		DrawRectangle(100 + pos.x * 200, 100 + pos.y * 200, 200, 200, RED);
	}
	
}

Square::Square(int x, int y) : pos{ (float)x, (float)y }
{
	std::cout << "Square created: (" << pos.x << ", " << pos.y << ")" << std::endl;
}

void Square::checkClick()
{
	if (!isClicked)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			//std::cout << "mouse is at " << GetMousePosition().x << " " << GetMousePosition().y << std::endl;
			Vector2 mouseClick = GetMousePosition();
			if (mouseClick.x > 100 + this->pos.x * 200 && mouseClick.x < 100 + this->pos.x * 200 + 200 &&
				mouseClick.y > 100 + this->pos.y * 200 && mouseClick.y < 100 + this->pos.y * 200 + 200)
			{
				isClicked = true;
				std::cout << "drawn at " << pos.x << " " << pos.y << std::endl;
				//std::cout << "click detected";
			}
		}
	}
	
}

int main()
{
	InitWindow(800, 800, "TTT");

	// Flags
	//SetWindowState(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	std::vector<Square> array;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array.push_back(Square(i, j));
			//DrawRectangleLines(125+ i * 800/5, 125+ j * 800/5, GetScreenHeight() / 5, GetScreenWidth() / 5, BLACK);
		}
	}


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		for (int i = 0; i < 9; i++)
		{
			array[i].drawSquare();
			array[i].checkClick();
		}

		DrawFPS(10, 10);

		EndDrawing();
	}
}

