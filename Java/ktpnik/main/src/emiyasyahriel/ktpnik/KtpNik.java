package emiyasyahriel.ktpnik;
/**
 * ktpnik - KTP NIK Parsing Library
 * Author : EmiyaSyahriel
 */

import java.math.BigInteger;

/**
 * Data Structure of a KTP NIK
 */
public class KtpNik {
    
    /** Register Province */ 
    public byte province;
    /** Register City / Regency */
    public byte city;
    /** Register Region */
    public byte region;
    /** Is Resident Female? */
    public Boolean isFemale;
    /** Birth Date */
    public byte birthDate;
    /** Birth Month */
    public byte birthMonth;
    /** Birth Year */
    public byte birthYear;
    /** Person Unique ID */
    public short uid;

    private static BigInteger MIN_NIK_INFO = new BigInteger("1101010101000001");

    private static BigInteger NIK_PROVINCE_DIV =  new BigInteger("100000000000000");
    private static BigInteger NIK_CITY_DIV =      new BigInteger("1000000000000");
    private static BigInteger NIK_REGION_DIV =    new BigInteger("10000000000");
    private static BigInteger NIK_DATE_DIV =      new BigInteger("100000000");
    private static BigInteger NIK_MONTH_DIV =     new BigInteger("1000000");
    private static BigInteger NIK_YEAR_DIV =      new BigInteger("10000");
    private static BigInteger NIK_REGISTNUM_DIV = new BigInteger("1");
    private static BigInteger NIK_HUNDRED_MAX =   new BigInteger("100");
    private static BigInteger NIK_REGISTNUM_MAX = new BigInteger("10000");

    /**
     * Parse NIK Number to [KtpNik]
     * @param nik - Source KTP NIK
     * @param retval - Reference to a NIK Structure
     * @returns Error type, {KtpNikError} if success
     */
    public static KtpNikError Parse(BigInteger nik, KtpNik retval){
        if (nik.compareTo(MIN_NIK_INFO) < 0)
        {
            return KtpNikError.InsufficientData;
        }        
        
        retval.province =   nik.divide(NIK_PROVINCE_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.city =       nik.divide(NIK_CITY_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.region =     nik.divide(NIK_REGION_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.birthDate =  nik.divide(NIK_DATE_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.birthMonth = nik.divide(NIK_MONTH_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.birthYear =  nik.divide(NIK_YEAR_DIV).mod(NIK_HUNDRED_MAX).byteValue();
        retval.uid =        nik.divide(NIK_REGISTNUM_DIV).mod(NIK_REGISTNUM_MAX).shortValue();
        retval.isFemale = retval.birthDate > 40;

        if (retval.isFemale)
        {
            retval.birthDate -= 40;
        }

        if (retval.birthDate > 31 || retval.birthMonth > 12)
        {
            return KtpNikError.InvalidDate;
        }
        
        return KtpNikError.Success;
    }
}