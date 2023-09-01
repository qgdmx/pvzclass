#pragma once
#include "BaseEvent.h"

// 僵尸被减速事件
// 参数：触发事件的僵尸
// 无返回值
class ZombieDecelerateEvent : public BaseEvent<std::function<
	void(std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ZombieDecelerateEvent();
	bool handle(EventHandler handler);
};

ZombieDecelerateEvent::ZombieDecelerateEvent()
{
	address = 0x530950;
}

bool ZombieDecelerateEvent::handle(EventHandler handler)
{
	if (handler.context.Eip != address) return false;
	auto zombie = std::make_shared<PVZ::Zombie>(handler.context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](zombie);
	}
	afterHandle(handler);
	return true;
}