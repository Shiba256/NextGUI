#include"DrawIconText_impl.h"

namespace nGUI {
	String DrawIconText_impl::replaceUnicode(StringView str) {
		String replaced_str = U"";
		for (size_t i1 = 0ull; i1 < str.size(); i1++) {
			String stack = U"";
			if (str[i1] == U'$') {
				for (size_t i2 = i1 + 1; i2 < str.size(); i2++) {
					if (str[i2] == U'$') {
						if (stack.empty()) {
							replaced_str += str[i1];
							break;
						}
						uint32 unicodeValue = std::stoul(stack.toWstr(), nullptr, 16);
						char32 unicode = static_cast<char32>(unicodeValue);
						replaced_str += unicode;
						i1 = i2;
						break;
					}
					else {
						if (not IsXdigit(str[i2])) {
							replaced_str += str[i1];
							break;
						}
						stack += str[i2];
					}
				}

			}
			else replaced_str += str[i1];
		}
		return replaced_str;
	}
}
