package emiyasyahriel.ktpnik;

import java.math.BigInteger;

public class KtpNikSample {
    private static BigInteger SMP_NIK_INFO = new BigInteger("3502136410016213");
    public static void main(String[] args){
        KtpNik ktp = new KtpNik();
        KtpNikError err = KtpNik.Parse(SMP_NIK_INFO, ktp);
        
        if(err != KtpNikError.Success)
        {
            System.out.println(String.format("Error parsing NIK %s : %s", SMP_NIK_INFO.toString(), err.toString()));
            System.exit(1);
        }

        System.out.println(String.format("NIK %s, City : %d, Female : %b, UID : %d", 
            SMP_NIK_INFO.toString(),
            ktp.city,
            ktp.isFemale,
            ktp.uid
            ));
    }
}
