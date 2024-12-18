#include"Button.h"

#include"DrawText.h"
#include"Font.h"

namespace nGUI {
	void Button::update()  {
		is_pressed = box.round_rect.leftPressed();
		is_release = box.round_rect.leftReleased();
		is_over = box.round_rect.mouseOver();

		if (not style.enable) {
			this->updateBox(style.rrs_unable);
		}
		else if (is_pressed) {
			this->updateBox(style.rrs_pressed);
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
		else {
			this->drawBox(style.rrs);
		}
		drawText(box.round_rect, style.text.text, nFont::instance().getRegular(), nFont::instance().getIcon(), style.text.color, style.position_type, true);
	}
}
