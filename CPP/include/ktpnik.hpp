#pragma once
#include <cstdint>

#ifdef BUILD_SHARED_LIB
#ifdef WIN32
	#ifdef KTPNIK_BUILD_LIB
		#define KTPNIK_LIB __declspec(dllexport)
	#else
		#define KTPNIK_LIB __declspec(dllimport)
	#endif
#elif __unix__
	#ifdef KTPNIK_BUILD_LIB
		#define KTPNIK_LIB
	#else
		#define KTPNIK_LIB extern
	#endif
#else
	#define KTPNIK_LIB extern
#endif
#else
#define KTPNIK_LIB 
#endif

namespace ktpnik {

	KTPNIK_LIB enum class result {
		/* Success */
		success				= 0x00000000,
		/* Insufficient Data */
		insufficient_data	= 0x86200001,
		/* Invalid Date */
		invalid_date		= 0x86200002
	};

	/* KTP NIK Data */
	KTPNIK_LIB class ktpnik {
	public:
		struct {
			/* Registration Province */
			uint8_t province;
			/* Registration City or Regency */
			uint8_t city;
			/* Registration Region */
			uint8_t region;
		} location;
		/* Is Resident a Female? */
		uint8_t is_female;
		struct {
			/* Birthday Date */
			uint8_t date;
			/* Birthday Month */
			uint8_t month;
			/* Birthday 2-digit Year */
			uint8_t year;
		} birthday;
		/* Person Unique ID */
		uint16_t person_unique_id;

		/* Parse NIK into this structure */
		result parse(uint64_t nik);
	};

}