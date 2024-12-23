#include"Initializer.h"

#include"Constants.h"
#include"MouseEventManager.h"

#include"stdafx.h"

namespace nGUI {
	void Initializer() {
		Addon::Register<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR);
	}
}
