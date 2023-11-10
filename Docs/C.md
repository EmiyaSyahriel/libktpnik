## Linking
### With project
```cmake
add_subdirectory(third_party/ktpnik/C)

target_link_libraries()
```
To build, with static link (command line) :
```bash
cmake ... -DKTPNIK_STATIC_LIB=ON ...
```

### Prebuild
```cmake
# Assuming you have ktpnik library in your PATH either static or shared library
target_link_libraries(target_name PRIVATE ktpnik)
```

## Usage
### Include Header in source
```c
#include <ktpnik.h>
```

## Methods
### `enum ktpnik_result ktpnik_parse(uint64_t nik, struct ktpnik_t* result)`
#### Argument
- `uint64_t nik` - Source NIK
- `struct ktpnik_t* result` - Parsed Info from NIK
#### Return Value
`enum ktpnik_result` - Similar to HRESULT
- `0x00000000` / `KTPNIK_SUCCESS` - No Error
- `0x86200001` / `KTPNIK_ERROR_INSUFFICIENT_DATA` - NIK value is insufficient
- `0x86200002` / `KTPNIK_ERROR_INVALID_DATE` - Date were out of a normal range

## Structs
### `ktpnik_t`
- `struct location_t location` - Registration Location
    - `uint8_t province` - Province
    - `uint8_t city` - City
    - `uint8_t region` - Region
- `uint8_t is_female` - Registered Person Is Female
- `struct birthday_t birthday` - Birthday
    - `uint8_t date` - Date
    - `uint8_t month` - Month
    - `uint8_t year` - Year
- `uint16_t person_unique_id` - Person Unique ID with same Registration Location and Birthday