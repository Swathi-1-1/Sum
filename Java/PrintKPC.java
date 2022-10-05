import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        Scanner obj=new Scanner(System.in);
        String s=obj.next();
        printKPC(s,"");
    }
    static String[] codes={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static void printKPC(String s, String ans) {
       if(s.length()==0)
       {
           System.out.println(ans);
           return;
       } 

    char a=s.charAt(0);
    String ros=s.substring(1);
    String we=codes[a-'0'];

    for(int i=0;i<we.length();i++)
    {
        char f=we.charAt(i);

        printKPC(ros,ans+f);
    }

        return;
    }

}
