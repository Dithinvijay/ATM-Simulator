package atmsimulator;

import java.util.InputMismatchException;
import java.util.Scanner;

public class InputValidation {
    public int validateInteger(Scanner sc)
    {
        int num;
        while(true)
        {
            try{
                num=sc.nextInt();
                return num;
            }
            catch(InputMismatchException e)
            {
                System.out.println("Check the input you have entered");
                sc.nextLine();
            }
            
        }
    }
    public double validateDouble(Scanner sc)
    {
        double num;
        while(true)
        {
            try{
                num=sc.nextDouble();
                return num;
            }
            catch(InputMismatchException e)
            {
                System.out.println("Check the input you have entered");
                sc.nextLine();
            }
            
        }
    }
}
