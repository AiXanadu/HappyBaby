#include <source/Main/HBMainWidget.h>
#include "ui_HBMainWidget.h"
#include <source/Core/HBCoreCfg.h>
#include <source/Core/HBCoreGame.h>



// 主界面
struct PDMainWidget
{
	// 游戏列表
	std::map<QWidget*, HBCoreGame*>			gameArray;
};



// constructor
HBMainWidget::HBMainWidget(QWidget *_Parent) noexcept : QWidget(_Parent), ui(new Ui::HBMainWidget)
{
	d_ptr = new(std::nothrow) PDMainWidget();
	ui->setupUi(this);
	setWindowTitle(tr(u8"HappyBaby"));
	setWindowIcon(QIcon(":/LOGO.ico"));
	gameLoad();
	coreCfgLoad();
}

// destructor
HBMainWidget::~HBMainWidget() noexcept
{
	delete ui;
	delete d_ptr;
}



// [event] 关闭
void HBMainWidget::closeEvent(QCloseEvent* _Event) noexcept
{
	coreCfgSave();
	QWidget::closeEvent(_Event);
}



// [opt] 设置加载
void HBMainWidget::coreCfgLoad() noexcept
{
	auto		vAreaX = HBCoreCfg::example()->get("Main", "AreaX", 0).toInt();
	auto		vAreaY = HBCoreCfg::example()->get("Main", "AreaY", 0).toInt();
	auto		vAreaW = HBCoreCfg::example()->get("Main", "AreaW", 0).toInt();
	auto		vAreaH = HBCoreCfg::example()->get("Main", "AreaH", 0).toInt();
	if(0 == vAreaX || 0 == vAreaY || 0 == vAreaW || 0 == vAreaH)
	{
		return;
	}
	resize(vAreaW, vAreaH);
	move(vAreaX, vAreaY);
}

// [opt] 设置保存
void HBMainWidget::coreCfgSave() noexcept
{
	auto		vAreaX = this->x();
	auto		vAreaY = this->y();
	auto		vAreaW = this->width();
	auto		vAreaH = this->height();
	HBCoreCfg::example()->set("Main", "AreaX", vAreaX);
	HBCoreCfg::example()->set("Main", "AreaY", vAreaY);
	HBCoreCfg::example()->set("Main", "AreaW", vAreaW);
	HBCoreCfg::example()->set("Main", "AreaH", vAreaH);
}



// [opt] 加载所有游戏
void HBMainWidget::gameLoad() noexcept
{
}
