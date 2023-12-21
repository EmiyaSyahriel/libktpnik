/**
 * ktpnik - KTP NIK Parsing Library
 * @author EmiyaSyahriel 
 */

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

/** Data Structure of a KTP NIK */
struct ktpnik_t {
	struct location_t {
		/** Registration Province */
		uint8_t province;
		/** Registration City or Regency */
		uint8_t city;
		/** Registration Region */
		uint8_t region;
	} location;
	/** Is Resident a Female? */
	uint8_t is_female;
	struct birthday_t {
		/** Birthday Date */
		uint8_t date;
		/** Birthday Month */
		uint8_t month;
		/** Birthday 2-digit Year */
		uint8_t year;
	} birthday;
	/** Person Unique ID */
	uint16_t person_unique_id;
};

enum ktpnik_result {
	/** No Error */
	KTPNIK_SUCCESS = 0x00000000,
	/**  Given NIK has less than required data */
	KTPNIK_ERROR_INSUFFICIENT_DATA = 0x86200001,
	/** Given NIK is contains invalid date, 
	 *
	 * > Note: that this only use simple check, treats that all
	 * > months has 31 days and all years has 12 months 
	*/ 
	KTPNIK_ERROR_INVALID_DATE = 0x86200002
};

/**
 * Parse NIK Number to [KtpNik]
 * @param nik - Source KTP NIK
 * @param retval - Reference to a NIK Structure
 * @returns Error type, [KTPNIK_SUCCESS] if success
 */
KTPNIK_LIB enum ktpnik_result ktpnik_parse(uint64_t nik, struct ktpnik_t* ktp_nik);