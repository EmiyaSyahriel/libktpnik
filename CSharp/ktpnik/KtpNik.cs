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
        /// <summary> Register Province </summary>
        public byte province;
        /// <summary> Register City / Regency </summary>
        public byte city;
        /// <summary> Register Region </summary>
        public byte region;
        /// <summary> Is Resident Female? </summary>
        public bool isFemale;
        /// <summary> Birth Date </summary>
        public byte birthDate;
        /// <summary> Birth Month </summary>
        public byte birthMonth;
        /// <summary> Birth Year </summary>
        public byte birthYear;
        /// <summary> Person Unique ID </summary>
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