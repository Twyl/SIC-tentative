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
		///////////初期設定///////////
		
		stage_state++;
		/*fallthrough*/


	case 1:
		///////////パラメータの設定///////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		stage_state++;
		/*fallthrough*/


	case 2:
		///////////通常時///////////

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