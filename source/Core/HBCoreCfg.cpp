#include <source/Core/HBCoreCfg.h>
#include <QSettings>



// 公共处理 - 配置
struct PDCoreCfg
{
	QSettings*					handle = nullptr;
};



// Core - Cfg - 加载
static bool HB_Core_Cfg_Load(PDCoreCfg* d_ptr) noexcept
{
	Q_UNUSED(d_ptr);
	return true;
}

// Core - Cfg - 存储
static bool HB_Core_Cfg_Save(PDCoreCfg* d_ptr) noexcept
{
	Q_UNUSED(d_ptr);
	return true;
}



// constructor
HBCoreCfg::HBCoreCfg() noexcept
{
	d_ptr = new(std::nothrow) PDCoreCfg();
	d_ptr->handle = new(std::nothrow) QSettings(QCoreApplication::applicationDirPath() + "/cfg.ini", QSettings::IniFormat);
	HB_Core_Cfg_Load(d_ptr);
}

// destructor
HBCoreCfg::~HBCoreCfg() noexcept
{
	HB_Core_Cfg_Save(d_ptr);
	delete d_ptr->handle;
	delete d_ptr;
}



// [get] 实例
HBCoreCfg* HBCoreCfg::example() noexcept
{
	static auto	static_object_example = new(std::nothrow) HBCoreCfg();
	return static_object_example;
}



// [set] 值
void HBCoreCfg::set(const QString& _Domain, const QString& _Key, const QVariant& _Value) noexcept
{
	if(nullptr == _Domain || nullptr == _Key)
	{
		return;
	}
	d_ptr->handle->setValue(_Domain + "/" + _Key, _Value);
}

// [get] 值
QVariant HBCoreCfg::get(const QString& _Domain, const QString& _Key, const QVariant& _Default) const noexcept
{
	if(nullptr == _Domain || nullptr == _Key)
	{
		return _Default;
	}
	return d_ptr->handle->value(_Domain + "/" + _Key, _Default);
}
