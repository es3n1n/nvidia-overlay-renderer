#pragma once
#include "../logger/logger.h"
#include "../overlay/overlay.h"

#include <stdio.h>
#include <dwmapi.h> 
#include <d2d1.h>
#include <dwrite.h>
#pragma comment(lib, "Dwrite")

#pragma comment(lib, "Dwmapi.lib") 
#pragma comment(lib, "d2d1.lib")


namespace renderer {
	namespace internal {
		extern ID2D1Factory* m_d2d;
		extern ID2D1HwndRenderTarget* m_render_target;
		extern IDWriteFactory* m_factory;

		utils::e_status init( );
		utils::e_status shutdown( );
	}
}
