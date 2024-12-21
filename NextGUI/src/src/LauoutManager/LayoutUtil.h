#pragma once
#ifndef _NEXTGUI_LAYOUTUTIL_H_
#define _NEXTGUI_LAYOUTUTIL_H_

#include"Panel.h"

#include"stdafx.h"

namespace nGUI {
	struct Util {
		static void alignComponents(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize, PositionType containerAlignment) {
			RectF boundingRect = calculateBoundingRect(components);
			Vec2 alignmentOffset = calculateAlignmentOffset(boundingRect, containerPos, containerSize, containerAlignment);

			for (auto& record : components) {
				record.value->setPos(record.value->getLT() + alignmentOffset);
			}
		}
	private:
		static RectF calculateBoundingRect(const Array<Panel::Record>& components) {
			if (components.isEmpty()) {
				return RectF();
			}

			RectF rect{ components.front().value->getLT(), components.front().value->getSize() };
			for (const auto& record : components) {
				const auto lt = record.value->getLT();
				const auto size = record.value->getSize();
				rect.x = Math::Min(rect.x, lt.x);
				rect.y = Math::Min(rect.y, lt.y);
				rect.size.x = Math::Max(rect.size.x, (lt.x + size.x) - rect.x);
				rect.size.y = Math::Max(rect.size.y, (lt.y + size.y) - rect.y);
			}
			return rect;
		}

		static Vec2 calculateAlignmentOffset(const RectF& boundingRect, const Vec2& containerPos, const SizeF& containerSize, PositionType alignmentType) {
			Vec2 offset = { 0.0, 0.0 };
			switch (alignmentType) {
			case PositionType::center:
				offset.x = containerPos.x + (containerSize.x - boundingRect.w) / 2 - boundingRect.x;
				offset.y = containerPos.y + (containerSize.y - boundingRect.h) / 2 - boundingRect.y;
				break;
			case PositionType::topCenter:
				offset.x = containerPos.x + (containerSize.x - boundingRect.w) / 2 - boundingRect.x;
				offset.y = containerPos.y - boundingRect.y;
				break;
			case PositionType::topRight:
				offset.x = containerPos.x + containerSize.x - boundingRect.w - boundingRect.x;
				offset.y = containerPos.y - boundingRect.y;
				break;
			case PositionType::rightCenter:
				offset.x = containerPos.x + containerSize.x - boundingRect.w - boundingRect.x;
				offset.y = containerPos.y + (containerSize.y - boundingRect.h) / 2 - boundingRect.y;
				break;
			case PositionType::bottomRight:
				offset.x = containerPos.x + containerSize.x - boundingRect.w - boundingRect.x;
				offset.y = containerPos.y + containerSize.y - boundingRect.h - boundingRect.y;
				break;
			case PositionType::bottomCenter:
				offset.x = containerPos.x + (containerSize.x - boundingRect.w) / 2 - boundingRect.x;
				offset.y = containerPos.y + containerSize.y - boundingRect.h - boundingRect.y;
				break;
			case PositionType::bottomLeft:
				offset.x = containerPos.x - boundingRect.x;
				offset.y = containerPos.y + containerSize.y - boundingRect.h - boundingRect.y;
				break;
			case PositionType::leftCenter:
				offset.x = containerPos.x - boundingRect.x;
				offset.y = containerPos.y + (containerSize.y - boundingRect.h) / 2 - boundingRect.y;
				break;
			case PositionType::topLeft:
			default:
				offset.x = containerPos.x - boundingRect.x;
				offset.y = containerPos.y - boundingRect.y;
				break;
			}
			return offset;
		}
	};
}

#endif
