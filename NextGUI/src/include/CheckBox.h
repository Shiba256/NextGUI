#pragma once

#include"StyleBase.h"
#include"RoundRectStyle.h"
#include"Text.h"
#include"nFont.h"
#include"DrawText.h"
#include"stdafx.h"

namespace nGUI {
	struct CheckBoxStyle {
		COMMON_STYLE;
		union {
			RoundRectStyle rrs;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> background_color;
				Outline outline;
				Shadow shadow;
				double r;
			};
		};
		union {
			RoundRectStyle rrs_mouseover;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> background_color_mouseover;
				Outline outline_mouseover;
				Shadow shadow_mouseover;
				double r_mouseover;
			};
		};
		union {
			RoundRectStyle rrs_clicked;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> background_color_clicked;
				Outline outline_clicked;;
				Shadow shadow_clicked;
				double r_clicked;
			};
		};
		union {
			RoundRectStyle rrs_unable;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> background_color_unable;
				Outline outline_unable;
				Shadow shadow_unable;
				double r_unable;
			};
		};
		union {
			RoundRectStyle checkbox;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> checkbox_background_color;
				Outline checkbox_outline;
				Shadow checkbox_shadow;
				double checkbox_r;
			};
		};
		union {
			RoundRectStyle checkbox_mouseover;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> checkbox_background_color_mouseover;
				Outline checkbox_outline_mouseover;
				Shadow checkbox_shadow_mouseover;
				double checkbox_r_mouseover;
			};
		};
		union {
			RoundRectStyle checkbox_clicked;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> checkbox_background_color_over;
				Outline checkbox_outline_over;
				Shadow checkbox_shadow_over;
				double checkbox_r_over;
			};
		};
		union {
			RoundRectStyle checkbox_unable;
			SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
				struct {
				GradationColor<ColorF> checkbox_background_color_unable;
				Outline checkbox_outline_unable;
				Shadow checkbox_shadow_unable;
				double checkbox_r_unable;
			};
		};
		Text text;
		ColorF check_color = Palette::Skyblue;
		Vec2 checkbox_margin = { 10,0 };
		SizeF checkbox_size = { 0,0 };
		bool enable = true;
		bool is_check = false;
	};
	class CheckBox : public AbstractComponent {
	public:
		CheckBox(CheckBoxStyle style = CheckBoxStyle{}) :
			style(style),
			box((RoundRect{ style.getCalculatedPosition(), style.size,style.r })),
			checkbox(GradationRoundRect{ RoundRect{Arg::center = box.round_rect.leftCenter().movedBy(style.checkbox_margin).movedBy(style.checkbox_size.x / 2,0),style.checkbox_size,style.checkbox_r} })
		{}

		void update() override {
			if (box.round_rect.mouseOver()) {
				Cursor::RequestStyle(CursorStyle::Hand);
			}
			if (box.round_rect.leftReleased()) {
				style.is_check = !(style.is_check);
				Mouse::ClearLRInput();
			}
		}

		void draw() const override {
			if (not style.enable) {
				this->drawBox(style.rrs_unable);
				this->drawCheckBox(style.checkbox_unable);
			}
			else if (box.round_rect.mouseOver()) {
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

		constexpr bool isSelected() const noexcept {
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
			box = GradationRoundRect{ RoundRect{style.getCalculatedPosition(),style.size,style.r} };
			checkbox = GradationRoundRect{ RoundRect{Arg::center = box.round_rect.leftCenter().movedBy(style.checkbox_margin).movedBy(style.checkbox_size.x / 2,0),style.checkbox_size,style.checkbox_r} };
		}
	private:
		void drawBox(const RoundRectStyle& rrs) const {
			box.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(box);
			box.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
		}

		void drawCheckBox(const RoundRectStyle& rrs) const {
			checkbox.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(checkbox);
			checkbox.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
			if (style.is_check)nFont::instance().get()(U"✔").drawAt(checkbox.round_rect.w * 0.9, checkbox.round_rect.center(), style.check_color);
		}

		CheckBoxStyle style;
		GradationRoundRect box;
		GradationRoundRect checkbox;
	};
}
