#ifndef			_HB_CORE_CFG_H_
#define			_HB_CORE_CFG_H_

#include <source/Core/HBCoreHeader.h>


// 公共处理 - 配置
struct PDCoreCfg;
typedef struct PDCoreCfg			PDCoreCfg;
class HBCoreCfg
{
private:
	// 私有数据
	PDCoreCfg*				d_ptr;

private:
	Q_DISABLE_COPY(HBCoreCfg)

public:
	// constructor
	HBCoreCfg() noexcept;

	// destructor
	virtual ~HBCoreCfg() noexcept;

public:
	// [get] 实例
	static HBCoreCfg* example() noexcept;

public:
	// [set] 值
	virtual void set(const QString& _Domain, const QString& _Key, const QVariant& _Value) noexcept final;

	// [get] 值
	virtual QVariant get(const QString& _Domain, const QString& _Key, const QVariant& _Default = QVariant()) const noexcept final;
};

#endif
