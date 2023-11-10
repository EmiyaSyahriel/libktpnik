#include <stdint.h>
#ifdef BUILD_SHARED_LIB
#ifdef WIN32
	#ifded KTPNIK_BUILD_LIB
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

struct ktpnik_t {
	struct location_t {
		uint8_t province;
		uint8_t city;
		uint8_t region;
	} location;
	uint8_t is_female;
	struct birthday_t {
		uint8_t date;
		uint8_t month;
		uint8_t year;
	} birthday;
	uint16_t person_unique_id;
};

enum ktpnik_result {
	KTPNIK_SUCCESS = 0x00000000,
	KTPNIK_ERROR_INSUFFICIENT_DATA = 0x86200001,
	KTPNIK_ERROR_INVALID_DATE = 0x86200002
};

KTPNIK_LIB enum ktpnik_result ktpnik_parse(uint64_t nik, struct ktpnik_t* ktp_nik);