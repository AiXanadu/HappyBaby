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
class HBMainWidget : public QWidget
{
Q_OBJECT

public:
	// constructor
	explicit HBMainWidget(QWidget* _Parent = nullptr) noexcept;

	// destructor
	~HBMainWidget() noexcept override;

private:
	// UI
	Ui::HBMainWidget*			ui;

protected:
	// [event] 关闭
	void closeEvent(QCloseEvent* _Event) noexcept;

public:
	// [opt] 设置加载
	virtual void coreCfgLoad() noexcept final;

	// [opt] 设置保存
	virtual void coreCfgSave() noexcept final;
};

#endif
