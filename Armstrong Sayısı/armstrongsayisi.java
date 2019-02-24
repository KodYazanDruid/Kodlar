import java.util.Scanner;
public class armstrongsayisi {
    public static void main(String[] args){
        int t, a, b, c, temp;
        System.out.println("3 basamakli bir sayi giriniz: ");
        t = new Scanner (System.in).nextInt();
        c = t%10;
        b = ((t-c)/10)%10;
        a = ((t-(b+c))/100)%100;
        temp = (a*a*a) + (b*b*b) + (c*c*c);
        if(t == temp){
            System.out.println("Armstrong sayisi!");
        }else{
            System.out.println("Armstrong sayisi degil :(");
        }
    }
}
