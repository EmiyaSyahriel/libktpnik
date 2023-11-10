# libktpnik
Multilingual library to parse KTP NIK (Indonesian Resident Identification Number)

## Warning : KEEP YOUR NIK AWAY FROM INTERNET! YOU ARE A POTENTIAL PREY TO ROGUE JUDOL AND PINJOL USERS! YOU DO NOT WANT TO BE BLACKMAILED, RIGHT!?

## How it Works
Based on [Disdukcapil NIK Format (Indonesian)](https://dispenduk.mojokertokota.go.id/home/berita/Arti-kode-angka-dalam-NIK-E-KTP), NIK consists of multiple data concatenated together at this format:
> `AABBCCDDEEFFXXXX` = `AA-BB-CC-DD-EE-FF-XXXX`
- `AA` - Registration Province
- `BB` - Registration City / Regency
- `CC` - Registration Region
- `DD` - Birthday Date (+40 if Resident is Woman)
- `EE` - Birthday Month
- `FF` - Birthday Year (2-Digit)
- `XXXX` - Person Unique ID (Incremental Index of person with same location and 2-digit year birthday)

### Sample
> `3502026410010013` - `35-02-02-64-10-01-0013`
- `35` = East Java
- `02` = Ponorogo Regency
- `02` = Ngrayun Region
- `64` = Female - Born 24
- `10` = October
- `01` = Year 01, Either 1901, 2001 or 2101.
- `0013` = 13th Registered Person with same Birthday and Registration Location.

## Library usages :
Please refer to the docs

## License
CC-BY 4.0 - Public Domain, anyone can use in any form as long any kind of attribution is given.