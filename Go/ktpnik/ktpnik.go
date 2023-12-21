package ktpnik

import "errors"

type KtpNik struct {
	Province   uint8
	City       uint8
	Region     uint8
	IsFemale   bool
	BirthDate  uint8
	BirthMonth uint8
	BirthYear  uint8
	Uid        uint16
}

const KTPNIK_MIN_VALUE uint64 = 1101010101000001

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
