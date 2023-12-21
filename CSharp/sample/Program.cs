/**
 * ktpnik.Sample - KTP NIK Parsing Library Sample
 * Author : EmiyaSyahriel
 */
using System;

namespace EmiyaSyahriel.KtpNik.Sample
{
    public static class Program
    {
        const ulong SMP_NIK_INFO = 3502136410016213UL;
        public static int Main(string[] args)
        {
            KtpNik ktp = new KtpNik();
            KtpNikError err = KtpNik.Parse(SMP_NIK_INFO, ref ktp);
            if(err != KtpNikError.Success)
            {
                Console.WriteLine();
                return 1;
            }

            Console.WriteLine($"NIK {SMP_NIK_INFO}, City : {ktp.city}, Female : {ktp.isFemale}, UID : {ktp.uid}");
            return 0;
        }
    }
}