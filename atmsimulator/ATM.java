package atmsimulator;

import java.util.Scanner;

public class ATM {
    private Account head;
    public ATM() {
        this.head = null;
    }

    private Account findAccount(String accountNumber) {
        Account temp = head;
        while (temp != null) {
            if (temp.accountNumber.equals(accountNumber)) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }

    public void createAccount(String accountNumber, String accountHolderName, int pin) {
        if (findAccount(accountNumber) != null) {
            System.out.println("Account already exists with Account Number: " + accountNumber);
            return;
        }
        Account newAccount = new Account(accountNumber, accountHolderName, pin);
        if (head == null) {
            head = newAccount;
        } else {
            Account temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newAccount;
        }
        System.out.println("Account Created Successfully!");
    }

    public void deposit(String accountNumber, int pin, double amount) {
        Account account = findAccount(accountNumber);
        if (account == null) {
            System.out.println("No account found with the given number.");
            return;
        }
        if (account.pin != pin) {
            System.out.println("Incorrect PIN.");
            return;
        }
        account.inputDeposit(amount);
        account.deposit();
        System.out.println("Deposited Amount: " + amount);
    }

    public void withdraw(String accountNumber, int pin, double amount) {
        Account account = findAccount(accountNumber);
        if (account == null) {
            System.out.println("No account found with the given number.");
            return;
        }
        if (account.pin != pin) {
            System.out.println("Incorrect PIN.");
            return;
        }
        account.inputWithdraw(amount);
        if (account.withdraw()) {
            System.out.println("Withdrawn Amount: " + amount);
        }
    }

    public void checkBalance(String accountNumber, int pin) {
        Account account = findAccount(accountNumber);
        if (account == null) {
            System.out.println("No account found with the given number.");
            return;
        }
        if (account.pin != pin) {
            System.out.println("Incorrect PIN.");
            return;
        }
        System.out.println("Available Balance: " + account.balance);
    }

    public void changePin(String accountNumber, int oldPin, int newPin) {
        Account account = findAccount(accountNumber);
        if (account == null) {
            System.out.println("No account found with the given number.");
            return;
        }
        if (account.pin != oldPin) {
            System.out.println("Incorrect PIN.");
            return;
        }
        Scanner scanner = new Scanner(System.in);
        System.out.print("Re-enter the new PIN: ");
        int confirmPin = scanner.nextInt();
        if (confirmPin == oldPin) {
            System.out.println("This PIN matches the old one. Choose a new PIN.");
        } else if (confirmPin == newPin) {
            account.pin = newPin;
            System.out.println("PIN updated successfully!");
        } else {
            System.out.println("PINs do not match. Try again.");
        }
        scanner.close();
    }
}
