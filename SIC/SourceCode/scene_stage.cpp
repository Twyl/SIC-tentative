#include "all.h"
#include <sstream>
#include <string>

int stage_state;
int stage_timer;

int Stagenum;

std::string stage_select_str;

Sprite* BackGround;

std::ostringstream ss;

void stage_init()
{
	stage_state = 0;
	stage_timer = 0;
	Stagenum = 1;
}
void stage_deinit()
{

}
void stage_update()
{
	switch (stage_state)
	{
	case 0:
		///////////初期設定///////////
		
		stage_state++;
		/*fallthrough*/


	case 1:
		///////////パラメータの設定///////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		BackGround = sprite_load(L"./Data/Images/Back.png");
		stage_state++;
		/*fallthrough*/


	case 2:
		///////////通常時///////////
		if (GetAsyncKeyState('A') & 1)
		{
			Stagenum -= 1;
				sound::play(0, 0);
			if (Stagenum <= 0)
			{
				Stagenum = 1;
			}
		}
		if (GetAsyncKeyState('D') & 1)
		{
			Stagenum += 1;
			sound::play(0, 0);
			if (Stagenum >= MAX_STAGE_NUM + 1)
			{
				Stagenum = MAX_STAGE_NUM;
			}
		}
		if (TRG(0) & PAD_START)
		{
			stageNum = Stagenum;

			nextScene = SCENE_GAME;
			sound::play(0, 0);
			break;
		}

		break;
	}
	stage_timer++;
}
void stage_render()
{
	GameLib::clear(0, 0, 0);

	sprite_render
	(
		BackGround,
		0, 0,
		1, 1
	);

	text_out(2, "Select Stage", SCREEN_W / 2, SCREEN_H / 4, 1, 1, 1, 1, 1, 1, TEXT_ALIGN::MIDDLE);
	ss.str("");
	ss << Stagenum;
	stage_select_str = "Stage" + ss.str();
	text_out(2, stage_select_str, SCREEN_W / 2, SCREEN_H / 4 * 2.2f, 1.7f, 1.7f, 1, 1, 1, 1, TEXT_ALIGN::MIDDLE);
	text_out(2, "'A'key +                  'D'key -", SCREEN_W / 2, SCREEN_H / 4 * 2.2f, 1, 1, 1, 1, 1, 0.5f, TEXT_ALIGN::MIDDLE);
	text_out(2, "\"Enter\" to Start", SCREEN_W / 2, SCREEN_H / 4 * 2.7f, 1.2f, 1.2f, 1, 1, 1, 1, TEXT_ALIGN::MIDDLE);
}