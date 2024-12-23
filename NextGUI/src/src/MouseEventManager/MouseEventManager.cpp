#include"MouseEventManager.h"

#include"MouseEventManagerImpl.h"

#include"Constants.h"

namespace nGUI {
	bool MouseEventManager::leftClicked() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->leftClicked();
		}
		return false;
	}

	bool MouseEventManager::rightClicked() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->rightClicked();
		}
		return false;
	}

	bool MouseEventManager::leftPressed() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->leftPressed();
		}
		return false;
	}

	bool MouseEventManager::rightPressed() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->rightPressed();
		}
		return false;
	}

	bool MouseEventManager::leftReleased() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->leftReleased();
		}
		return false;
	}

	bool MouseEventManager::rightReleased() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return ptr->p_impl->rightReleased();
		}
		return false;
	}

	void MouseEventManager::clearDown() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			ptr->p_impl->clearDown();
		}
	}

void MouseEventManager::clearPressed() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			ptr->p_impl->clearPressed();
		}
	}

	void MouseEventManager::clearUp() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			ptr->p_impl->clearUp();
		}
	}

	void MouseEventManager::clearMouseOver() {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			ptr->p_impl->clearMouseOver();
		}
	}

	bool MouseEventManager::_mouseOver(bool is_over) {
		if (auto* ptr = Addon::GetAddon<MouseEventManager>(Constants::MOUSE_EVENT_MANAGER_STR)) {
			return (not ptr->p_impl->isClearMouseOver()) && is_over;
		}
		return false;
	}

	bool MouseEventManager::init() {
		p_impl = std::make_shared<MouseEventManagerImpl>();
		return static_cast<bool>(p_impl);
	}

	bool MouseEventManager::update() {
		return p_impl->update();
	}
}
