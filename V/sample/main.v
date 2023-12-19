module main
import ktpnik

const smp_nik_info = u64(3502136410016213)

fn main() {
	mut ktp := ktpnik.KtpNik {}
	err := ktpnik.parse(smp_nik_info, mut &ktp)
	if err != ktpnik.KtpNikError.success {
		println("Error parsing NIK ${smp_nik_info} : ${err}");
		exit(i32(err))
	}

	println("NIK ${smp_nik_info}, City : ${ktp.city}, Female : ${ktp.is_female}, UID : ${ktp.uid}")
}
