#include <source/Core/HBCoreHeader.h>
#include <source/Main/HBMainWidget.h>


// main - DPI设置
static void HB_Main_DPI_Setting() noexcept
{
	SetProcessDPIAware();

	auto		vDesktopDC = ::GetDC(nullptr);
	auto		vDPI_W = ::GetDeviceCaps(vDesktopDC, LOGPIXELSX);
	::ReleaseDC(nullptr, vDesktopDC);

	auto		vScanRatio = (double)vDPI_W / 96.0f;
	if(vScanRatio <= 0.4f)
	{
		qputenv("QT_SCALE_FACTOR", "0.25");
	}
	else if(vScanRatio <= 0.6f)
	{
		qputenv("QT_SCALE_FACTOR", "0.5");
	}
	else if(vScanRatio <= 0.9f)
	{
		qputenv("QT_SCALE_FACTOR", "0.75");
	}
	else if(vScanRatio <= 1.1f)
	{
		qputenv("QT_SCALE_FACTOR", "1.0");
	}
	else if(vScanRatio <= 1.4f)
	{
		qputenv("QT_SCALE_FACTOR", "1.25");
	}
	else if(vScanRatio <= 1.6f)
	{
		qputenv("QT_SCALE_FACTOR", "1.5");
	}
	else if(vScanRatio <= 1.9f)
	{
		qputenv("QT_SCALE_FACTOR", "1.75");
	}
	else if(vScanRatio <= 2.1f)
	{
		qputenv("QT_SCALE_FACTOR", "2.0");
	}
	else if(vScanRatio <= 2.4f)
	{
		qputenv("QT_SCALE_FACTOR", "2.25");
	}
	else if(vScanRatio <= 2.6f)
	{
		qputenv("QT_SCALE_FACTOR", "2.5");
	}
	else
	{
		qputenv("QT_SCALE_FACTOR", "3.0");
	}
}

// main - 元数据注册
static void HB_Main_Register_Meta_Type() noexcept
{
	qRegisterMetaType<std::int8_t>("std::int8_t");
	qRegisterMetaType<std::uint8_t>("std::uint8_t");
	qRegisterMetaType<std::int16_t>("std::int16_t");
	qRegisterMetaType<std::uint16_t>("std::uint16_t");
	qRegisterMetaType<std::int32_t>("std::int32_t");
	qRegisterMetaType<std::uint32_t>("std::uint32_t");
	qRegisterMetaType<std::int64_t>("std::int64_t");
	qRegisterMetaType<std::uint64_t>("std::uint64_t");
}

// main - 运行主界面
static void HB_Main_Run() noexcept
{
	auto		vWindow = new(std::nothrow) HBMainWidget(nullptr);
	vWindow->show();
}

// main - 入口函数
int main(int _Argc, char** _Argv)
{
	WSADATA		vWsaData;
	WSAStartup(MAKEWORD(2, 2), &vWsaData);
	OleInitialize(nullptr);
	HB_Main_DPI_Setting();

	// OpenGL渲染级别		(不启用时可能：在某些旧显卡机器上启动程序时，浏览器页面显示花屏)
	QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL, true);
	// 高质量图片
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
	// 创建本机窗口
	QCoreApplication::setAttribute(Qt::AA_NativeWindows, true);

	QApplication		vApplication(_Argc, _Argv);

	// QT的初始化工作
	qsrand((unsigned int)std::time(nullptr));

	// 启动主界面
	HB_Main_Register_Meta_Type();
	HB_Main_Run();
	QApplication::exec();

	OleUninitialize();
	WSACleanup();
	return 0;
}
