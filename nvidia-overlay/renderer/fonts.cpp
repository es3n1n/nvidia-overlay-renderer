#include "renderer.h"


namespace renderer {
	namespace fonts {
		IDWriteTextFormat* m_consolas_font = nullptr;

		utils::e_status init( ) {
			TRACE_FN;

			L_ASSERT( !FAILED(
				internal::m_factory->CreateTextFormat(
					L"Consolas", NULL,
					DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL,
					13.0,
					L"en-us",
					&m_consolas_font
				) ), "failed to create consolas font" );

			return utils::e_status::status_ok;
		}

		utils::e_status shutdown( ) {
			TRACE_FN;

			m_consolas_font->Release( );

			return utils::e_status::status_ok;
		}
	}
}