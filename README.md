# libktpnik
Multilingual library to parse KTP NIK (Indonesian Resident Identification Number)

## Warning : KEEP YOUR NIK AWAY FROM INTERNET! YOU ARE A POTENTIAL PREY TO ROGUE JUDOL AND PINJOL USERS! YOU DO NOT WANT TO BE BLACKMAILED, RIGHT!?

## How it Works
Based on [Disdukcapil Format Info (Indonesian)](https://dispenduk.mojokertokota.go.id/home/berita/Arti-kode-angka-dalam-NIK-E-KTP), NIK consists of multiple data concatenated together at this format:
> `AABBCCDDEEFFXXXX` = `AA-BB-CC-DD-EE-FF-XXXX`
- `AA` - Registration Province
- `BB` - Registration City / Regency
- `CC` - Registration Region
- `DD` - Birthday Date (+40 if Resident is Woman)
- `EE` - Birthday Month
- `FF` - Birthday Year (2-Digit)
- `XXXX` - Registration Index (Index of person with same location and birthday)

## Library usages :
Please refer to the docs

## License
CC-BY 4.0 - Public Domain, anyone can use in any form as long any kind of attribution is given.