#pragma once
#ifndef _NEXTGUI_STYLEBASE_H_
#define _NEXTGUI_STYLEBASE_H_

#include"PositionType.h"

namespace nGUI {
	constexpr inline Vec2 __getPosition(const Vec2& pos, const Vec2& size, PositionType position_type) {
		switch (position_type) {
		case PositionType::center:
			return pos.movedBy(-size / 2);
			break;
		case PositionType::topLeft:
			return pos;
			break;
		case PositionType::topCenter:
			return pos.movedBy(-size.x / 2, 0);
			break;
		case PositionType::topRight:
			return pos.movedBy(-size.x, 0);
			break;
		case PositionType::rightCenter:
			return pos.movedBy(-size.x, -size.y / 2);
			break;
		case PositionType::bottomRight:
			return pos.movedBy(-size.x, -size.y);
			break;
		case PositionType::bottomCenter:
			return pos.movedBy(-size.x / 2, -size.y);
			break;
		case PositionType::bottomLeft:
			return pos.movedBy(0, -size.y);
			break;
		case PositionType::leftCenter:
			return pos.movedBy(0, -size.y / 2);
			break;
		default:
			return pos;
			break;
		}
	}
}

#define __STYLE_BASE Vec2 pos = {0,0}; SizeF size = {0,0}; PositionType position_type = PositionType::topLeft; int32 z_index = 0;
#define __STYLE_FUNCTION constexpr inline Vec2 getCalculatedPosition() const {return __getPosition(this->pos,this->size,this->position_type);}
#define COMMON_STYLE __STYLE_BASE __STYLE_FUNCTION

#endif
