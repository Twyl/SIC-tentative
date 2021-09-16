#ifndef STAGE_DATA_H
#define STAGE_DATA_H

#define STAGE_W		600
#define STAGE_H		600
#define MAPCHIP_W	60
#define MAPCHIP_H	60
#define MAPSIZE_W	(STAGE_W/MAPCHIP_W)
#define MAPSIZE_H	(STAGE_H/MAPCHIP_H)

//ÉpÉlÉãÇÃèÛë‘
#define Normal	1
#define Frozen	2
char Mapchip_list[MAPSIZE_H][MAPSIZE_W];




#endif

