# libktpnik
[Baca dalam Bahasa Indonesia](BACA.MD)

Multilingual library to parse KTP NIK (Indonesian Resident Identification Number)

> [!CAUTION]
> KEEP YOUR REAL NIK AWAY FROM INTERNET! IT CAN BE USED BY IRRESPONSIBLE PEOPLE TO REGISTER AND MAKE A
> LOAN ON AN UNLICENSED ONLINE LOAN FOR USE ON ONLINE GAMBLING! YOU DO NOT WANT TO BE CHASED BY 
> LOAN SHARK EVEN THOUGH YOU DID NOT MAKE ANY LOAN YOURSELF, DON'T YOU!

## Why I made this?
For Educational Purpose, including myself, to learn programming languages, logics and toolchains. 
I am confident enough that this library by itself is not that useful usage-wise.

## Contributing
You are free to contribute to this repository as long as you are accepting that the code you contribute
here is under CC-BY-4.0.

By the way, If there is a mistake in the code. You are allowed to fix it! Since I am mostly using compiler-only and not
the full build system on new languages. Just tell me if I'm making a mistake.

## How it Works
Based on [Disdukcapil NIK Format (Indonesian)](https://dispenduk.mojokertokota.go.id/home/berita/Arti-kode-angka-dalam-NIK-E-KTP), 
NIK consists of multiple data concatenated together at this format:
> `AABBCCDDEEFFXXXX` = `AA-BB-CC-DD-EE-FF-XXXX`
- `AA` - Registration Province
- `BB` - Registration City / Regency
- `CC` - Registration Region
- `DD` - Birthday Date (+40 if Resident is Woman)
- `EE` - Birthday Month
- `FF` - Birthday Year (2-Digit)
- `XXXX` - Person Unique ID (Incremental Index of person with same location and 2-digit year birthday)

### Sample (Fictional)
> `3502027102019913` - `35-02-02-71-02-01-9913`
- `35` = East Java
- `02` = Ponorogo Regency
- `02` = Ngrayun Region
- `71` = Female - Born 31
- `02` = February
- `01` = Year 01, Either 1901, 2001 or 2101.
- `9913` = 9913th Registered Person with same Birthday and Registration Location.

## Library usages
Please refer to the docs

## License
CC-BY 4.0 - Public Domain - Attribution, anyone can use in any form as long any kind of attribution is given.