package atmsimulator;

public class Account {
    String accountNumber;
    String accountHolderName;
    int pin;
    double balance;
    double depositAmount;
    double withdrawAmount;
    Account next;

    public Account() {
        this.accountNumber = "";
        this.accountHolderName = "";
        this.pin = 0;
        this.balance = 0.0;
        this.depositAmount = 0.0;
        this.withdrawAmount = 0.0;
        this.next = null;
    }

    public Account(String accountNumber, String accountHolderName, int pin) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.pin = pin;
        this.balance = 0.0;
    }

    public void inputDeposit(double depositAmount) {
        this.depositAmount = depositAmount;
    }

    public void inputWithdraw(double withdrawAmount) {
        this.withdrawAmount = withdrawAmount;
    }

    public void deposit() {
        balance += depositAmount;
    }

    public boolean withdraw() {
        if (withdrawAmount > balance) {
            System.out.println("Insufficient Balance! Available balance: " + balance);
            return false;
        }
        balance -= withdrawAmount;
        return true;
    }
}
