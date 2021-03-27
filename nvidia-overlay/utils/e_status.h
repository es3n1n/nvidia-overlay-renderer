#pragma once


namespace utils {
	enum class e_status : int {
		status_ok = 0,
		status_failed
	};

	inline bool operator! ( e_status e ) {
		return e == e_status::status_failed;
	}
}
