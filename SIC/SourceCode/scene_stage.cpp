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
		///////////‰Šúİ’è///////////
		
		stage_state++;
		/*fallthrough*/


	case 1:
		///////////ƒpƒ‰ƒ[ƒ^‚Ìİ’è///////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		BackGround = sprite_load(L"./Data/Images/Back.png");
		stage_state++;
		/*fallthrough*/


	case 2:
		///////////’Êí///////////
		if (GetAsyncKeyState('A') & 1)
		{
			Stagenum -= 1;
			if (Stagenum <= 0)
			{
				Stagenum = 1;
			}
		}
		if (GetAsyncKeyState('D') & 1)
		{
			Stagenum += 1;
			if (Stagenum >= 6)
			{
				Stagenum = 5;
			}
		}
		if (TRG(0) & PAD_START)
		{
			stageNum = Stagenum;

			nextScene = SCENE_GAME;
			break;
		}

		break;
	}
	stage_timer++;
}
void stage_render()
{
	GameLib::clear(0, 0, 0);

	debug::setString("%d",Stagenum);
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
	text_out(2, "\"Enter\" to Start", SCREEN_W / 2, SCREEN_H / 4 * 2.7f, 1.2f, 1.2f, 1, 1, 1, 1, TEXT_ALIGN::MIDDLE);
}