#include "renderer.h"

namespace renderer {
	namespace colors {
		ID2D1SolidColorBrush* m_white_color = nullptr;
		ID2D1SolidColorBrush* m_red_color = nullptr;
		ID2D1SolidColorBrush* m_green_color = nullptr;
		ID2D1SolidColorBrush* m_blue_color = nullptr;
		ID2D1SolidColorBrush* m_black_color = nullptr;

		utils::e_status init( ) {
			TRACE_FN;

			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( D2D1::ColorF::White ), &m_white_color );
			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( D2D1::ColorF::Red ), &m_red_color );
			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( D2D1::ColorF::Green ), &m_green_color );
			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( D2D1::ColorF::Blue ), &m_blue_color );
			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( D2D1::ColorF::Black ), &m_black_color );

			return utils::e_status::status_ok;
		}

		utils::e_status shutdown( ) {
			TRACE_FN;

			m_white_color->Release( );
			m_red_color->Release( );
			m_green_color->Release( );
			m_blue_color->Release( );
			m_black_color->Release( );

			return utils::e_status::status_ok;
		}
	}
}
