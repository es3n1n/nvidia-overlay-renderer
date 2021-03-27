#pragma once
#include "renderer/renderer.h"


void draw_demo_scene( ) {
	renderer::scene::start( );

	uint32_t x = 100;
	for ( uint32_t j = 0; j < 5; j++ ) {
		uint32_t y = 150;
		for ( uint32_t i = 0; i < 70; i++ ) {
			renderer::scene::text( utils::vec2( x, y ), L"русские вперед", renderer::colors::m_white_color, renderer::fonts::m_consolas_font );
			y += 10;
		}
		x += 120;
	}

	renderer::scene::end( );
}


utils::e_status show_scene( ) {
	TRACE_FN;

	logger::info( "Press [delete] key to exit" );

	while ( !GetAsyncKeyState( VK_DELETE ) )
		draw_demo_scene( );

	return utils::e_status::status_ok;
}
