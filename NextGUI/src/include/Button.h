#pragma once
#ifndef _NEXTGUI_BUTTON_H_
#define _NEXTGUI_BUTTON_H_

#include"RoundRectStyle.h"
#include"Text.h"

#include"StyleBase.h"
#include"AbstractComponent.h"

#include"stdafx.h"


namespace nGUI {
	struct ButtonStyle : public StyleBase {

		SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
		union {
			RoundRectStyle rrs{ Palette::White };
			struct {
				GradationColor<ColorF> background_color;
				Outline outline;
				Shadow shadow;
				double r;
			};
		};

		SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
		union {
			RoundRectStyle rrs_pressed{ Palette::Lightgray };
			struct {
				GradationColor<ColorF> background_pressed_color;
				Outline outline_pressed;
				Shadow shadow_pressed;
				double r_pressed;
			};
		};

		SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
		union {
			RoundRectStyle rrs_unable{ Palette::Gray };
			struct {
				GradationColor<ColorF> background_unable_color;
				Outline outline_unable;
				Shadow shadow_unable;
				double r_unable;
			};
		};
		void setR(double _r) {
			this->r = _r;
			this->r_pressed = _r;
			this->r_unable = _r;
		}
		Text text;
		bool enable = true;
	};

	class Button : public AbstractComponent {
	public:
		Button(ButtonStyle style = ButtonStyle{}) :
			style(style),
			box(RoundRect{ style.getCalculatedPosition(), style.size,style.r })
		{}

		void update() override;

		void draw()const override;

		constexpr inline bool isRelease() const noexcept {
			return this->style.enable && this->is_release;
		}

		constexpr inline bool isMouseOver() const noexcept {
			return this->is_over;
		}

		const RoundRect& getAsRoundRect() const {
			return box.round_rect;
		}

		void setStyle(const ButtonStyle& _style) {
			this->style = _style;
		}

		constexpr const Vec2& getPos() const override {
			return style.pos;
		}
		constexpr const SizeF& getSize() const override {
			return style.size;
		}
		constexpr int32 getZIndex() const override {
			return style.z_index;
		}
		constexpr void setPos(const Vec2& pos, PositionType position_type = PositionType::topLeft) override {
			style.pos = pos;
			style.position_type = position_type;
		}
		void ReConstruct() override {
			box = GradationRoundRect{ RoundRect{style.getCalculatedPosition(),style.size,style.r} };
		}
	private:
		void updateBox(const RoundRectStyle& rrs) {
			box.round_rect.r = rrs.r;
		}

		void drawBox(const RoundRectStyle& rrs) const {
			box.round_rect.drawShadow(rrs.shadow.offset, rrs.shadow.blur, rrs.shadow.spread, rrs.shadow.color, rrs.shadow.fill);
			rrs.background_color.draw(box);
			box.round_rect.drawFrame(rrs.outline.thickness, rrs.outline.color);
		}
		ButtonStyle style;
		GradationRoundRect box;
		bool is_pressed = false;
		bool is_release = false;
		bool is_over = false;
	};
}


#endif
