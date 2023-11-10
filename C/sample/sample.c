#include <ktpnik.h>
#include <stdio.h>

int main(int argc, const char* argv[])
{
	struct ktpnik_t data;
	const uint64_t nik = 3902136410010013;
	enum ktpnik_result result = ktpnik_parse(nik, &data);
	
	if(result != KTPNIK_SUCCESS){
		printf("Error 0x%08X\n", result);
		
	}
	
	printf("NIK : %llu\n", nik);
	
	printf("Provinsi: %d\n", data.location.province);
	printf("Kota/Kab: %d\n", data.location.city);
	printf("Kecamatan: %d\n", data.location.region);
	
	printf("Jenis Kelamin : %s\n", data.is_female ? "Perempuan" : "Laki-Laki");
	
	printf("Ulang Tahun : %02d/%02d/%02d\n", data.birthday.date, data.birthday.month, data.birthday.year);
	
	printf("Indeks Registrasi Kecamatan : %04d\n", data.person_unique_id);
	
	return 0;
}