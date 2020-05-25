struct Button_State
{
	bool isDown;
	bool changed;
};

enum MyEnum
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_W,
	BUTTON_S,

	BUTTON_COUNT,
};

struct Input
{
	Button_State buttons[BUTTON_COUNT];
};