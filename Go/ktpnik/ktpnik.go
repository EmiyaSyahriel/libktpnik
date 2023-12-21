// ktpnik - KTP NIK Parsing Library
//
// Author : EmiyaSyahriel
package ktpnik

import "errors"

// Data Structure of a KTP NIK
type KtpNik struct {
	Province   uint8 	// Registration Province
	City       uint8 	// Registration City or Regency
	Region     uint8	// Registration Region
	IsFemale   bool		// Is Resident a Female?
	BirthDate  uint8	// Birthday Date
	BirthMonth uint8	// Birthday Month
	BirthYear  uint8	// Birthday 2-digit Year
	Uid        uint16	// Person Unique ID
}

// Minimum value of an KTP NIK, or else insufficient data error will be returned
const KTPNIK_MIN_VALUE uint64 = 1101010101000001

// Parse NIK Number to KtpNik
//
// with nik being the Source KTP NIK and retval is a Reference to 
// returned NIK Structure.
func Parse(nik uint64, retval *KtpNik) error {
	if nik < KTPNIK_MIN_VALUE {
		return errors.New("Insufficient data")
	}

	retval.Province = uint8((nik / 100000000000000) % 100)
	retval.City = uint8((nik / 1000000000000) % 100)
	retval.Region = uint8((nik / 10000000000) % 100)
	retval.BirthDate = uint8((nik / 100000000) % 100)
	retval.IsFemale = retval.BirthDate > 40
	if retval.IsFemale {
		retval.BirthDate -= 40
	}
	retval.BirthMonth = uint8((nik / 1000000) % 100)
	retval.BirthYear = uint8((nik / 10000) % 100)
	retval.Uid = uint16(nik % 10000)

	if retval.BirthDate > 31 || retval.BirthMonth > 12 {
		return errors.New("Invalid date")
	}

	return nil
}
