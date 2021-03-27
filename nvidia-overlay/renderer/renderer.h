#pragma once
#include "internal.h"
#include "../utils/vec2.h"


namespace renderer {
	namespace colors {
		extern ID2D1SolidColorBrush* m_white_color;
		extern ID2D1SolidColorBrush* m_red_color;
		extern ID2D1SolidColorBrush* m_green_color;
		extern ID2D1SolidColorBrush* m_blue_color;
		extern ID2D1SolidColorBrush* m_black_color;

		utils::e_status init( );
		utils::e_status shutdown( );
	}

	namespace fonts {
		extern IDWriteTextFormat* m_consolas_font;
		utils::e_status init( );
		utils::e_status shutdown( );
	}

	namespace scene {
		void start( ); // alias for begin() & clear()
		void begin( );
		void end( );
		void clear( );

		void text( utils::vec2 pos, const wchar_t* text, ID2D1SolidColorBrush* color = colors::m_white_color, IDWriteTextFormat* font = fonts::m_consolas_font );

		void shutdown( );
	}

	utils::e_status init( );
	utils::e_status shutdown( );
}