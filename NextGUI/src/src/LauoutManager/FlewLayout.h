#pragma once
#ifndef _NEXT_GUI_FLEXLAYOUT_H_
#define _NEXT_GUI_FLEXLAYOUT_H_

#include"Panel.h"

#include"stdafx.h"

namespace nGUI {
	struct Flex {
		static void apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize, const Vec2& spacing, bool wrap) {
			Vec2 currentPos = containerPos;
			double maxHeightInRow = 0.0;

			for (auto& record : components) {
				const auto& componentSize = record.value->getSize();

				if (wrap && currentPos.x + componentSize.x > containerPos.x + containerSize.x) {
					currentPos.x = containerPos.x;
					currentPos.y += maxHeightInRow + spacing.y;
					maxHeightInRow = 0.0;
				}

				record.value->setPos(currentPos);

				currentPos.x += componentSize.x + spacing.x;
				maxHeightInRow = Math::Max(maxHeightInRow, componentSize.y);
			}
		}
	};
}

#endif
