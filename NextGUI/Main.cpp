#include<Siv3D.hpp>

#include"nGUI.h"

#include "StyleBase.h"
#include "RoundRectStyle.h"
#include "Text.h"

#include "nFont.h"
#include "DrawText.h"
#include "MouseEventManager.h"

#include "stdafx.h"

namespace nGUI {
	struct ToggleButtonStyle {
		COMMON_STYLE;
		RoundRectStyle rrs{ Palette::White };
		RoundRectStyle rrs_off{ Palette::White };
		RoundRectStyle rrs_mouseover = rrs;

		RoundRectStyle knob_on{ Palette::White };
		RoundRectStyle knob_off{ Palette::White };
		RoundRectStyle knob_mouseover = knob_on;

		SizeF circle_size = { 10,10 };
		double circle_r = 10.0;
		bool is_check = false;
		Text text_on;
		Text text_off;
	};

	class ToggleButton : public AbstractComponent {
	public:
		ToggleButton(ToggleButtonStyle style = ToggleButtonStyle{}) :
			style(style),
			box(RoundRect{ style.getCalculatedPosition(),style.size,style.rrs.r }),
			knob(RoundRect{ Arg::center = box.round_rect.leftCenter(),style.circle_size,style.knob_on.r}),
			move_transition(0.1s, 0.1s, 1.0)
		{
			if (style.is_check) {
				box.round_rect.r = style.rrs.r;
				knob.round_rect.r = style.knob_on.r;
			}
			else {
				box.round_rect.r = style.rrs_off.r;
				knob.round_rect.r = style.knob_off.r;
			}
		}

		void update() {
			is_over = MouseEventManager::mouseOver(box.round_rect);
			move_transition.update(!style.is_check);
			if (is_over) {
				MouseEventManager::clearMouseOver();
				box.round_rect.r = style.rrs_mouseover.r;
				knob.round_rect.r = style.knob_mouseover.r;
			}
			if (MouseEventManager::leftReleased(box.round_rect)) {
				MouseEventManager::clearUp();
				style.is_check = !style.is_check;
				if (style.is_check) {
					box.round_rect.r = style.rrs.r;
					knob.round_rect.r = style.knob_on.r;
				}
				else {
					box.round_rect.r = style.rrs_off.r;
					knob.round_rect.r = style.knob_off.r;
				}
			}
			knob.round_rect.x = box.round_rect.x + (box.round_rect.w - knob.round_rect.w) * move_transition.easeInOut(Easing::Circ);
		}

		void draw() const {
			if (is_over) {
				drawBox(style.rrs_mouseover);
				drawKnob(style.knob_mouseover);
				if (style.is_check) {
					drawText(style.text_on.font_size, box.round_rect.stretched(0, 0, 0, -style.circle_size.x), style.text_on.text, nGUI::nFont::instance().get(), style.text_on.color, style.text_on.position);
				}
				else {
					drawText(style.text_off.font_size, box.round_rect.stretched(0, -style.circle_size.x, 0, 0), style.text_off.text, nGUI::nFont::instance().get(), style.text_off.color, style.text_off.position);
				}
			}
			else if (style.is_check) {
				drawBox(style.rrs);
				drawKnob(style.knob_on);
				drawText(style.text_on.font_size, box.round_rect.stretched(0, 0, 0, -style.circle_size.x), style.text_on.text, nGUI::nFont::instance().get(), style.text_on.color, style.text_on.position);
			}
			else {
				drawBox(style.rrs_off);
				drawKnob(style.knob_off);
				drawText(style.text_off.font_size, box.round_rect.stretched(0, -style.circle_size.x, 0, 0), style.text_off.text, nGUI::nFont::instance().get(), style.text_off.color, style.text_off.position);
			}
		}

		ToggleButtonStyle& changeStyle() {
			return style;
		}

		constexpr bool isOn() const noexcept {
			return style.is_check;
		}

		constexpr Vec2 getPos() const override {
			return style.pos;
		}
		constexpr Vec2 getLT() const override {
			return style.getCalculatedPosition();
		}
		constexpr SizeF getSize() const override {
			return style.size;
		}
		constexpr int32 getZIndex() const override {
			return style.z_index;
		}
		void setPos(const Vec2& pos, PositionType position_type = PositionType::topLeft) override {
			style.pos = pos;
			style.position_type = position_type;
		}
		void setSize(const SizeF& _size) override {
			style.size = _size;
		}
		void ReConstruct() override {
			box = GradationRoundRect{ RoundRect{style.getCalculatedPosition(),style.size,style.rrs.r} };
		}

	private:
		void drawBox(const RoundRectStyle& rrs) const {
			box.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(box);
			box.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
		}

		void drawKnob(const RoundRectStyle& rrs) const {
			knob.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(knob);
			knob.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
		}

		ToggleButtonStyle style;
		GradationRoundRect box;
		GradationRoundRect knob;
		Transition move_transition;
		bool is_over = false;
	};
}

void Main() {
	Window::Resize(1920, 1080);
	Scene::SetBackground(Palette::Aliceblue);

	nGUI::Initializer();

	nGUI::ToggleButton toggle{
		nGUI::ToggleButtonStyle{
			.pos = Scene::CenterF(),
			.size{200,50},
			.position_type = nGUI::PositionType::center,
			.rrs{
				.r = 20,
			},
			.rrs_off{
				.background_color = ColorF{0.95},
				.r = 20,
			},
			.knob_on{
				.background_color = Palette::Lightgreen,
				.r = 50,
			},
			.knob_off{
				.background_color = Palette::Lightgray,
				.r = 50,
			},
			.circle_size = {50,50},
			.text_on = U"ON",
			.text_off= U"OFF",
		}
	};
	while (System::Update()) {
		toggle.update();
		toggle.draw();
	}
}
