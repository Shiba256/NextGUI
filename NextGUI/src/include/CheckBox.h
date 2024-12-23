#pragma once

#include"StyleBase.h"
#include"RoundRectStyle.h"
#include"Text.h"
#include"nFont.h"
#include"DrawText.h"
#include"MouseEventManager.h"
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
			is_over = MouseEventManager::mouseOver(box.round_rect);
			if (MouseEventManager::leftReleased(box.round_rect) && style.enable) {
				style.is_check = !(style.is_check);
				MouseEventManager::clearAll();
			}else if (is_over) {
				Cursor::RequestStyle(CursorStyle::Hand);
				MouseEventManager::clearMouseOver();
			}
			
		}

		void draw() const override {
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
		bool is_over = false;
		CheckBoxStyle style;
		GradationRoundRect box;
		GradationRoundRect checkbox;
	};
}


namespace nGUI {
	namespace Preset {
		namespace CheckBox {
			static inline CheckBoxStyle Default(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style{};
				style.rrs = {
					.background_color = {.color_from = Palette::White},
					.shadow = {.offset = {0, 4}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_mouseover = {
					.background_color = {.color_from = Palette::Lightgray},
					.shadow = {.offset = {0, 6}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.3)}
				};
				style.rrs_clicked = {
					.background_color = {.color_from = Palette::Gray},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Darkgray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};

				style.checkbox = {
					.background_color = {.color_from = Palette::Skyblue},
					.shadow = {.offset = {0, 2}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.3)},
					.r = 6.0
				};
				style.checkbox_mouseover = {
					.background_color = {.color_from = Palette::Lightblue},
					.shadow = {.offset = {0, 3}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.4)},
					.r = 6.0
				};
				style.checkbox_clicked = {
					.background_color = {.color_from = Palette::Blue},
					.shadow = {.offset = {0, 1}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.25)},
					.r = 6.0
				};
				style.checkbox_unable = {
					.background_color = {.color_from = Palette::Gray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)},
					.r = 6.0
				};

				style.text = { .text = text, .color = Palette::Black };
				style.check_color = Palette::Skyblue;
				style.checkbox_margin = { 10, 0 };
				style.checkbox_size = { 20, 20 };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline CheckBoxStyle Modern(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = ColorF(0.95), .color_to = ColorF(0.9), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 1.5, .color = ColorF(0.8) };
				style.rrs.shadow = { .offset = {0, 4}, .blur = 12, .spread = 0, .color = ColorF(0.0, 0.2) };

				style.checkbox.background_color = { .color_from = Palette::White };
				style.checkbox.shadow = { .offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15) };
				style.checkbox_outline = { .thickness = 1.5, .color = ColorF(0.8) };
				return style;
			}

			static inline CheckBoxStyle Frosted(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(1.0), 0.85), .color_to = Scene::GetBackground().lerp(ColorF(1.0), 0.75), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 1.0, .color = ColorF(0.7) };
				style.rrs.shadow = { .offset = {0, 6}, .blur = 15, .spread = 0, .color = ColorF(0.0, 0.25) };

				style.checkbox.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(0.0), 0.2) };
				style.checkbox.shadow = { .offset = {0, 2}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.3) };
				style.checkbox_outline = { .thickness = 1.0, .color = ColorF(0.6) };
				return style;
			}

			static inline CheckBoxStyle Glassy(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(1.0), 0.9), .color_to = Scene::GetBackground().lerp(ColorF(1.0), 0.8), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 2.0, .color = ColorF(0.85) };
				style.rrs.shadow = { .offset = {0, 8}, .blur = 20, .spread = 0, .color = ColorF(0.0, 0.3) };

				style.checkbox.background_color = { .color_from = Palette::White, .color_to = Palette::Lightgray, .type = GradationType::top_bottom };
				style.checkbox.shadow = { .offset = {0, 4}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.25) };
				style.checkbox_outline = { .thickness = 2.0, .color = ColorF(0.8) };
				return style;
			}
		}
	}
}

