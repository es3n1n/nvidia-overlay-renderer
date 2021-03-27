#include "renderer.h"


namespace renderer {
	namespace scene {
		void start( ) {
			begin( );
			clear( );
		}

		void begin( ) {
			internal::m_render_target->BeginDraw( );
		}

		void end( ) {
			internal::m_render_target->EndDraw( );
		}

		void clear( ) {
			internal::m_render_target->Clear( );
		}

		void text( utils::vec2 pos, const wchar_t* text, ID2D1SolidColorBrush* color, IDWriteTextFormat* font ) {
			internal::m_render_target->DrawTextW( text, lstrlenW( text ), font, pos.rect( ), color, D2D1_DRAW_TEXT_OPTIONS_NONE, DWRITE_MEASURING_MODE_NATURAL );
		}

		void shutdown( ) {
			begin( );
			clear( );
			end( );
		}
	}
}