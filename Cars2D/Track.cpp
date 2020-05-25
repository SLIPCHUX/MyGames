#include "Track.h"

Track::Track()
{
	const int BorderWidth = 3;
	spriteSelector = one;

	GenerateTextSprite();

	trackTextSprite[one].SetPosition(0, 0);

	leftBorder.SetLeft(0);
	leftBorder.SetWidth(BorderWidth);
	leftBorder.SetTop(0);
	leftBorder.SetHeight(trackTextSprite[one].GetHeight());

	rightBorder.SetLeft(trackTextSprite[one].GetWidth() - BorderWidth);
	rightBorder.SetWidth(BorderWidth);
	rightBorder.SetTop(0);
	rightBorder.SetHeight(trackTextSprite[one].GetHeight());
}

void Track::Draw(GraphicsEngine textWindow)
{
	switch (spriteSelector)
	{
	case one:
		textWindow.Draw(trackTextSprite[one]);
		spriteSelector = two;
		break;

	case two:
		textWindow.Draw(trackTextSprite[two]);
		spriteSelector = three;
		break;

	case three:
		textWindow.Draw(trackTextSprite[three]);
		spriteSelector = one;
		break;
	}
}

Box& Track::GetLeftBorder()
{
	return leftBorder;
}

Box& Track::GetRightBorder()
{
	return rightBorder;
}

Track::~Track()
{

}

void Track::GenerateTextSprite()
{
	Sprite sprt1, sprt2, sprt3;

	for (size_t i = 0; i < 15; ++i)
	{
		sprt1.AddLine("||-                 |                 -||");
		sprt1.AddLine("||-                 |                 -||");
		sprt1.AddLine("||-                 |                 -||");
	}
	for (size_t i = 0; i < 15; ++i)
	{
		sprt2.AddLine("||-                 |                 -||");
		sprt2.AddLine("||-                 |                 -||");
		sprt2.AddLine("||-                 |                 -||");
	}
	for (size_t i = 0; i < 15; ++i)
	{
		sprt3.AddLine("||-                 |                 -||");
		sprt3.AddLine("||-                 |                 -||");
		sprt3.AddLine("||-                 |                 -||");
	}

	sprt1.SetPosition(0, 0);
	sprt2.SetPosition(0, 0);
	sprt3.SetPosition(0, 0);

	trackTextSprite.insert(std::pair<selector, Sprite>(one, sprt1));
	trackTextSprite.insert(std::pair<selector, Sprite>(two, sprt2));
	trackTextSprite.insert(std::pair<selector, Sprite>(three, sprt3));
}
