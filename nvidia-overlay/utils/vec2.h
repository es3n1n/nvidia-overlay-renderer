#pragma once
#include <cstdint>


namespace utils {
	struct vec2 {
		uint32_t x, y;

		vec2( uint32_t x, uint32_t y ) : x( x ), y( y ) { }

		D2D1_RECT_F rect( ) {
			return D2D1::RectF( static_cast< FLOAT >( x ), static_cast< FLOAT >( y ), static_cast< FLOAT >( INT_MAX ), static_cast< FLOAT >( INT_MAX ) );
		}
	};
}
