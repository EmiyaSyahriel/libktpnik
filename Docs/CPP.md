## Linking
### With project
```cmake
add_subdirectory(third_party/ktpnik/CPP)

target_link_libraries(target_name PRIVATE ktpnik)
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
```c++
#include <ktpnik.hpp>
```

## Methods
### `ktpnik::result ktpnik::ktpnik::parse(uint64_t nik)`
#### Argument
- `uint64_t nik` - Source NIK
#### Return Value
`enum class ktpnik::result` - Similar to HRESULT
- `ktpnik::result::success` - No Error
- `ktpnik::result::insufficient_data` - NIK value is insufficient
- `ktpnik::result::invalid_date` - Date were out of a normal range

## Classes
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