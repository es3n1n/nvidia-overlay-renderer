#include "overlay.h"


namespace overlay {
	namespace vars {
		HWND m_window_hwnd;
		RECT m_window_rect;
		D2D1_SIZE_U m_window_size;
	}

	utils::e_status init( ) {
		TRACE_FN;

		vars::m_window_hwnd = FindWindowW( L"CEF-OSC-WIDGET", L"NVIDIA GeForce Overlay" );
		L_ASSERT( vars::m_window_hwnd, "overlay not found" );

		auto apply_window_styles = [ ] ( ) -> utils::e_status {
			TRACE_FN;

			// style
			SetWindowLongW( vars::m_window_hwnd, -20, static_cast< LONG_PTR >( ( static_cast< int >( GetWindowLongW( vars::m_window_hwnd, -20 ) ) | 0x20 ) ) );

			// transparency
			MARGINS margin = { -1, -1, -1, -1 };
			DwmExtendFrameIntoClientArea( vars::m_window_hwnd, &margin );
			L_ASSERT( SetLayeredWindowAttributes( vars::m_window_hwnd, 0x000000, 0xFF, 0x02 ), "SetLayeredWindowAttributes() returned false" );

			// top most
			L_ASSERT( SetWindowPos( vars::m_window_hwnd, HWND_TOPMOST, 0, 0, 0, 0, 0x0002 | 0x0001 ), "SetWindowPos() returned false" );

			return utils::e_status::status_ok;
		};

		L_ASSERT( apply_window_styles( ), "cannot apply styles" );
		L_ASSERT( ShowWindow( vars::m_window_hwnd, SW_SHOW ), "ShowWindow() returned false" );

		L_ASSERT( GetClientRect( vars::m_window_hwnd, &vars::m_window_rect ), "GetClientRect() returned false" );
		vars::m_window_size = D2D1::SizeU( vars::m_window_rect.right - vars::m_window_rect.left, vars::m_window_rect.bottom - vars::m_window_rect.top );

		return utils::e_status::status_ok;
	}
}
