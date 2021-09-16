#include "all.h"

void guide_init() {

}
void guide_deinit() {

}
void guide_update() {
	if (TRG(0) & PAD_START)
	{
		nextScene = SCENE_GAME;
		
	}
}
void guide_render() {



}
