#include "all.h"

#define STAGE_W		600
#define STAGE_H		600
#define MAPCHIP_W	60
#define MAPCHIP_H	60
#define MAPSIZE_W	(STAGE_W/MAPCHIP_W)
#define MAPSIZE_H	(STAGE_H/MAPCHIP_H)

//ÉpÉlÉãÇÃèÛë‘
#define Normal	1
#define Frozen	2

int Mapchip_list[MAPSIZE_H][MAPSIZE_W]
{
	{0, 0, 1, 3, 2, 2, 1, 1, 0, 0,},
	{0, 0, 1, 3, 3, 1, 0, 0, 0, 0,},
	{0, 0, 1, 1, 2, 3, 2, 0, 0, 0,},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 0,},
	{0, 0, 0, 2, 2, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
};
