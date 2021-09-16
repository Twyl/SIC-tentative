#include "all.h"

int title_state;
int title_timer;

Sprite* title;

void title_init()
{
	title_state = 0;
	title_timer = 0;
}


void title_deinit()
{
	safe_delete(title);
}


void title_update()
{
	switch (title_state)
	{
	case 0:
		///////////‰Šúİ’è///////////
		title = sprite_load(L"./Data/Images/Title.png");
		title_state++;
		/*fallthrough*/

	
	case 1:
		///////////ƒpƒ‰ƒ[ƒ^‚Ìİ’è///////////
		GameLib::setBlendMode(Blender::BS_ALPHA);
		worldNum = 1;
		stageNum = 1;
		title_state++;
		/*fallthrough*/

	
	case 2:
		///////////’Êí///////////

	


		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_STAGE;
			sound::play(0, 0);
			break;
		}

		break;
	}
	title_timer++;
}


void title_render()
{
	GameLib::clear(0, 0, 0);
	sprite_render(title, 0, 0);
	text_out(2, "Press Enter Key", SCREEN_W / 2, SCREEN_H / 4 * 3, 1, 1, 1, 1, 1, 1, TEXT_ALIGN::MIDDLE);
}