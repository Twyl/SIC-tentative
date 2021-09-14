#include "all.h"
#include "Stage_data.h"

int game_state;
int game_timer;

int panelstate;

int panel_mapX;
int panel_mapY;

int slime_mapX;
int slime_mapY;

int old_slimeX;
int old_slimeY;

int old_panelX;
int old_panelY;

int clearCount;

bool gameover_flag = false;
bool gameclear_flag = false;


Sprite* Frame;
Sprite* Mapchip;
Sprite* p_slime;
Sprite* panel;
Sprite* Redpanel;

void Change_panel() {

	if (Mapchip_list[old_slimeY][old_slimeX] == 1)
	{
		Mapchip_list[old_slimeY][old_slimeX] = 0;
	}



	if (Mapchip_list[old_slimeY][old_slimeX] == 2)
	{
		Mapchip_list[old_slimeY][old_slimeX] = 1;
	}


	if (Mapchip_list[old_slimeY][old_slimeX] == 3)
	{
		Mapchip_list[old_slimeY][old_slimeX] = 2;
	}

}


struct Charactor {
	VECTOR2 pos;		//x,y
	VECTOR4 Direction;	//up,down,left,right
};
Charactor slime;


void game_init()
{
	game_state = 0;
	game_timer = 0;

	panel_mapX = 340;
	panel_mapY = 60;
	



	old_slimeX = 0;
	old_slimeY = 0;

	old_panelX = 0;
	old_panelY = 0;

	clearCount = 0;
	
}

void game_deinit()
{
	safe_delete(Frame);
	safe_delete(Mapchip);
	safe_delete(p_slime);
	safe_delete(panel);
	safe_delete(Redpanel);
}

void game_update()
{
	switch (game_state)
	{
	case 0:
		///////////初期設定///////////
		Frame = sprite_load(L"./Data/Images/Frame.png");
		Mapchip = sprite_load(L"./Data/Images/パネル素材.png");
		p_slime = sprite_load(L"./Data/Images/slime_idle.png");
		Redpanel = sprite_load(L"./Data/Images/RED.png");
		game_state++;
		/*fallthrough*/

	case 1:
		///////////パラメータの設定///////////
		game_state++;
		/*fallthrough*/
	case 2:
		///////////スポーン場所選択///////////
		if (GetAsyncKeyState('W') & 1)
		{
			panel_mapY = panel_mapY - 60;

			if (panel_mapY < 60)
			{
				panel_mapY = 60;
			}
		}

		if (GetAsyncKeyState('A') & 1)
		{
			panel_mapX = panel_mapX - 60;

			if (panel_mapX < 340)
			{
				panel_mapX = 340;
			}
		}

		if (GetAsyncKeyState('S') & 1)
		{
			panel_mapY = panel_mapY + 60;

			if (panel_mapY >= 600)
			{
				panel_mapY = 600;
			}
		}

		if (GetAsyncKeyState('D') & 1)
		{
			panel_mapX = panel_mapX + 60;

			if (panel_mapX >= 880)
			{
				panel_mapX = 880;
			}
		}

		if (TRG(0) & PAD_START)
		{

		

			game_state++;
		}
		slime.pos.x = panel_mapX;
		slime.pos.y = panel_mapY;

		break;

	case 3:
		///////////通常時///////////

		
		//上方向
		if (GetAsyncKeyState('W') & 1&&gameover_flag==false) 
		{
			old_slimeX = slime_mapX;
			old_slimeY = slime_mapY;

			slime.pos.y = slime.pos.y - 60;

			if (slime.pos.y < 60)
			{
				slime.pos.y = 60;
			}

			Change_panel();
			
		}

		//左方向
		if (GetAsyncKeyState('A') & 1 && gameover_flag == false)
		{
			old_slimeX = slime_mapX;
			old_slimeY = slime_mapY;

			slime.pos.x = slime.pos.x - 60;

			if (slime.pos.x < 340)
			{
				slime.pos.x = 340;
			}

			Change_panel();

		}
		
		//下方向
		if (GetAsyncKeyState('S') & 1 && gameover_flag == false)
		{
			old_slimeX = slime_mapX;
			old_slimeY = slime_mapY;

			slime.pos.y = slime.pos.y + 60;

			if (slime.pos.y >= 600)
			{
				slime.pos.y = 600;
			}

			Change_panel();

		}

		//右方向
		if (GetAsyncKeyState('D') & 1 && gameover_flag == false)
		{
			old_slimeX = slime_mapX;
			old_slimeY = slime_mapY;

			slime.pos.x = slime.pos.x + 60;

			if (slime.pos.x >= 880)
			{
				slime.pos.x = 880;
			}

			Change_panel();

		}
		slime_mapX = (slime.pos.x - 340) / 60;
		slime_mapY = (slime.pos.y - 60) / 60;
	
		if (Mapchip_list[slime_mapY][slime_mapX] == 0)
		{
			clearCount = 0;

			for (int i = 0; i < MAPSIZE_H ; i++)
			{
				for (int j = 0; j < MAPSIZE_W; j++)
				{
					if (Mapchip_list[i][j] ==0)
					{
						clearCount += 1;
					}

					if (clearCount == 100)
					{
						gameclear_flag = true;
					}
					
					else
					{ 
						gameover_flag = true; 
					}
				}
			}

		}



		break;
	}

	game_timer++;
}

void game_render()
{
	GameLib::clear(0, 0, 0);




	//マップチップ描画
	for (int y = 0; y < MAPSIZE_H; y++)
	{
		for (int x = 0; x < MAPSIZE_W; x++)
		{
			int chip_id = Mapchip_list[y][x];


			float chip_pos_x = (float)(chip_id % MAPSIZE_W) * MAPCHIP_W - 60;	//テクスチャ座標
			float chip_pos_y = (float)(chip_id / MAPSIZE_H) * MAPCHIP_H;

			int draw_x = MAPCHIP_W * x + 340;		//マップチップの描画x座標
			int draw_y = MAPCHIP_H * y + 60;		//マップチップの描画y座標

			sprite_render(
				Mapchip,
				draw_x, draw_y,
				1, 1,
				chip_pos_x, chip_pos_y,
				MAPCHIP_W, MAPCHIP_H,
				0, 0
			);



		}
	}

	
	switch (game_state)
	{
		case 2:
			sprite_render
			(
				Redpanel,
				panel_mapX, panel_mapY,
				1, 1,
				0, 0,
				60, 60,
				0, 0,
				0,
				1, 0, 0, 0.6
			);

			break;

		case 3:
			sprite_render
			(
				p_slime,
				slime.pos.x, slime.pos.y,
				1, 1,
				0, 0,
				60, 60,
				0, 0
			);		
	}
	sprite_render
	(
		Frame,
		290, 25,
		1.15, 1.15
	);



	if (gameover_flag && !gameclear_flag)
	{
		text_out(
			1,
			"GAMEOVER",
			360, 340,
			2, 2
		);
	}

	if (gameclear_flag)
	{
		text_out(
			1,
			"GAMECLEAR",
			360, 340,
			2, 2
		);
	}

	text_out(
		1,
		"DEMO",
		1000, 100,
		1, 1
	);

	text_out(
		1,
		"MOVE : WASD",
		1000, 200,
		0.7, 0.7
	);

	text_out(
		1,
		"DECIDE : ENTER",
		970, 300,
		0.7, 0.7
	);

}