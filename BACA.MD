# libktpnik
Pustaka multibahasa untuk mengurai NIK KTP

## Warning
<h2>
JANGAN SAMPAI NIK ASLI KAMU KESEBAR! BISA DIPAKE SAMA ORANG YANG GAK BERTANGGUNG-JAWAB
BUAT DAFTAR PINJOL YANG NANTI DIPAKE BUAT JUDOL! GAK MAU KAN DIKEJAR-KEJAR DEBT COLLECTOR
PADAHAL KAMU GAK NGUTANG!?
</h2>

## Kenapa Dibuat?
Keperluan Edukasi, termasuk untuk saya sendiri. Untuk belajar bahasa pemrograman, logika dan toolchainnya.
Diluar itu, saya cukup yakin kalau jarang yang bakal pake library-nya sendiri untuk fungsinya.

## Berkontribusi
Kalian bebas membuat kontribusi ke repo ini selama kalian terima kalau kode yang kalian berikan kemari
berada dibawah lisensi CC-BY-4.0

Ngomong-ngomong, Kalau ada kesalahan dalam kode, kalian boleh membetulkannya dan mengkotribusikannya ke
repo ini, Saya lebih sering hanya menggunakan compiler dan tidak menggunakan build system secara penuh di
beberapa bahasa yang baru saya pelajari. Jadi tegur aja kalau saya sok tau~

## Cara kerja
Berdasarkan [Format NIK dari Disdukcapil](https://dispenduk.mojokertokota.go.id/home/berita/Arti-kode-angka-dalam-NIK-E-KTP), 
Angka NIK tersusun dalam bentuk:
> `AABBCCDDEEFFXXXX` = `AA-BB-CC-DD-EE-FF-XXXX`
- `AA` - Provinsi Disdukcapil Pendaftaran
- `BB` - Kota / Kabupaten Pendaftaran
- `CC` - Kecamatan Pendaftaran
- `DD` - Tanggal Lahir (+40 Untuk Perempuan)
- `EE` - Bulan Lahir
- `FF` - Tahun Lahir (2-Angka)
- `XXXX` - Angka Unik Pendaftar (Naik satu untuk tiap orang yang mendaftar di lokasi dengan tanggal lahir yang sama)

### Contoh (Fiksi)
> `3502027102019913` - `35-02-02-71-02-01-9913`
- `35` = Jawa Timur
- `02` = Kab. Ponorogo
- `02` = Kec. Ngrayun
- `71` = Perempuan - Lahir 31
- `02` = Februari
- `01` = Tahun XX01, Bisa 1901, 2001, 2101 atau seterusnya.
- `9913` = Orang ke 9913 yang mendaftar ditempat yang sama dengan tanggal lahir yang sama

## Penggunaan
Cek direktori Docs

## Lisensi
CC-BY 4.0 - Domain Publik - Atribusi, semua orang bebas memakai dalam bentuk apapun selama mencantumkan nama pembuat.