#pragma once
#ifndef _NEXTGUI_BOX_H_
#define _NEXTGUI_BOX_H_

#include"StyleBase.h"
#include"AbstractComponent.h"
#include"GradationRoundRect.h"

#include"RoundRectStyle.h"

#include"stdafx.h"

namespace nGUI {
	struct BoxStyle : public StyleBase {
		SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)
		union {
			RoundRectStyle rrs;
			struct {
				GradationColor<ColorF> background_color;
				Outline outline;
				Shadow shadow;
			};
		};
		double r = 0.0;
	};

	class Box : public AbstractComponent {
	public:
		Box(BoxStyle style = BoxStyle{}) :
			style(style),
			box{ RoundRect{style.getCalculatedPosition(),style.size,style.r} }
		{}

		void update() override {

		}

		void draw() const override {
			box.round_rect.drawShadow(style.shadow.offset, style.shadow.blur, style.shadow.spread, style.shadow.color, style.shadow.fill);
			style.background_color.draw(box);
			box.round_rect.drawFrame(style.outline.thickness, style.outline.color);
		}

		const RoundRect& getAsRoundRect() const {
			return box.round_rect;
		}

		void setStyle(const BoxStyle& _style) {
			this->style = _style;
		}

		BoxStyle& changeStyle() {
			return this->style;
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
		}
	private:
		BoxStyle style;
		GradationRoundRect box;
	};

}
#endif
