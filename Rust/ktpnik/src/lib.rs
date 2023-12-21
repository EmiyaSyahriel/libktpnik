/////////////////
/// # ktpnik - KTP NIK Parsing Library
/// Author : EmiyaSyahriel
/// 
/////////////////

use std::fmt;


/// Data Structure of a KTP NIK
pub struct KtpNik {
	/// Registration Province
    pub province : u8 ,
	/// Registration City or Regency
    pub city : u8,
	/// Registration Region
    pub region : u8,
	/// Is Resident a Female?
    pub is_female : bool,
	/// Birthday Date
    pub birthdate : u8,
	/// Birthday Month
    pub birthmonth : u8,
	/// Birthday 2-digit Year
    pub birthyear : u8,
	/// Person Unique ID
    pub uid : u16
}


/// Errors that might returned by [parse]
#[derive(Debug, Clone, Copy)]
pub enum KtpNikError {
	/// No Error
    Success = 0x00000000,
	///  Given NIK has less than required data
    InsufficientData = 0x86200001,
	/// Given NIK is contains invalid date, 
	/// > Note: that this only use simple check, treats that all
	/// > months has 31 days and all years has 12 months
    InvalidDate = 0x86200002
}

const MIN_NIK_INFO : u64 = 1101010101000001;


/// Parse NIK Number to [KtpNik]
/// # Arguments
/// * `nik` - Source KTP NIK
/// * `retval` - Reference to a NIK Structure
/// # Returns 
/// Error type, [KtpNikError::Success] if success
pub fn parse(nik: u64, retval: &mut KtpNik) -> KtpNikError {
    if nik < MIN_NIK_INFO {
        return KtpNikError::InsufficientData;
    }

    retval.province =   ((nik / 100000000000000) % 100) as u8;
    retval.city =       ((nik / 1000000000000) % 100) as u8;
    retval.region =     ((nik / 10000000000) % 100) as u8;
    retval.birthdate =  ((nik / 100000000) % 100) as u8;
    retval.is_female = retval.birthdate > 40;
    if retval.is_female {
        retval.birthdate -= 40;
    }
    retval.birthmonth = ((nik / 1000000) % 100) as u8;
    retval.birthyear =  ((nik / 10000) % 100) as u8;
    retval.uid = (nik % 10000) as u16;

    if retval.birthdate > 31 || retval.birthmonth > 12 {
        return KtpNikError::InvalidDate;
    }

    return KtpNikError::Success;
}

impl fmt::Display for KtpNikError {
	/// String formatter for [KtpNikError]
    fn fmt(&self, f : &mut fmt::Formatter) -> fmt::Result {
        match self {
            KtpNikError::Success => write!(f, "Success"),
            KtpNikError::InsufficientData => write!(f, "Insufficient Data"),
            KtpNikError::InvalidDate => write!(f, "Invalid Date"),
        }
    }
}

impl Default for KtpNik {
	/// Default Values for [KtpNik]
    fn default() -> KtpNik{
        KtpNik {
            province : 0,
            city : 0,
            region : 0,
            is_female : false,
            birthdate : 0,
            birthmonth : 0,
            birthyear : 0,
            uid : 0   
        }
    }
}