	template<class Type>
	Type* nGUI::Panel::get(StringView name) const {
		for (size_t i = 0ull, e = name.size() - 1; i < e; i++) {
			if (name[i] == U':' && name[i + 1] == U':') {
				return this->get<Panel>(name.substr(0ull, i))->get<Type>(name.substr(i + 2ull));
			}
		}
		if (auto it = cache.find(name); it != cache.end()) {
			return static_cast<Type*>(it->second);
		}
		for (auto& component : components) {
			if (component.key == name) {
				if (auto ptr = dynamic_cast<Type*>(component.value.get())) {
					cache.emplace(name, ptr);
					return ptr;
				}
			}
		}
		return nullptr;
	}
