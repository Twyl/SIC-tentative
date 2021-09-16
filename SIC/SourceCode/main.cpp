#include "all.h"

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{

	//�Q�[�����C�u�����̏����ݒ�
	GameLib::init(L"SIC���(��)", SCREEN_W, SCREEN_H);

	//�Q�[�����[�v
	while (GameLib::gameLoop())
	{
		
		if (curScene != nextScene)
		{
			//���݂̃V�[���ɉ������I������
			switch (curScene)
			{
			case SCENE_TITLE:
				title_deinit();
				break;

			case SCENE_STAGE:
				stage_deinit();

			case SCENE_GAME:
				game_deinit();
				break;

			case SCENE_RELOAD:
				reload_deinit();
			}

			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;


			case SCENE_STAGE:
				stage_init();
			
			case SCENE_GAME:
				game_init();
				break;

			case SCENE_RELOAD:
				reload_init();
			}
			
			curScene = nextScene;
		}

		input::update();
		//���݂̃V�[���ɉ������X�V�E�`�揈��
		switch (curScene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;

		case SCENE_STAGE:
			stage_update();
			stage_render();
			break;

		case SCENE_GAME:
			game_update();
			game_render();
			break;

		case SCENE_RELOAD:
			reload_update();
			reload_render();
			break;
		}
		

		debug::display(1, 1, 1, 1, 1);
		GameLib::present(1, 0);
	}

	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;

	case SCENE_STAGE:
		stage_deinit();
		break;

	case SCENE_GAME:
		game_deinit();
		break;

	case SCENE_RELOAD:
		reload_deinit();
		break;
	}


	GameLib::uninit();

}