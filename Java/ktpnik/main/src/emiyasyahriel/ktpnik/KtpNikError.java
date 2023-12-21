package emiyasyahriel.ktpnik;
/**
 * ktpnik - KTP NIK Parsing Library
 * Author : EmiyaSyahriel
 */

/**
 * Errors that might returned by <see cref="KtpNik.Parse(ulong, ref KtpNik)"/>
 */
public enum KtpNikError {
    
    /** No Error */
    Success,
    /** Given NIK has less than required data */
    InsufficientData,
        /** Given NIK is contains invalid date
         * 
         * @remarks Note: that this only use simple check, treats that all, 
         *          months has 31 days and all years has 12 months
        */
    InvalidDate
}
