#pragma once
#ifndef _NEXT_GUI_MOUSEEVENTMANAGERIMPL_H_
#define _NEXT_GUI_MOUSEEVENTMANAGERIMPL_H_

#include"stdafx.h"

namespace nGUI {
	class MouseEventManager::MouseEventManagerImpl {
	public:
		constexpr bool rightClicked() const {
			return right.click;
		}

		constexpr bool leftClicked() const {
			return left.click;
		}

		constexpr bool rightPressed() const {
			return right.pressed;
		}

		constexpr bool leftPressed() const {
			return left.pressed;
		}

		constexpr bool rightReleased() const {
			return right.release;
		}

		constexpr bool leftReleased() const {
			return left.release;
		}

		constexpr void clearDown() {
			right.click = false;
			left.click = false;
		}

		constexpr void clearPressed() {
			right.pressed = false;
			left.pressed = false;
		}

		constexpr void clearUp() {
			right.release = false;
			left.release = false;
		}

		constexpr void clearMouseOver() {
			is_clear_mouse_over = true;
		}

		constexpr bool isClearMouseOver() const noexcept {
			return is_clear_mouse_over;
		}

		bool update() {
			is_clear_mouse_over = false;
			right.update(MouseR);
			left.update(MouseL);
			return true;
		}

	private:
		struct MouseEvent {
			bool click = false;
			bool pressed = false;
			bool release = false;
			void init() {
				click = pressed = release = false;
			}
			void update(const Input& input) {
				click = input.down();
				pressed = input.pressed();
				release = input.up();
			}
		};
		bool is_clear_mouse_over = false;
		MouseEvent right;
		MouseEvent left;
	};
}

#endif
