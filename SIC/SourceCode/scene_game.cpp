#include "all.h"

int game_state;
int game_timer;

int panelstate;



int slime_mapX;
int slime_mapY;



Sprite* Stage;
Sprite* Mapchip;
Sprite* p_slime;
Sprite* panel;


//int textread()		//����������f�[�^�������Ă���֐�
//{
//
//}

struct Panel {
	bool onoff;
	int Count;
	int panelstate;
};


struct Charactor {
	VECTOR2 pos;		//x,y
	VECTOR4 Direction;	//up,down,left,right
};
Charactor slime;


void game_init()
{
	game_state = 0;
	game_timer = 0;

	

	slime.pos.x = 0;
	slime.pos.y = 0;
	
}

void game_deinit()
{
	safe_delete(Stage);
	safe_delete(Mapchip);
	safe_delete(p_slime);
	safe_delete(panel);
}

void game_update()
{
	switch (game_state)
	{
	case 0:
		///////////�����ݒ�///////////
		Mapchip = sprite_load(L"./Data/Images/�p�l���f��.png");
		p_slime = sprite_load(L"./Data/Images/slime_idle.png");
		game_state++;
		/*fallthrough*/

	case 1:
		///////////�p�����[�^�̐ݒ�///////////
		game_state++;
		/*fallthrough*/

	case 2:
		///////////�ʏ펞///////////

		//�����
		if (GetAsyncKeyState('W') & 1) 
		{
			slime.pos.y = slime.pos.y - 60;

			if (slime.pos.y < 0)
			{
				slime.pos.y = 0;
			}
		}

		//������
		if (GetAsyncKeyState('A') & 1)
		{
			slime.pos.x = slime.pos.x - 60;

			if (slime.pos.x < 0)
			{
				slime.pos.x = 0;
			}
		}
		
		//������
		if (GetAsyncKeyState('S') & 1)
		{
			slime.pos.y = slime.pos.y + 60;

			if (slime.pos.y >= 540)
			{
				slime.pos.y = 540;
			}
		}

		//�E����
		if (GetAsyncKeyState('D') & 1)
		{
			slime.pos.x = slime.pos.x + 60;

			if (slime.pos.x >= 540)
			{
				slime.pos.x = 540;
			}
		}
	
		break;
	}

	game_timer++;
}

void game_render()
{
	GameLib::clear(1, 1, 1);

	slime_mapX = slime.pos.x / 60;
	slime_mapY = slime.pos.y / 60;

	//�}�b�v�`�b�v�z��
	Panel panels[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			panels[i][j].
		}
	}

	

	sprite_render(
		p_slime,
		slime.pos.x, slime.pos.y,
		1, 1,
		0, 0,
		60, 60,
		0, 0
	);
}