#ifndef COMMON_H
#define COMMON_H


#define SCENE_NONE			-1
#define SCENE_TITLE			0
#define SCENE_STAGE			1
#define SCENE_GAME			2	
#define SCENE_RELOAD		3



#define SCREEN_W	1280
#define SCREEN_H	720


#define ToRadian( x )   DirectX::XMConvertToRadians( x )    // �p�x�����W�A����
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )    // ���W�A�����p�x��

extern int curScene;
extern int nextScene;

extern int worldNum;
extern int stageNum;

#endif
