#pragma once
#ifndef _NEXT_GUI_NGUI_H_
#define _NEXT_GUI_NGUI_H_

#ifndef _NO_USE_COMPONENT_
// Box
#ifndef _NO_USE_BOX_
#include"Box.h"
#endif // !_NO_USE_BOX_

// Button
#ifndef _NO_USE_BUTTON_
#include"Button.h"
#include"ButtonPreset.h"
#endif // !_NO_USE_BUTTON_

// CheckBox
#ifndef _NO_USE_CHECKBOX_
#include"CheckBox.h"
#include"CheckBoxPreset.h"
#endif // !_NO_USE_CHECKBOX_

// Panel
#ifndef _NO_USE_PANEL_
#include"Panel.h"
#endif // !_NO_USE_PANEL_

// LayoutManager
#ifndef _NO_USE_LAYOUTMANAGER_
#include"LayoutManager.h"
#endif // !_NO_USE_LAYOUTMANAGER_
#endif // !_NO_USE_COMPONENT_

#ifndef _NO_USE_NGUISYSTEM_
#include"Initializer.h"
#endif // !_NO_USE_NGUISYSTEM_

// Open Siv 3D
#include"stdafx.h"

#endif // !_NEXT_GUI_NGUI_H_
