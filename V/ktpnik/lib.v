module ktpnik

pub struct KtpNik {
pub mut:
    province u8
    city u8
    region u8
    is_female bool
    birthdate u8
    birthmonth u8
    birthyear u8
    uid u16
}

pub enum KtpNikError as u32 {
    success 		 	= 0x00000000
    insufficient_data	= 0x86200001
    invalid_date		= 0x86200002
}

const min_nik_info := u64(1101010101000001)

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
