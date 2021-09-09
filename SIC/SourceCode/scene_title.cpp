#include "all.h"

int title_state;
int title_timer;

Sprite* slime;

void title_init()
{
	title_state = 0;
	title_timer = 0;
}


void title_deinit()
{
	safe_delete(slime);
}


void title_update()
{
	switch (title_state)
	{
	case 0:
		///////////‰Šúİ’è///////////
		slime = sprite_load(L"./Data/Images/slime_idle.png");
		title_state++;
		/*fallthrough*/

	
	case 1:
		///////////ƒpƒ‰ƒ[ƒ^‚Ìİ’è///////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		title_state++;
		/*fallthrough*/

	
	case 2:
		///////////’Êí///////////

		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_STAGE;
			break;
		}

		break;
	}
	title_timer++;
}


void title_render()
{
	GameLib::clear(0, 0, 0);


	sprite_render(slime, 200, 200);
}