#include "all.h"

int game_state;
int game_timer;




//int textread()		//����������f�[�^�������Ă���֐�
//{
//
//}



void game_init()
{
	game_state = 0;
	game_timer = 0;
}

void game_deinit()
{

}

void game_update()
{
	switch (game_state)
	{
	case 0:
		///////////�����ݒ�///////////
		game_state++;
		/*fallthrough*/

	case 1:
		///////////�p�����[�^�̐ݒ�///////////
		game_state++;
		/*fallthrough*/

	case 2:
		///////////�ʏ펞///////////

	//�X�e�[�W�ǂݍ���		
	
		break;
	}

	game_timer++;
}

void game_render()
{
	GameLib::clear(1, 1, 1);
}