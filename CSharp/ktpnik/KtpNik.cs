/**
 * ktpnik - KTP NIK Parsing Library
 * Author : EmiyaSyahriel
 */

namespace EmiyaSyahriel.KtpNik
{
    /// <summary>
    /// Data Structure of a KTP NIK
    /// </summary>
    public struct KtpNik
    {
        public byte province;
        public byte city;
        public byte region;
        public bool isFemale;
        public byte birthDate;
        public byte birthMonth;
        public byte birthYear;
        public ushort uid;

        private const ulong MIN_NIK_INFO = 1101010101000001UL;

        /// <summary>
        /// Parse NIK Number to <see cref="KtpNik"/>
        /// </summary>
        /// <param name="nik">Source KTP NIK</param>
        /// <param name="retval">Reference to a NIK Structure</param>
        /// <returns>Error Type, <see cref="KtpNikError.Success"> if success</returns>
        public static KtpNikError Parse(ulong nik, ref KtpNik retval)
        {
            if (nik < MIN_NIK_INFO)
            {
                return KtpNikError.InsufficientData;
            }

            retval.province = (byte)((nik / 100000000000000) % 100);
            retval.city = (byte)((nik / 1000000000000) % 100);
            retval.region = (byte)((nik / 10000000000) % 100);
            retval.birthDate = (byte)((nik / 100000000) % 100);
            retval.isFemale = retval.birthDate > 40;
            if (retval.isFemale)
            {
                retval.birthDate -= 40;
            }
            retval.birthMonth = (byte)((nik / 1000000) % 100);
            retval.birthYear = (byte)((nik / 10000) % 100);
            retval.uid = (ushort)(nik % 10000);

            if (retval.birthDate > 31 || retval.birthMonth > 12)
            {
                return KtpNikError.InvalidDate;
            }

            return KtpNikError.Success;
        }
    }
}