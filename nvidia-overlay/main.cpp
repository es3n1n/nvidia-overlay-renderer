#ifdef _DEBUG
#define LOG_DEBUG_MESSAGES
#endif

#include "scene.h"


utils::e_status init( ) {
	TRACE_FN;

	L_ASSERT( overlay::init( ), "failed to initialize overlay" );
	logger::info( "Initialized overlay" );

	L_ASSERT( renderer::init( ), "failed to initialize renderer" );
	logger::info( "Initialized renderer" );

	return utils::e_status::status_ok;
}


utils::e_status shutdown( ) {
	TRACE_FN;

	L_ASSERT( renderer::shutdown( ), "failed to shut down renderer" );
	logger::info( "Shut down renderer" );

	return utils::e_status::status_ok;
}


int main( ) {
	TRACE_FN;

	if ( !init( ) ) return -1;
	if ( !show_scene( ) ) return -1;
	if ( !shutdown( ) ) return -1;

	return 0;
}