#include <ktpnik.hpp>
#include <iostream>

int main(int argc, const char** argv) {
	const uint64_t nik = 3902136410016213;
	ktpnik::result result = ktpnik::result::success;
	ktpnik::ktpnik data = {};

	if ((result = data.parse(nik)) != ktpnik::result::success) {
		std::cout << "Error: " << (int)result << std::endl;
		return (int)result;
	}

	std::cout << "NIK: "         << (uint64_t)nik << std::endl;
	std::cout << "Provinsi: "    << (int)data.location.province << std::endl;
	std::cout << "Kota/Kab: "    << (int)data.location.city << std::endl;
	std::cout << "Kecamatan: "   << (int)data.location.region << std::endl;
	std::cout << "J Kelamin: "   << (data.is_female ? "Perempuan" : "Laki-Laki") << std::endl;
	std::cout << "Ulang Tahun: " << (int)data.birthday.date << '/' << (int)data.birthday.month << '/' << (int)data.birthday.year << std::endl;
	std::cout << "Indeks: "      << (short)data.person_unique_id << std::endl;

	return 0;
}