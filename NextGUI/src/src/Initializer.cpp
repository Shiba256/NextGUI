#include"Initializer.h"

#include"Constants.h"
#include"MouseEventManager.h"

#include"Siv3D/Addon.hpp"

namespace nGUI {
	void Initializer() {
		Addon::Register<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR);
	}
}
