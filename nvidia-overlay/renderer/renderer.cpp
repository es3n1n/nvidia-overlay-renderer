#include "renderer.h"


namespace renderer {
	utils::e_status init( ) {
		TRACE_FN;

		L_ASSERT( internal::init( ), "failed to init internal render stuff" );

		return utils::e_status::status_ok;
	}

	utils::e_status shutdown( ) {
		TRACE_FN;

		scene::shutdown( );
		L_ASSERT( internal::shutdown( ), "failed to shutdown internal render stuff" );
		L_ASSERT( colors::shutdown( ), "failed to shutdown colors" );
		L_ASSERT( fonts::shutdown( ), "failed to shutdown colors" );

		return utils::e_status::status_ok;
	}
}
