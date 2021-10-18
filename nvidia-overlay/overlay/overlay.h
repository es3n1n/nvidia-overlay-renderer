#pragma once
#include "../logger/logger.h"
#include <d2d1.h>
#include <stdio.h>
#include <dwmapi.h> 
#pragma comment(lib, "Dwmapi.lib") 


namespace overlay {
	namespace vars {
		inline HWND m_window_hwnd;
		inline RECT m_window_rect;
		inline D2D1_SIZE_U m_window_size;
	}

	utils::e_status init( );
}
