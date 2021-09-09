#include "all.h"

int stage_state;
int stage_timer;

void stage_init()
{
	stage_state = 0;
	stage_timer = 0;
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