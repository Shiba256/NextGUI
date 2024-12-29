#pragma once
#ifndef _NEXT_GUI_CHECKBOX_H_
#define _NEXT_GUI_CHECKBOX_H_

#include"StyleBase.h"
#include"RoundRectStyle.h"
#include"Text.h"
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
		void setR(double _r) {
			rrs.r = _r;
			rrs_clicked.r = _r;
			rrs_mouseover.r = _r;
			rrs_unable.r = _r;
		}
		void setCheckBoxR(double _r) {
			checkbox.r = _r;
			checkbox_clicked.r = _r;
			checkbox_mouseover.r = _r;
			checkbox_unable.r = _r;
		}
	};

	class CheckBox : public AbstractComponent {
	public:
		CheckBox(CheckBoxStyle style = CheckBoxStyle{}) :
			style(style),
			box((RoundRect{ style.getCalculatedPosition(), style.size,style.r })),
			checkbox(GradationRoundRect{ RoundRect{Arg::center = box.round_rect.leftCenter().movedBy(style.checkbox_margin).movedBy(style.checkbox_size.x / 2,0),style.checkbox_size,style.checkbox_r} })
		{}

		void update() override;

		void draw() const override;

		constexpr bool isSelected() const noexcept {
			return style.is_check;
		}

		CheckBoxStyle& changeStyle() {
			return style;
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
		void ReConstruct() override;
	private:
		void drawBox(const RoundRectStyle& rrs) const;
		void drawCheckBox(const RoundRectStyle& rrs) const;

		bool is_over = false;
		CheckBoxStyle style;
		GradationRoundRect box;
		GradationRoundRect checkbox;
	};
}

#endif
