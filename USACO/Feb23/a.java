// package aaa;
import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cows = sc.nextInt();
        int cc = sc.nextInt();
        int max = 0;
        int temp = 0;
        ArrayList<Integer> cowHeights = new ArrayList<>();
        ArrayList<Integer> ccHeights = new ArrayList<>();
        for(int i = 0; i < cows; i++) {
            temp = sc.nextInt();
            cowHeights.add(temp);
            if(temp > max) {
                max = temp;
            }
        }
        
        for(int i = 0; i < cc; i++) {
            ccHeights.add(sc.nextInt());
        }
        doa(cowHeights, ccHeights, max);
    }
    
    public static void doa(ArrayList<Integer> cowHeights, ArrayList<Integer> ccHeights, int max) {
        int height = 0;
        int ccheight = 0;
        for(int i = 0; i < ccHeights.size(); i++) {
            ccheight = ccHeights.get(i);
            int first = cowHeights.get(0);
            if(max <= first) {
                int add = ccheight;
                if(first <= ccheight) {
                    add = first;
                }
                cowHeights.set(0, first + add);
            } else {
                for(int j = 0; j < cowHeights.size(); j++) {
                    int check = cowHeights.get(j);
                    if(check > height) {
                        int temp = height;
                        height = check;
                        cowHeights.set(j, 2 * check - temp);
                        if(check >= ccheight) {
                            break;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < cowHeights.size(); i++)
            System.out.println(cowHeights.get(i));
    }
}