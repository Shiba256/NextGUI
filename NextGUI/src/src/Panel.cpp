#include"Panel.h"
#include"Autolayout.h"

namespace nGUI {
	void  Panel::update() {
		components.sort_by([](const Record& v1, const Record& v2) ->bool {return v1.value->getZIndex() < v2.value->getZIndex(); });
		for (auto i : Range(components.size() - 1ull, 0ull, -1)) {
			auto& component = components[i];
			if (style.hide_overflow && not RectF{ style.getCalculatedPosition(), style.size }.contains(component.value->getLT()))continue;
			component.value->update();
		}
	}

	void Panel::draw()const {
		for (const auto& component : components) {
			if (style.hide_overflow && not RectF{ style.getCalculatedPosition(), style.size }.contains(component.value->getLT()))continue;
			component.value->draw();
		}
	}

	void Panel::drawDebug(const Outline& outline ) {
		RectF{ style.getCalculatedPosition(),style.size }.drawFrame(outline.thickness, outline.color);
	}

	void Panel::add(StringView name, const std::shared_ptr<AbstractComponent>& component) {
		component->setPos(component->getLT() + this->getLT());
		component->ReConstruct();
		components.emplace_back(id_count++, name, component);
		this->callLayoutManager();
	}

	void Panel::erase(StringView name) {
		components.remove_if([&name](const Record& record)->bool {return record.key == name; });
		this->callLayoutManager();
	}

	void Panel::erase(size_t id) {
		components.remove_if([&id](const Record& record)->bool {return record.getID() == id; });
		this->callLayoutManager();
	}

	void Panel::addLayoutManager(Autolayout&& manager) {
		this->layout_manager = std::make_shared<Autolayout>(manager);
		this->callLayoutManager();
	}

	void Panel::callLayoutManager() {
		if (layout_manager)layout_manager->apply(components, this->getLT(), this->getSize());
		components.each([](Record& record) {record.value->ReConstruct(); });
	}


	void Panel::setPos(const Vec2& pos, PositionType position_type)  {
		const auto before_pos = style.getCalculatedPosition();
		style.pos = pos;
		style.position_type = position_type;
		const auto move = style.getCalculatedPosition() - before_pos;
		for (auto& component : components) {
			component.value->setPos(component.value->getLT().movedBy(move));
			component.value->ReConstruct();
		}
	}

	void Panel::ReConstruct() {
		if (style.auto_size && not components.isEmpty()) {
			RectF rect{ components.front().value->getLT(),components.front().value->getSize() };
			for (const auto& component : components) {
				const auto&& lt = component.value->getLT();
				const auto&& size = component.value->getSize();
				rect.x = Math::Min(rect.x, lt.x);
				rect.y = Math::Min(rect.y, lt.y);
				rect.size.x = Math::Max(rect.size.x, (size + lt).x - rect.x);
				rect.size.y = Math::Max(rect.size.y, (size + lt).y - rect.y);
			}
			style.size = rect.size;
			style.pos.moveBy(rect.pos - style.getCalculatedPosition());
		}
		this->callLayoutManager();
	}
}
