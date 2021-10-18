#pragma once

#include <iostream>
#include <cassert>

namespace hash {
	template <typename S> struct fnv1;

	template <> struct fnv1<uint32_t> {
		constexpr static inline uint32_t hash( char const* const aString, const uint32_t val = 0x811C9DC5 ) {
			return ( aString[ 0 ] == '\0' ) ? val : hash( &aString[ 1 ], ( val * 0x01000193 ) ^ uint32_t( aString[ 0 ] ) );
		}
	};
} // namespace hash
