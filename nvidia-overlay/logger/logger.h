#pragma once
#include <cstdint>
#include <stdio.h>
#include <Windows.h>
#include "../utils/e_status.h"


#define L_ERROR(txt) logger::error("%s(): %s", __FUNCTION__, txt); return utils::e_status::status_failed;
#define L_ASSERT(cond, txt) if (!cond) { L_ERROR(txt); }
#define TRACE_FN logger::debug( "%s()", __FUNCTION__ );

#define CREATE_LOGGER_METHOD(n) inline void n(const char* fmt, ...) { char buf[1024]; va_list va; va_start( va, fmt ); _vsnprintf_s( buf, 1024, fmt, va ); va_end( va ); log( #n, e_level_color::level_color_ ##n, buf ); }


namespace logger {
	enum class e_level_color : uint32_t {
		level_color_none = 15, // black bg and white fg
		level_color_debug = 8,
		level_color_info = 10,
		level_color_warn = 14,
		level_color_error = 12
	};

	namespace _colors {
		extern void* m_console_handle;

		bool ensure_handle( );
		void apply( uint32_t clr );
		void reset( );
	}

	void log( const char* prefix, e_level_color level, const char* message );

#ifdef LOG_DEBUG_MESSAGES
	CREATE_LOGGER_METHOD( debug );
#else
	inline void debug( const char* fmt, ... ) { }
#endif

	CREATE_LOGGER_METHOD( info );
	CREATE_LOGGER_METHOD( warn );
	CREATE_LOGGER_METHOD( error );
}

#undef CREATE_LOGGER_METHOD
