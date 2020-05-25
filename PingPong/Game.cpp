#define is_down(b) input->buttons[b].isDown
#define pressed(b) (input->buttons[b].isDown && input->buttons[b].changed)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].changed)


const float arena_half_size_x = 90.f;
const float arena_half_size_y = 45.f;



internal void SimulateGame(Input* input, float delta_time)
{
	firstPlayer.SetPlayerDdp(0.f);
	if (is_down(BUTTON_UP)) firstPlayer.SetPlayerDdp(2000.f);
	if (is_down(BUTTON_DOWN)) firstPlayer.SetPlayerDdp(-2000.f);

	secondPlayer.SetPlayerDdp(0.f);
	if (is_down(BUTTON_W)) secondPlayer.SetPlayerDdp(2000.f);
	if (is_down(BUTTON_S)) secondPlayer.SetPlayerDdp(-2000.f);

	firstPlayer.CalculateImpulse(delta_time);
	firstPlayer.CalculateCollision(arena_half_size_x, arena_half_size_y);

	secondPlayer.CalculateImpulse(delta_time);
	secondPlayer.CalculateCollision(arena_half_size_x, arena_half_size_y);


	ball.CalculatePosition(delta_time);
	ball.CalculateCollision(firstPlayer, secondPlayer, arena_half_size_x, arena_half_size_y);
	


	drawRect(0, 0, arena_half_size_x, arena_half_size_y, 0x0000FF);


	if (ball.GetFirstStatus())
	{
		++secondPlayer;
		ball.SetFirstStatus(false);
	}
	else if (ball.GetSecondStatus())
	{
		++firstPlayer;
		ball.SetSecondStatus(false);
	}


	//DRAW GAME-SCORE
	float at_x = -80;
	for (int i = 0; i < firstPlayer.GetScore(); i++)
	{
		drawRect(at_x,  47.f, 1.f, 1.f, 0xaaaaaaaa);
		at_x += 2.5f;

	}
	at_x = 80;
	for (int i = 0; i < secondPlayer.GetScore(); i++)
	{
		drawRect(at_x, 47.f, 1.f, 1.f, 0xaaaaaaaa);
		at_x -= 2.5f;

	}

	drawNumber(firstPlayer.GetScore(), 10, 40, 1.f, 0xbbffbb);
	drawNumber(secondPlayer.GetScore(), -10, 40, 1.f, 0xbbffbb);

	drawRect(ball.GetPosX(), ball.GetPosY(), ball.GetHalfSize(), ball.GetHalfSize(), 0xff5500);
	drawRect(80, firstPlayer.GetPlayerPos(), firstPlayer.GetPlayerHalfSizeX(), firstPlayer.GetPlayerHalfSizeY(), 0xff0000);
	drawRect(-80, secondPlayer.GetPlayerPos(), secondPlayer.GetPlayerHalfSizeX(), secondPlayer.GetPlayerHalfSizeY(), 0xff0000);
}







