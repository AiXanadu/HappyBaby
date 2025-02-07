#ifndef			_HB_CORE_GAME_H_
#define			_HB_CORE_GAME_H_

#include <source/Core/HBCoreHeader.h>


// 核心 - 游戏接口
class HBCoreGame
{
public:
	// constructor
	HBCoreGame() noexcept;

	// destructor
	virtual ~HBCoreGame() noexcept;

public:
	// [get] 游戏名称
	virtual QString abstractGameName() const noexcept = 0;

	// [get] 游戏图标
	virtual QIcon abstractGameIcon() const noexcept = 0;

	// [get] 游戏 - 背景
	virtual QImage abstractGameImage() const noexcept = 0;
};

#endif
