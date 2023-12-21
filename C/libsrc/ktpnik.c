#include <ktpnik.h>

#define PRIVATE __attribute__((visibility("hidden")))

// MINIMUM DATA = Sumatera, Aceh, Kab Aceh Selatan, Kec Bakogan, Laki-Laki, 01/01/2000, Index 0001
const uint64_t const 
PRIVATE MIN_NIK_INFO =     1101010101000001ULL,
PRIVATE SMP_NIK_INFO =     3502136410016213ULL,
PRIVATE NIK_PROVINCE_DIV =  100000000000000ULL,
PRIVATE NIK_CITY_DIV =        1000000000000ULL,
PRIVATE NIK_REGION_DIV =        10000000000ULL,
PRIVATE NIK_DATE_DIV =            100000000ULL,
PRIVATE NIK_MONTH_DIV =             1000000ULL,
PRIVATE NIK_YEAR_DIV =                10000ULL,
PRIVATE NIK_REGISTNUM_DIV =               1ULL,
PRIVATE NIK_HUNDRED_MAX =                100ULL,
PRIVATE NIK_REGISTNUM_MAX =            10000ULL,
PRIVATE NIK_ISFEMALE_FLAG =              40ULL
;

#define __min(a, b) (((a) < (b)) ? (a) : (b))
#define __max(a, b) (((a) > (b)) ? (a) : (b))
#define __clm(a, b) ((a) % (b))

/**
 * Parse NIK Number to [KtpNik]
 * @param nik - Source KTP NIK
 * @param retval - Reference to a NIK Structure
 * @returns Error type, [KTPNIK_SUCCESS] if success
 */
enum ktpnik_result ktpnik_parse(uint64_t nik, struct ktpnik_t* ktp_nik){
	if(nik < MIN_NIK_INFO) return KTPNIK_ERROR_INSUFFICIENT_DATA;
	struct ktpnik_t* k = ktp_nik;
	
	k->location.province = (uint8_t)__clm(nik / NIK_PROVINCE_DIV, NIK_HUNDRED_MAX);
	k->location.city = (uint8_t)__clm(nik / NIK_CITY_DIV, NIK_HUNDRED_MAX);
	k->location.region = (uint8_t)__clm(nik / NIK_REGION_DIV, NIK_HUNDRED_MAX); 
	
	k->birthday.date = (uint8_t)__clm(nik / NIK_DATE_DIV, NIK_HUNDRED_MAX);
	k->birthday.month = (uint8_t)__clm(nik / NIK_MONTH_DIV, NIK_HUNDRED_MAX);
	k->birthday.year = (uint8_t)__clm(nik / NIK_YEAR_DIV, NIK_HUNDRED_MAX);
	
	if((k->is_female = k->birthday.date > NIK_ISFEMALE_FLAG) == 1){
		k->birthday.date -= NIK_ISFEMALE_FLAG;
	}
	
	k->person_unique_id = (uint16_t)__clm(nik / NIK_REGISTNUM_DIV, NIK_REGISTNUM_MAX);
	
	if(k->birthday.date > 31 || k->birthday.month > 12) return KTPNIK_ERROR_INVALID_DATE;
	
	return KTPNIK_SUCCESS;
}