//float player_1_pos = 0.f;
//float player_1_dp = 0.f;
//float player_2_pos = 0.f;
//float player_2_dp = 0.f;
//float arena_half_size_x = 90.f;
//float arena_half_size_y = 45.f;
//float player_half_size_x = 2.f;
//float player_half_size_y = 12.f;
//float ball_pos_x, ball_pos_y, ball_dp_x = 100, ball_dp_y;
//float ball_half_size = 1.f;
//
//internal void simulateGame(Input* input, float delta_time)
//{
//	//clearScreen(0xff5500);
//	float player_1_ddp = 0.f;
//	if (is_down(BUTTON_UP)) player_1_ddp += 2000;
//	if (is_down(BUTTON_DOWN)) player_1_ddp -= 2000;
//
//	float player_2_ddp = 0.f;
//	if (is_down(BUTTON_W)) player_2_ddp += 2000;
//	if (is_down(BUTTON_S)) player_2_ddp -= 2000;
// 
//	player_1_ddp -= player_1_dp * 10.f;
//	player_1_pos = player_1_pos + player_1_dp * delta_time + player_1_ddp * delta_time * delta_time * 0.5f;
//	player_1_dp = player_1_dp + player_1_ddp * delta_time;
//
//	if (player_1_pos + player_half_size_y > arena_half_size_y)
//	{
//		player_1_pos = arena_half_size_y - player_half_size_y;
//		player_1_dp *= -1;
//	}
//	else if (player_1_pos - player_half_size_y < -arena_half_size_y)
//	{
//		player_1_pos = -arena_half_size_y + player_half_size_y;
//		player_1_dp *= -1;
//	}
//
//
//
//	player_2_ddp -= player_2_dp * 10.f;
//	player_2_pos = player_2_pos + player_2_dp * delta_time + player_2_ddp * delta_time * delta_time * 0.5f;
//	player_2_dp = player_2_dp + player_2_ddp * delta_time;
//
//	if (player_2_pos + player_half_size_y > arena_half_size_y)
//	{
//		player_2_pos = arena_half_size_y - player_half_size_y;
//		player_2_dp *= -1;
//	}
//	else if (player_2_pos - player_half_size_y < -arena_half_size_y)
//	{
//		player_2_pos = -arena_half_size_y + player_half_size_y;
//		player_2_dp *= -1;
//	}
//
//
//	ball_pos_x += ball_dp_x * delta_time;
//	ball_pos_y += ball_dp_y * delta_time;
//
//	if (ball_pos_x + ball_half_size > 80 - player_half_size_x &&
//		ball_pos_x - ball_half_size < 80 + player_half_size_x &&
//		ball_pos_y + ball_half_size > player_1_pos - player_half_size_y &&
//		ball_pos_y + ball_half_size < player_1_pos + player_half_size_y)
//	{
//		ball_pos_x = 80 - player_half_size_x - ball_half_size;
//		ball_dp_x *= -1;
//		ball_dp_y = (ball_pos_y - player_1_pos) * 2 + player_1_dp * 0.75f;
//	} 
//	else if (ball_pos_x + ball_half_size > -80 - player_half_size_x &&
//		ball_pos_x - ball_half_size < -80 + player_half_size_x &&
//		ball_pos_y + ball_half_size > player_2_pos - player_half_size_y &&
//		ball_pos_y + ball_half_size < player_2_pos + player_half_size_y)
//	{
//		ball_pos_x = -80 + player_half_size_x + ball_half_size;
//		ball_dp_x *= -1;
//		ball_dp_y = (ball_pos_y - player_2_pos) * 2 + player_2_dp * 0.75f;
//	}
//	if (ball_pos_y + ball_half_size > arena_half_size_y)
//	{
//		ball_pos_y = arena_half_size_y - ball_half_size;
//		ball_dp_y *= -1;
//	}
//	else if (ball_pos_y - ball_half_size < -arena_half_size_y)
//	{
//		ball_pos_y = -arena_half_size_y + ball_half_size;
//		ball_dp_y *= -1;
//	}
//
//	if (ball_pos_x + ball_half_size > arena_half_size_x)
//	{
//		ball_dp_x *= -1;
//		ball_dp_y = 0;
//		ball_pos_x = 0;
//		ball_pos_y = 0;
//	}
//	else if (ball_pos_x - ball_half_size < -arena_half_size_x)
//	{
//		ball_dp_x *= -1;
//		ball_dp_y = 0;
//		ball_pos_x = 0;
//		ball_pos_y = 0;
//	}
//
//	drawRect(0, 0, 90, 45, 0xfffff12);
//	drawRect(ball_pos_x, ball_pos_y, ball_half_size, ball_half_size, 0xff5500);
//	drawRect(80, player_1_pos, player_half_size_x, player_half_size_y, 0xff0000);
//	drawRect(-80, player_2_pos, player_half_size_x, player_half_size_y, 0xff0000);
//
//qwerqwreqwerqwrqwerqwrqwerqwrr
//

	//float player_pos_x = 0.f;
	//float player_pos_y = 0.f;
	//float speed = 50.f;	//units per second


	//internal void simulateGame(Input* input, float delta_time)
	//{
	//	//clearScreen(0xff5500);
	//	if (is_down(BUTTON_UP)) player_pos_y += speed * delta_time;
	//	if (is_down(BUTTON_DOWN)) player_pos_y -= speed * delta_time;
	//	if (is_down(BUTTON_RIGHT)) player_pos_x += speed * delta_time;
	//	if (is_down(BUTTON_LEFT)) player_pos_x -= speed * delta_time;

	//	drawRect(0, 0, 90, 45, 0xfffff12);
	//	drawRect(player_pos_x - 80, player_pos_y, 2, 12, 0xff0000);
	//	drawRect(player_pos_x + 80, player_pos_y, 2, 12, 0xff0000);
	//}
	
