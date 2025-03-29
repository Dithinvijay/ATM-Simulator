package atmsimulator;

import java.util.Scanner;

public class AtmMachine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ATM atm = new ATM();
        InputValidation input = new InputValidation();

        int option;
        do {
            System.out.println("\n\t\t\tWelcome to the ATM");
            System.out.println("Choose an option:");
            System.out.println("0. Exit");
            System.out.println("1. Create an Account");
            System.out.println("2. Deposit Money");
            System.out.println("3. Withdraw Money");
            System.out.println("4. Check Balance");
            System.out.println("5. Change PIN");

            option = input.validateInteger(scanner);
            scanner.nextLine(); 

            String accountNumber;
            String accountHolderName;
            int pin, newPin;
            double amount;

            switch (option) {
                case 0:
                    System.out.println("Exiting...");
                    break;
                case 1:
                    System.out.println("Enter Account Number:");
                    accountNumber = scanner.nextLine();
                    System.out.println("Enter Account Holder Name:");
                    accountHolderName = scanner.nextLine();
                    System.out.println("Create a PIN:");
                    pin = input.validateInteger(scanner);
                    atm.createAccount(accountNumber, accountHolderName, pin);
                    break;
                case 2:
                    System.out.println("Enter Account Number:");
                    accountNumber = scanner.nextLine();
                    System.out.println("Enter Deposit Amount:");
                    amount = input.validateDouble(scanner);
                    System.out.println("Enter PIN:");
                    pin = input.validateInteger(scanner);
                    atm.deposit(accountNumber, pin, amount);
                    break;
                case 3:
                    System.out.println("Enter Account Number:");
                    accountNumber = scanner.nextLine();
                    System.out.println("Enter Withdraw Amount:");
                    amount = input.validateDouble(scanner);
                    System.out.println("Enter PIN:");
                    pin = input.validateInteger(scanner);
                    atm.withdraw(accountNumber, pin, amount);
                    break;
                case 4:
                    System.out.println("Enter Account Number:");
                    accountNumber = scanner.nextLine();
                    System.out.println("Enter PIN:");
                    pin = input.validateInteger(scanner);
                    atm.checkBalance(accountNumber, pin);
                    break;
                case 5:
                    System.out.println("Enter Account Number:");
                    accountNumber = scanner.nextLine();
                    System.out.println("Enter Current PIN:");
                    pin = input.validateInteger(scanner);
                    System.out.println("Enter New PIN:");
                    newPin = input.validateInteger(scanner);
                    atm.changePin(accountNumber, pin, newPin);
                    break;
                default:
                    System.out.println("Invalid option! Please try again.");
            }
        } while (option != 0);

        scanner.close();
    }
}
