#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{
	Time = 0;
}

AbstractScene* GameEnd::Update()
{
	if (EndTime < ++Time)
	{
		return nullptr;
	}

	return this;
}

void GameEnd::Draw() const
{
	DrawString(0, 0, "I‚í‚è", 0xffffff);
}
