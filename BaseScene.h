#pragma once
#include "MyDx.h"

class BaseScene {
public:
	BaseScene();
	virtual int Update();
	virtual void Draw();
};