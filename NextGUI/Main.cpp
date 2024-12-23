#include<Siv3D.hpp>

#include"MouseEventManager.h"
#include"Initializer.h"

void Main() {
	Window::Resize(1920, 1080);
	Scene::SetBackground(Palette::Aliceblue);
	nGUI::Initializer();

	while (System::Update()) {
	}
}
