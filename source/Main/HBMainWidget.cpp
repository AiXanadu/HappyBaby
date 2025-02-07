#include <source/Main/HBMainWidget.h>
#include "ui_HBMainWidget.h"


// constructor
HBMainWidget::HBMainWidget(QWidget *_Parent) noexcept : QWidget(_Parent), ui(new Ui::HBMainWidget)
{
	ui->setupUi(this);
	setWindowTitle(tr(u8"HappyBaby"));
	setWindowIcon(QIcon(":/LOGO.ico"));
}

// destructor
HBMainWidget::~HBMainWidget() noexcept
{
	delete ui;
}
