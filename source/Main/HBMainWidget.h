#ifndef			_HB_MAIN_WIDGET_H_
#define			_HB_MAIN_WIDGET_H_

#include <source/Core/HBCoreHeader.h>


QT_BEGIN_NAMESPACE
namespace Ui
{
	class HBMainWidget;
}
QT_END_NAMESPACE

// 主界面
struct PDMainWidget;
typedef struct PDMainWidget			PDMainWidget;
class HBMainWidget : public QWidget
{
Q_OBJECT

private:
	// 私有数据
	PDMainWidget*				d_ptr;

	// UI
	Ui::HBMainWidget*			ui;

public:
	// constructor
	explicit HBMainWidget(QWidget* _Parent = nullptr) noexcept;

	// destructor
	~HBMainWidget() noexcept override;

protected:
	// [event] 关闭
	void closeEvent(QCloseEvent* _Event) noexcept override;

public:
	// [opt] 设置加载
	virtual void coreCfgLoad() noexcept final;

	// [opt] 设置保存
	virtual void coreCfgSave() noexcept final;

public:
	// [opt] 加载所有游戏
	virtual void gameLoad() noexcept final;
};

#endif
