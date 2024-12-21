#include"LayoutManager.h"

#include"LayoutUtil.h"
#include"FlewLayout.h"
#include"FlowLayout.h"
#include"GridLayout.h"

namespace nGUI {
	void LayoutManager::apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const {
		switch (options.type) {
		case LayoutType::Flex:
			Flex::apply(components, containerPos, containerSize, options.spacing, options.wrap);
			break;
		case LayoutType::Flow:
			Flow::apply(components, containerPos, containerSize, options.spacing, options.wrap, options.alignment);
			break;
		case LayoutType::Grid:
			Grid::apply(components, containerPos, containerSize, options.spacing, options.columns);
			break;
		}
		Util::alignComponents(components, containerPos, containerSize, options.containerAlignment);
	}
}
