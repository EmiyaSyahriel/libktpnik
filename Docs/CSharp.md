## Linking
```bash
# Assuming you've git cloned this repository to your (project root)/third_party
dotnet sln add "third_party/libktpnik/CSharp/ktpnik.csproj"
```

## Classes
### `EmiyaSyahriel.KtpNik.KtpNik`
#### Fields
- `byte province` - Register Province
- `byte city`- Register City
- `byte region` - Register Region
- `bool isFemale` - Is Resident Female?
- `byte birthDate` - Birth Date
- `byte birthMonth` - Birth Month
- `byte birthYear` - Birth Year
- `ushort uid` - Person Unique ID

#### Static Methods
##### `KtpNikError Parse(ulong nik, ref KtpNik retval)`
Parameters:
- `ulong nik` - Source KTP NIK
- `ref KtpNik retval` - Return value of retval
Return value
  `KtpNikError` - result of parsing
  
## Enums
### `EmiyaSyahriel.KtpNik.KtpNikError`
- `Success` - Success
- `InsufficientData` - Given NIK has less than required data
- `InvalidDate` - Given NIK is contains invalid date