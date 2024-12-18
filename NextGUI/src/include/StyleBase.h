#pragma once
#ifndef _NEXTGUI_STYLEBASE_H_
#define _NEXTGUI_STYLEBASE_H_

#include"PositionType.h"

namespace nGUI {
	struct StyleBase {
		Vec2 pos = { 0,0 };
		SizeF size = { 0,0 };
		PositionType position_type = PositionType::topLeft;
		int32 z_index = 0;
		constexpr inline Vec2 getCalculatedPosition() const {
			switch (position_type) {
			case nGUI::PositionType::center:
				return pos.movedBy(-size / 2);
				break;
			case nGUI::PositionType::topLeft:
				return pos;
				break;
			case nGUI::PositionType::topCenter:
				return pos.movedBy(-size.x / 2, 0);
				break;
			case nGUI::PositionType::topRight:
				return pos.movedBy(-size.x, 0);
				break;
			case nGUI::PositionType::rightCenter:
				return pos.movedBy(-size.x, -size.y / 2);
				break;
			case nGUI::PositionType::bottomRight:
				return pos.movedBy(-size.x, -size.y);
				break;
			case nGUI::PositionType::bottomCenter:
				return pos.movedBy(-size.x / 2, -size.y);
				break;
			case nGUI::PositionType::bottomLeft:
				return pos.movedBy(0, -size.y);
				break;
			case nGUI::PositionType::leftCenter:
				return pos.movedBy(0, -size.y / 2);
				break;
			default:
				return pos;
				break;
			}
		}
	};
}

#endif
