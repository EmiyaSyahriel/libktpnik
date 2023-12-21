/**
 * ktpnik - KTP NIK Parsing Library
 * Author : EmiyaSyahriel
 */

namespace EmiyaSyahriel.KtpNik {
    /// <summary>
    /// Errors that might returned by <see cref="KtpNik.Parse(ulong, ref KtpNik)"/>
    /// </summary>
    public enum KtpNikError
    {
        /// <summary> No Error </summary>
        Success,
        /// <summary> Given NIK has less than required data </summary>
        InsufficientData,
        /// <summary> Given NIK is contains invalid date </summary>
        /// <remarks>
        /// Note: that this only use simple check, treats that all, 
        /// months has 31 days and all years has 12 months
        /// </remarks>
        InvalidDate
    }
}