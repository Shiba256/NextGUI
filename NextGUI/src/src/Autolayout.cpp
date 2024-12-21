#include"Autolayout.h"

namespace nGUI {
	void Autolayout::apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const {
		switch (options.type) {
		case LayoutType::Flex:
			applyFlexLayout(components, containerPos, containerSize);
			break;
		case LayoutType::Flow:
			applyFlowLayout(components, containerPos, containerSize);
			break;
		case LayoutType::Grid:
			applyGridLayout(components, containerPos, containerSize);
			break;
		}
		alignComponents(components, containerPos, containerSize);
	}

	void Autolayout::applyFlexLayout(Array<Panel::Record>& components, const Vec2& containerPos, [[maybe_unused]]const SizeF& containerSize) const {
		Vec2 currentPos = containerPos;
		for (auto& record : components) {
			const auto& componentSize = options.fixedSize.value_or(record.value->getSize());
			record.value->setPos(currentPos);
			currentPos.x += componentSize.x + options.spacing.x;
		}
	}

	void Autolayout::applyFlowLayout(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const {
		Vec2 currentPos = containerPos;
		double lineHeight = 0.0;
		Array<Array<Panel::Record*>> rows; // Group components by rows
		Array<Panel::Record*> currentRow;

		for (auto& record : components) {
			const auto& componentSize = options.fixedSize.value_or(record.value->getSize());
			if (options.wrap && currentPos.x + componentSize.x > containerPos.x + containerSize.x) {
				rows.push_back(std::move(currentRow));
				currentRow.clear();
				currentPos.x = containerPos.x;
				currentPos.y += lineHeight + options.spacing.y;
				lineHeight = 0.0;
			}
			currentRow.push_back(&record);
			currentPos.x += componentSize.x + options.spacing.x;
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
				rowWidth += options.fixedSize.value_or(record->value->getSize()).x + options.spacing.x;
				rowHeight = Max(rowHeight, options.fixedSize.value_or(record->value->getSize()).y);
			}
			rowWidth -= options.spacing.x; // Remove trailing spacing

			double rowOffset = 0.0;
			switch (options.alignment) {
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
				const auto& componentSize = options.fixedSize.value_or(record->value->getSize());
				record->value->setPos(rowStart);
				const auto&& size = record->value->getSize();
				switch (options.alignment) {
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
				rowStart.x += componentSize.x + options.spacing.x;
			}
			currentPos.y += rowHeight + options.spacing.y;
		}
	}

	void Autolayout::applyGridLayout(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const {
		Vec2 currentPos = containerPos;
		const double cellWidth = options.fixedSize ? options.fixedSize->x : containerSize.x / options.columns;
		const double cellHeight = options.fixedSize ? options.fixedSize->y : containerSize.y / (components.size() / options.columns + 1);
		size_t column = 0;

		for (auto& record : components) {
			record.value->setPos(currentPos);
			currentPos.x += cellWidth + options.spacing.x;
			if (++column >= options.columns) {
				column = 0;
				currentPos.x = containerPos.x;
				currentPos.y += cellHeight + options.spacing.y;
			}
		}
	}

	void Autolayout::alignComponents(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const {
		RectF boundingRect = calculateBoundingRect(components);
		Vec2 alignmentOffset = calculateAlignmentOffset(boundingRect, containerPos, containerSize, options.containerAlignment);

		for (auto& record : components) {
			record.value->setPos(record.value->getLT() + alignmentOffset);
		}
	}

	RectF Autolayout::calculateBoundingRect(const Array<Panel::Record>& components) const {
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

	Vec2 Autolayout::calculateAlignmentOffset(const RectF& boundingRect, const Vec2& containerPos, const SizeF& containerSize, PositionType alignmentType) const {
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
}
