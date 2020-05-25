#include "Box.h"

Box::Box()
	: left(0), top(0), width(0), height(0)
{
}

Box::Box(int left, int top, int width, int height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

bool Box::CheckColliding(Box box)
{
	bool collidingVertical = false;
	bool collidingHorizontal = false;

	if (((left >= box.GetLeft()) && (left <= box.GetRight())) ||
		((GetRight() >= box.GetRight()) && (GetRight() <= box.GetRight())) ||
		((box.GetLeft() >= left) && (box.GetLeft() <= GetRight())) ||
		((box.GetRight() >= GetLeft()) && (box.GetRight() <= GetRight())))
	{
		collidingVertical = true;
	}

	if (((top >= box.GetTop()) && (top <= box.GetBottom())) ||
		((GetBottom() >= box.GetTop()) && (GetBottom() <= box.GetBottom())) ||
		((box.GetTop() >= top) && (box.GetTop() <= GetBottom())) ||
		((box.GetBottom() >= GetTop()) && (box.GetBottom() <= GetBottom())))
	{
		collidingHorizontal = true;
	}

	return collidingVertical && collidingHorizontal;
}

int Box::GetLeft()
{
	return this->left;
}

int Box::GetTop()
{
	return this->top;
}

int Box::GetRight()
{
	return this->left + this->width;
}

int Box::GetBottom()
{
	return this->top + this->height;
}

void Box::SetLeft(int left)
{
	this->left = left;
}

void Box::SetTop(int top)
{
	this->top = top;
}

void Box::SetWidth(int width)
{
	this->width = width;
}

void Box::SetHeight(int height)
{
	this->height = height;
}


Box::~Box()
{
}
