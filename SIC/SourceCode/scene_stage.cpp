#include "all.h"

int stage_state;
int stage_timer;

int Stagenum;

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


			nextScene = SCENE_GAME;
			break;
		}

		break;
	}
	stage_timer++;
}
void stage_render()
{
	GameLib::clear(1, 0, 0);
}