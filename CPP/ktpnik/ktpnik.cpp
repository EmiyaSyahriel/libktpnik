#include <ktpnik.hpp>

namespace ktpnik {

	#define PRIVATE __attribute__((visibility("hidden")))

	// MINIMUM DATA = Sumatera, Aceh, Kab Aceh Selatan, Kec Bakogan, Laki-Laki, 01/01/2000, Index 0001
	class constants {
	private:
		static const uint64_t MinInfo      = 1101010101000001ULL;
		static const uint64_t SampleInfo   = 3502136410016213ULL;
		static const uint64_t ProvinceDiv  = 100000000000000ULL;
		static const uint64_t CityDiv      = 1000000000000ULL;
		static const uint64_t RegionDiv    = 10000000000ULL;
		static const uint64_t DateDiv      = 100000000ULL;
		static const uint64_t MonthDiv     = 1000000ULL;
		static const uint64_t YearDiv      = 10000ULL;
		static const uint64_t RegistNumDiv = 1ULL;
		static const uint64_t HundredMax   = 100ULL;
		static const uint64_t RegistNumMax = 10000ULL;
		static const uint64_t IsFemaleFlag = 40ULL;

		template <typename T> static inline T min(T a, T b) { return a < b ? a : b; }
		template <typename T> static inline T max(T a, T b) { return a > b ? a : b; }
		template <typename T> static inline T clm(T a, T b) { return a % b; }

		friend ktpnik;
	};

	result ktpnik::parse(uint64_t nik) {
		if (nik < constants::MinInfo) return result::insufficient_data;

		this->location.province = (uint8_t)constants::clm(nik / constants::ProvinceDiv, constants::HundredMax);
		this->location.city     = (uint8_t)constants::clm(nik / constants::CityDiv,     constants::HundredMax);
		this->location.region   = (uint8_t)constants::clm(nik / constants::RegionDiv,   constants::HundredMax);

		this->birthday.date     = (uint8_t)constants::clm(nik / constants::DateDiv,  constants::HundredMax);
		this->birthday.month    = (uint8_t)constants::clm(nik / constants::MonthDiv, constants::HundredMax);
		this->birthday.year     = (uint8_t)constants::clm(nik / constants::YearDiv,  constants::HundredMax);

		if ((this->is_female = this->birthday.date > constants::IsFemaleFlag) == 1) {
			this->birthday.date -= constants::IsFemaleFlag;
		}

		this->person_unique_id = (uint16_t)constants::clm(nik / constants::RegistNumDiv, constants::RegistNumMax);

		if (this->birthday.date > 31 || this->birthday.month > 12) return result::invalid_date;

		return result::success;
	}
}