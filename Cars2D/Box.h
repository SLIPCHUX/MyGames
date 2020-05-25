#pragma once
class Box
{
public:
	Box();

	Box(int left, int top, int width, int height);

	bool CheckColliding(Box box);

	int GetLeft();

	int GetTop();

	int GetRight();

	int GetBottom();

	void SetLeft(int left);

	void SetTop(int top);

	void SetWidth(int width);

	void SetHeight(int height);

	~Box();

private:
	int left;
	int top;
	int width;
	int height;
};

