#pragma once
#ifndef _NEXT_GUI_GRIDLAYOUT_H_
#define _NEXT_GUI_GRIDLAYOUT_H_

#include"Panel.h"

#include"stdafx.h"

namespace nGUI {
	struct Grid {
		static void apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize, const Vec2& spacing, size_t columns) {
			const size_t numColumns = columns;
			if (numColumns == 0) {
				return;
			}

			const double cellWidth = containerSize.x / numColumns;
			const double cellHeight = containerSize.y / Math::Ceil(components.size() / static_cast<double>(numColumns));

			Vec2 currentPos = containerPos;
			size_t column = 0;

			for (auto& record : components) {
				record.value->setPos(currentPos);

				currentPos.x += cellWidth + spacing.x;
				++column;

				if (column >= numColumns) {
					column = 0;
					currentPos.x = containerPos.x;
					currentPos.y += cellHeight + spacing.y;
				}
			}
		}
	};
}

#endif
