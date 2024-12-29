#include"CheckBox.h"
#include"nFont.h"
#include"DrawText.h"
#include"MouseEventManager.h"


namespace nGUI {
		void CheckBox::update(){
			is_over = MouseEventManager::mouseOver(box.round_rect);
			if (not style.enable) {
				box.round_rect.r = style.rrs_unable.r;
				box.round_rect.r = style.checkbox_unable.r;
			}
			else if (is_over) {
				box.round_rect.r = style.rrs_mouseover.r;
				box.round_rect.r = style.checkbox_mouseover.r;
			}
			else if (style.is_check) {
				box.round_rect.r = style.rrs_clicked.r;
				box.round_rect.r = style.checkbox_clicked.r;
			}
			else {
				box.round_rect.r = style.rrs.r;
				box.round_rect.r = style.checkbox.r;
			}
			if (MouseEventManager::leftReleased(box.round_rect) && style.enable) {
				style.is_check = !(style.is_check);
				MouseEventManager::clearAll();
			}
			else if (is_over) {
				Cursor::RequestStyle(CursorStyle::Hand);
				MouseEventManager::clearMouseOver();
			}

		}

		void CheckBox::draw() const{
			if (not style.enable) {
				this->drawBox(style.rrs_unable);
				this->drawCheckBox(style.checkbox_unable);
			}
			else if (is_over) {
				this->drawBox(style.rrs_mouseover);
				this->drawCheckBox(style.checkbox_mouseover);
			}
			else if (style.is_check) {
				this->drawBox(style.rrs_clicked);
				this->drawCheckBox(style.checkbox_clicked);
			}
			else {
				this->drawBox(style.rrs);
				this->drawCheckBox(style.checkbox);
			}
			drawText(style.text.font_size, box.round_rect.stretched(0, 0, 0, -checkbox.round_rect.w - style.checkbox_margin.x), style.text.text, nFont::instance().get(), style.text.color, style.text.position);
		}
	void CheckBox::ReConstruct() {
			box = GradationRoundRect{ RoundRect{style.getCalculatedPosition(),style.size,style.r} };
			checkbox = GradationRoundRect{ RoundRect{Arg::center = box.round_rect.leftCenter().movedBy(style.checkbox_margin).movedBy(style.checkbox_size.x / 2,0),style.checkbox_size,style.checkbox_r} };
		}
		void CheckBox::drawBox(const RoundRectStyle& rrs) const {
			box.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(box);
			box.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
		}

		void CheckBox::drawCheckBox(const RoundRectStyle& rrs) const {
			checkbox.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(checkbox);
			checkbox.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
			if (style.is_check)nFont::instance().get()(U"✔").drawAt(checkbox.round_rect.w * 0.9, checkbox.round_rect.center(), style.check_color);
		}
	
}
