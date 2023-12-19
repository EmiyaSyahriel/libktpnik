use std::fmt;

pub struct NikType {
    pub province : u8 ,
    pub city : u8,
    pub region : u8,
    pub is_female : bool,
    pub birthdate : u8,
    pub birthmonth : u8,
    pub birthyear : u8,
    pub uid : u16
}

#[derive(Debug, Clone, Copy)]
pub enum KtpNikError {
    Success = 0x00000000,
    InsufficientData = 0x86200001,
    InvalidDate = 0x86200002
}

const MIN_NIK_INFO : u64 = 1101010101000001;

pub fn parse(nik: u64, retval: &mut NikType) -> KtpNikError {
    if nik < MIN_NIK_INFO {
        return KtpNikError::InsufficientData;
    }

    retval.province =   ((nik / 100000000000000) % 100) as u8;
    retval.city =       ((nik / 1000000000000) % 100) as u8;
    retval.region =     ((nik / 10000000000) % 100) as u8;
    retval.birthdate =  ((nik / 100000000) % 100) as u8;
    retval.is_female = retval.birthdate > 40;
    if(retval.is_female){
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
    fn fmt(&self, f : &mut fmt::Formatter) -> fmt::Result {
        match self {
            KtpNikError::Success => write!(f, "Success"),
            KtpNikError::InsufficientData => write!(f, "Insufficient Data"),
            KtpNikError::InvalidDate => write!(f, "Invalid Date"),
        }
    }
}

impl Default for NikType {
    fn default() -> NikType{
        NikType {
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