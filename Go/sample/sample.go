// ktpnik/sample - KTP NIK Parsing Library Sample
//
// Author : EmiyaSyahriel
package main

import (
	"fmt"
	"libktpnik/ktpnik"
	"os"
)

const SMP_NIK_INFO uint64 = 3502136410016213

func main() {
	var k ktpnik.KtpNik = ktpnik.KtpNik{}
	err := ktpnik.Parse(SMP_NIK_INFO, &k)
	if err != nil {
		fmt.Printf("Error : %s", err.Error())
		os.Exit(1)
	}

	fmt.Printf("Source NIK: %d\nCity : %02d\nIs Female : %v\nUID : %04d", SMP_NIK_INFO, k.City, k.IsFemale, k.Uid)
}
