import java.util.*;
public class Solution
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a = new long[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextLong();
        }
        long l = 0;
        int i;
        for(i=1;i<n;i*=2)
        {
            long li = a[0] ^ a[i];
            li /= i;
            while(li>1)
            {
                l += (li%2)*i;
                li /= 2;
                i *= 2;
            }
        }
        l += (a[0] / i)*i;
        System.out.println(a[0] ^ l);
        sc.close();
    }
}