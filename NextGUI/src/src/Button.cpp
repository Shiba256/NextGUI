#include"Button.h"

#include"DrawText.h"
#include"nFont.h"
#include"MouseEventManager.h"

namespace nGUI {
	void Button::update()  {
		is_pressed = MouseEventManager::leftPressed(box.round_rect);
		is_release = MouseEventManager::leftReleased(box.round_rect);
		is_over = MouseEventManager::mouseOver(box.round_rect);

		if (not style.enable) {
			this->updateBox(style.rrs_unable);
		}
		else if (is_pressed) {
			this->updateBox(style.rrs_pressed);
			MouseEventManager::clearAll();
		}
		else if (is_over) {
			this->updateBox(style.rrs_mouseover);
			MouseEventManager::clearAll();
		}
		else {
			this->updateBox(style.rrs);
		}

		if (is_over && style.enable) {
			Cursor::RequestStyle(CursorStyle::Hand);
		}

	}

	void Button::draw() const {
		if (not style.enable) {
			this->drawBox(style.rrs_unable);
		}
		else if (is_pressed) {
			this->drawBox(style.rrs_pressed);
		}
		else if (is_over) {
			this->drawBox(style.rrs_mouseover);
		}
		else {
			this->drawBox(style.rrs);
		}
		drawText(style.text.font_size, box.round_rect, style.text.text, nFont::instance().get(), style.text.color, style.text.position);
	}
}
