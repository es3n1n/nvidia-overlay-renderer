#include "logger.h"


namespace logger {
	namespace _colors {
		void* m_console_handle = nullptr;

		bool ensure_handle( ) {
			if ( !m_console_handle )
				m_console_handle = GetStdHandle( STD_OUTPUT_HANDLE );
			return static_cast< bool >( m_console_handle );
		}

		void apply( uint32_t clr ) {
			if ( !ensure_handle( ) ) return;
			SetConsoleTextAttribute( m_console_handle, clr );
		}

		void reset( ) {
			apply( static_cast< uint32_t >( e_level_color::level_color_none ) );
		}
	}

	void log( const char* prefix, e_level_color level, const char* message ) {
		_colors::apply( static_cast< uint32_t >( level ) );
		printf( "%s >> ", prefix );
		_colors::reset( );

		printf( "%s\n", message );
	}
}