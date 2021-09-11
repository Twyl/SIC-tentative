#include "all.h"

int game_state;
int game_timer;




//int textread()		//メモ帳からデータを持ってくる関数
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
		///////////初期設定///////////
		game_state++;
		/*fallthrough*/

	case 1:
		///////////パラメータの設定///////////
		game_state++;
		/*fallthrough*/

	case 2:
		///////////通常時///////////

	//ステージ読み込み		
	
		break;
	}

	game_timer++;
}

void game_render()
{
	GameLib::clear(1, 1, 1);
}