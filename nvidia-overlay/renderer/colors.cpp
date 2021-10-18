#include "renderer.h"

namespace renderer {
	namespace colors {
		ID2D1SolidColorBrush* get( uint32_t col ) {
			if ( _colors.find( col ) != _colors.end( ) )
				return _colors.at( col );
			_colors[ col ] = NULL;
			internal::m_render_target->CreateSolidColorBrush( D2D1::ColorF( col ), &_colors.at( col ) );
			return ::renderer::colors::get( col );
		}

		utils::e_status shutdown( ) {
			TRACE_FN;

			for ( auto&& p : _colors )
				p.second->Release( );  // @note: es3n1n: why would i care, nullptr here is an unexpected behavior!

			return utils::e_status::status_ok;
		}
	}
}
