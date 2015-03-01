#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include "FingRRR.h"

/* VC++ Code */
#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

int cntC = 0;
void onBtnClick(iButton *th, int &x, int &y)
{
	printf("Hello World ! %d\n", ++cntC);
	return ;
}
void onBtnHover(iButton *th, int &x, int &y)
{
	th->bgImg = &assetsImg[ th->customData[1] ];
	return ;
}
void onBtnOut(iButton *th, int &x, int &y)
{
	th->bgImg = &assetsImg[ th->customData[0] ];
	return ;
}
void changeClrCursorFootprint(iButton *th, int &x, int &y)
{
	clrCursorFootprint = CV_RGB(255, 0, 255);
	return ;
}

iObject *test, *test2;

void aniEnd()
{
	puts("Animation Ended");
	sceneActive->deleteObject(test);
}

void clickMoveTest(iButton *th, int &x, int &y)
{
	clock_t st = clock();
	createAnimation(test->x, 3, 200, ANI_SPEEDFUNC_CONST, NULL, aniEnd);
	return ;
}
void onDrag(iObject *th, int &x, int &y)
{
	objActive = th;
}

int cnt2 = 0;
void event()
{
	while (1)
	{
		system("cls");
		printf("%d\n", ++cnt2);
		waitKey(200);
	}
}

int main()
{
	int key;
	
	inputMethod = INPUT_METHOD_MOUSE;
	init(1400, 700, false);

	iScene *main = new iScene(0, 0, 1400, 700, 0, 0, 0, 0, &assetsImg[6]);
	sceneActive = main;
	iToolbar *mainTB = main->createToolbar(0, 0, 486, 60);
	iButton *btn1 = mainTB->createButton(140, 56, 255, 0, 0, 0, &assetsImg[0], onBtnHover, onBtnClick, NULL, NULL, NULL, NULL, onBtnOut);
	iButton *btn2 = mainTB->createButton(140, 56, 0, 255, 0, 0, &assetsImg[2], onBtnHover, clickMoveTest, NULL, NULL, NULL, NULL, onBtnOut);
	iButton *btn3 = mainTB->createButton(140, 56, 0, 0, 255, 0, &assetsImg[4], onBtnHover, onBtnClick, NULL, NULL, NULL, NULL, onBtnOut);
	btn1->customData[0] = 0; btn1->customData[1] = 1;
	btn2->customData[0] = 2; btn2->customData[1] = 3;
	btn3->customData[0] = 4; btn3->customData[1] = 5; 
	// iButton *btn4 = mainTB->createButton(56, 56, 255, 0, 255, 255, NULL, NULL, changeClrCursorFootprint, NULL, NULL, NULL, NULL, NULL);

	test2 = sceneActive->createObject(50, 50, 475, 475, 0, 0, 0, 0, &assetsImg[7], 230, true, true);
	test2->onDrag = &onDrag;

	test = sceneActive->createObject(200, 200, 100, 100, 0, 0, 255, 100, NULL, 255, true, true);
	test->onDrag = &onDrag;

	hookUserEvent(event);

	start();

	return 0;
}