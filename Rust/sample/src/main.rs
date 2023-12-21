/////////////////
/// # ktpnik_sample - KTP NIK Parsing Library Sample
/// Author : EmiyaSyahriel
/// 
/////////////////

extern crate ktpnik;

use std::fmt::Result;
use ktpnik::{KtpNik, KtpNikError};


const SMP_NIK_INFO : u64 = 3502136410016213;

fn main() -> Result {
    let mut ktp = KtpNik { ..Default::default() };
    let parse_err = ktpnik::parse(SMP_NIK_INFO, &mut ktp);
    if matches!(parse_err, KtpNikError::Success)
    {
        println!("Parse Error {} (parsing NIK {})", parse_err.to_string(), SMP_NIK_INFO);
        std::process::exit(1);
    }

    println!("NIK : {}, City : {}, Is Female : {}, UID : {}", SMP_NIK_INFO, ktp.city, ktp.is_female, ktp.uid);

    return Result::Ok(());
}