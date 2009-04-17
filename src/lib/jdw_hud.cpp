// SiC: Remove this file from lib
#include "jdw_hud.h"

HUD::HUD() {
	drawFPS = false;
	drawMessage = false;
/*
	font['0'] = zero;
	font['1'] = one;
	font['2'] = two;
	font['3'] = three;
	font['4'] = four;
	font['5'] = five;
	font['6'] = six;
	font['7'] = seven;
	font['8'] = eight;
	font['9'] = nine;
	font['.'] = dot;
*/
}

HUD::~HUD() {

}

void HUD::Update() {
	if (drawFPS) DrawFPS();

}

void HUD::DrawFPS() {

}

void HUD::DrawMessage() {

}
