#pragma once
#ifndef _NEXT_GUI_FLOWLAYOUT_H_
#define _NEXT_GUI_FLOWLAYOUT_H_

#include"Panel.h"

#include"stdafx.h"

namespace nGUI {
	struct Flow {
		static void apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize, const Vec2& spacing, bool wrap, PositionType alignment) {
			Vec2 currentPos = containerPos;
			double lineHeight = 0.0;
			Array<Array<Panel::Record*>> rows;
			Array<Panel::Record*> currentRow;

			for (auto& record : components) {
				const auto& componentSize = record.value->getSize();
				if (wrap && currentPos.x + componentSize.x > containerPos.x + containerSize.x) {
					rows.push_back(std::move(currentRow));
					currentRow.clear();
					currentPos.x = containerPos.x;
					currentPos.y += lineHeight + spacing.y;
					lineHeight = 0.0;
				}
				currentRow.push_back(&record);
				currentPos.x += componentSize.x + spacing.x;
				lineHeight = Math::Max(lineHeight, componentSize.y);
			}
			if (!currentRow.isEmpty()) {
				rows.push_back(std::move(currentRow));
			}

			currentPos = containerPos;
			for (auto& row : rows) {
				double rowWidth = 0.0;
				double rowHeight = 0.0;
				for (auto* record : row) {
					rowWidth += record->value->getSize().x + spacing.x;
					rowHeight = Max(rowHeight, record->value->getSize().y);
				}
				rowWidth -= spacing.x;

				double rowOffset = 0.0;
				switch (alignment) {
				case PositionType::center:
				case PositionType::topCenter:
				case PositionType::bottomCenter:
					rowOffset = (containerSize.x - rowWidth) / 2;
					break;
				case PositionType::topRight:
				case PositionType::rightCenter:
				case PositionType::bottomRight:
					rowOffset = containerSize.x - rowWidth;
					break;
				default:
					break;
				}

				Vec2 rowStart = { containerPos.x + rowOffset, currentPos.y };
				for (auto* record : row) {
					const auto& componentSize = record->value->getSize();
					record->value->setPos(rowStart);
					const auto&& size = record->value->getSize();
					switch (alignment) {
					case PositionType::center:
					case PositionType::leftCenter:
					case PositionType::rightCenter:
					{
						const auto offset_y = (rowHeight - size.y) / 2;
						record->value->setPos(record->value->getPos().movedBy(0, offset_y));
					}
					break;
					case PositionType::bottomCenter:
					case PositionType::bottomLeft:
					case PositionType::bottomRight:
					{
						const auto offset_y = rowHeight - size.y;
						record->value->setPos(record->value->getPos().movedBy(0, offset_y));
					}
					break;
					default:
						break;
					}
					rowStart.x += componentSize.x + spacing.x;
				}
				currentPos.y += rowHeight + spacing.y;
			}
		}
	};	
}

#endif
