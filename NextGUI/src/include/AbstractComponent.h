#pragma once
#ifndef _NEXTGUI_ABSTRACTCOMPONENT_H_
#define _NEXTGUI_ABSTRACTCOMPONENT_H_

#include"PositionType.h"

#include"stdafx.h"

namespace nGUI {
	class AbstractComponent {
	public:
		virtual void update() = 0;
		virtual void draw() const = 0;

		virtual constexpr Vec2 getPos() const = 0;
		virtual constexpr Vec2 getLT() const = 0;
		virtual constexpr SizeF getSize() const = 0;
		virtual constexpr int32 getZIndex() const = 0;
		virtual void setPos(const Vec2& pos, PositionType position_type = PositionType::topLeft) = 0;
		virtual void setSize(const SizeF& size) = 0;
		virtual void ReConstruct() = 0;
	};
}

#endif
