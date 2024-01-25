/**
 * ktpnik - KTP NIK Parsing Library
 * @author EmiyaSyahriel
 * @license CC-BY 4.0, see https://github.com/EmiyaSyahriel/libktpnik/blob/main/LICENSE
 *     This code is allowed to be copied into your project, but please 
 * link to the main project and show the license.
 */
module ktpnik

/**
* Data Structure of a KTP NIK
*/
pub struct KtpNik {
pub mut:
	/** Registration Province */
    province u8
	/** Registration City / Regency */
    city u8
	/** Registration Region */
    region u8
	/** Is Resident a Female */
    is_female bool
	/** Birthday Date */
    birthdate u8
	/** Birthday Month */
    birthmonth u8
	/** Birthday 2-digit Year */
    birthyear u8
	/** Person Unique ID */
    uid u16
}

/**
* Errors returned by [ktpnik.parse]
*/
pub enum KtpNikError as u32 {
	/** No Error, Success */
    success 		 	= 0x00000000
	/** Given NIK has less data */
    insufficient_data	= 0x86200001
	/** Given NIK is contains invalid date, 
	* @remarks Note that this only use simple check, treats that all
	*  months has 31 days and all years has 12 months
	*/
    invalid_date		= 0x86200002
}

const min_nik_info := u64(1101010101000001)

/**
* Parse NIK Number to [KtpNik]
* @param nik - Source KTP NIK
* @param retval - Reference to a NIK Structure
* @returns Error type, [KtpNikError.success] if success
*/
pub fn parse(nik u64, mut retval &KtpNik) KtpNikError {
    if nik < min_nik_info {
        return KtpNikError.insufficient_data
    }

	retval.province   = u8((nik / 100000000000000) % 100)
	retval.city       = u8((nik / 1000000000000) % 100)
	retval.region     = u8((nik / 10000000000) % 100)
	retval.birthdate  = u8((nik / 100000000) % 100)
	retval.birthmonth = u8((nik / 1000000) % 100)
	retval.birthyear  = u8((nik / 10000) % 100)
	retval.uid        = u16((nik / 1) % 10000)
	retval.is_female  = retval.birthdate > 40
	if retval.is_female {
		retval.birthdate -= 40
	}

    if retval.birthdate > 31 || retval.birthmonth > 12 {
        return KtpNikError.invalid_date
    }

	return KtpNikError.success
}
