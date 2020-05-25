internal void drawBackground(int i)
{
	u32* pixel = static_cast<u32*>(render_state.memory);
	for (int y = 0; y < render_state.height; y++)
	{
		for (int x = 0; x < render_state.width; x++)
		{
			*pixel++ = x + y + i;
		}
	}
}
internal void clearScreen(unsigned int color)
{
	u32* pixel = static_cast<u32*>(render_state.memory);
	for (int y = 0; y < render_state.height; y++)
	{
		for (int x = 0; x < render_state.width; x++)
		{
			*pixel++ = color;
		}
	}
}

internal void drawRectInPixels(int x0, int y0, int x1, int y1, u32 color)
{
	x0 = clamp(0, x0, render_state.width);
	x1 = clamp(0, x1, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	y1 = clamp(0, y1, render_state.height);
	
	for (int y = y0; y < y1; y++)
	{
		u32* pixel = static_cast<u32*>(render_state.memory) + x0 + y * render_state.width;
		for (int x = x0; x < x1; x++)
		{
			*pixel++ = color;
		}
	}
}

global_variable float render_scale = 0.01f;

internal void drawRect(float x, float y, float half_size_x, float half_size_y, u32 color)
{
	x *= render_state.height * render_scale;			//0
	y *= render_state.height * render_scale;			//0
	half_size_y *= render_state.height * render_scale;	//20 * 681 + 00,1
	half_size_x *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;


	//Change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;
	drawRectInPixels(x0, y0, x1, y1, color);
	
}


internal void drawNumber(int number, float x, float y, float size, u32 color)
{
	float half_size = size * 0.5f;
	switch (number)
	{
	case 0:
	{
		drawRect(x - size, y, half_size, 2.5f * size, color);
		drawRect(x + size, y, half_size, 2.5f * size, color);
		drawRect(x, y + size * 2.f, half_size,  half_size, color);
		drawRect(x, y - size * 2.f, half_size, half_size, color);




	} break;

	case 1:
	{
		drawRect(x, y, half_size, size * 2.5f, color);
	} break;

	case 2:
	{
		drawRect(x, y + size * 2, 1.5f * size, half_size, color);
		drawRect(x, y, 1.5f * size, half_size, color);
		drawRect(x, y - size * 2.f, 1.5f * size, half_size, color);
		drawRect(x - size, y - size, half_size, half_size, color);
		drawRect(x + size, y + size, half_size, half_size, color);
	} break;

	case 3:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x, y, size * 1.5f, half_size, color);
		drawRect(x, y - size * 2.f, size * 1.5f, half_size, color);
		drawRect(x + size, y, half_size, size * 1.5f, color);

	} break;

	case 4:
	{
		drawRect(x - size, y + size, half_size, size * 1.5f, color);
		drawRect(x + size, y, half_size, size * 2.5f, color);
		drawRect(x, y - half_size, size * 1.5f, half_size, color);
	} break;

	case 5:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x, y, size * 1.5f, half_size, color);
		drawRect(x, y - size * 2.f, size * 1.5, half_size, color);
		drawRect(x - size, y + size, half_size, size * 1.5f, color);
		drawRect(x + size, y - size, half_size, size * 1.5f, color);
	} break;

	case 6:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x, y, size * 1.5f, half_size, color);
		drawRect(x, y - size * 2.f, size * 1.5f, half_size, color);
		drawRect(x - size, y - size, half_size, half_size, color);
		drawRect(x + size, y - size, half_size, half_size, color);
		drawRect(x - size, y + size, half_size, half_size, color);
	} break;

	case 7:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x + size, y, half_size, size * 2.5f, color);
	} break;

	case 8:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x, y, size * 1.5f, half_size, color);
		drawRect(x, y - size * 2.f, size * 1.5f, half_size, color);
		drawRect(x - size, y, half_size, size * 1.5f, color);
		drawRect(x + size, y, half_size, size * 1.5f, color);

	} break;

	case 9:
	{
		drawRect(x, y + size * 2.f, size * 1.5f, half_size, color);
		drawRect(x, y, size * 1.5f, half_size, color);
		drawRect(x - size, y + size, half_size, size, color);
		
	} break;

	}



}



//что быстрее компилятор или интерпретатор, где лучше исправлять ошибки, формклы бека санаура, общее среднее о граматиках
//согласованость, поддержка расширений языка: свои функции, классы
//Возможность приведения типов (когда делим на число, а когда на строку)
//Хороший язык не даст создать что-то не правильное
//Критерии к транслятору: быстродействие, объем транслятора (дисковое простантсво), объем исполняемого кода (который на выходе),
//исправление ошибок (хорошая система исправления ошибок: где ошибка (строка..), номер ошибки, и как её исправить 


//Лексический анализатор,синтаксический анализатор, генератор кода (программа на языке выского уровня -> низкого уровня)
//начинаем с алфавита и лексики. 
//Первый класс - Наименшая допустимая еденица - лексема (зарезервированное слово)
//Вторый класс лексем - идентификаторы
//Трейтий класс лексем - условные операторы
//Четвертый класс лексем - разделители
//Пятый класс - комментарии
//Шестой класс - литералы
//
//Нужна формальная система, которая сможет все это описать: диаграммы



//Назначение языка
