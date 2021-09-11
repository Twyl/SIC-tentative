#ifndef COMMON_H
#define COMMON_H


#define SCENE_NONE	-1
#define SCENE_TITLE	0
#define SCENE_STAGE	1
#define SCENE_GAME	2	


#define SCREEN_W	1280
#define SCREEN_H	720

#define STAGE_W		540
#define STAGE_H		540
#define MAPCHIP_W	60
#define MAPCHIP_H	60
#define MAPSIZE_W	(STAGE_W/MAPCHIP_W)
#define MAPSIZE_H	(STAGE_H/MAPCHIP_H)


//マップチップ配列
int Mapchip_list[MAPSIZE_H][MAPSIZE_W]
{
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
};


extern int curScene;
extern int nextScene;

#endif
