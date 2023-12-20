/**
 * ktpnik.js - Author : EmiyaSyahriel
 * Licensed in CC-BY-4.0, see https://github.com/EmiyaSyahriel/libktpnik/blob/main/LICENSE
*/

const KTPNIK_SUCCESS = 0x0
const KTPNIK_ERR_INSUFFICIENT_DATA = 0x86200001
const KTPNIK_ERR_INVALID_DATE = 0x86200002

/**
 * Parse KTP nik
 * @param {Number} nik - Indonesian KTP NIK Number
 * @param {any} retval - Actual returned object reference (no null)
 * @returns error_code
 */
const ktpnik_parse = (nik, retval) => {
	const MIN_NIK_INFO = 1101010101000001
	
	if(nik < MIN_NIK_INFO) return KTPNIK_ERR_INSUFFICIENT_DATA
	
	retval.province   = Math.floor((nik / 100000000000000) % 100)
	retval.city       = Math.floor((nik / 1000000000000) % 100)
	retval.region     = Math.floor((nik / 10000000000) % 100)
	retval.birthdate  = Math.floor((nik / 100000000) % 100)
	retval.birthmonth = Math.floor((nik / 1000000) % 100)
	retval.birthyear  = Math.floor((nik / 10000) % 100)
	retval.uid        = Math.floor((nik / 1) % 10000)
	retval.is_female  = retval.birthdate > 40
	
	if(retval.is_female) {
		retval.birthdate -= 40
	}
	
	if(retval.birthdate > 31 || retval.birthmonth > 12){
		return KTPNIK_ERR_INVALID_DATE
	}
	
	return KTPNIK_SUCCESS
}