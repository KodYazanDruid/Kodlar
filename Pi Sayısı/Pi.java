import java.util.Random;
public class Pi {
    public static void main(String[] args){
        int total = 10000000;
        int inner=0;
        Random random = new Random();
        for(int i=0; i<total; i++){
            double x = random.nextDouble();
            double y = random.nextDouble();
            if((x*x + y*y) <= 1){
                inner++;
            }
        }
        System.out.println("Pi'nin yaklaþýk deðeri: " + 4*((float)inner/total));
    }
}
