#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class Acc
{
	public:
		string Ac_No;
		string Ac_Name;
		int pin,npin,npin1;
		double balance;
		double W_money;
		double D_money;
		int countD,countW;
		Acc* next;
		
		Acc()
		{
			Ac_No=" ";
			Ac_Name=" ";
			pin=0;
			balance=0;
			W_money=0;
			D_money=0;
			countD=0;
			countW=0;
			next=NULL;
		}
		Acc(string Ac_No,string Ac_Name,int pin)
		{
			this->Ac_No=Ac_No;
			this->Ac_Name=Ac_Name;
			this->pin=pin;
		}
		void input_deposit(double D_money)
		{
			this->D_money=D_money;
		}
		void input_withdraw(double W_money)
		{
			this->W_money=W_money;
		}
		double Deposit()
		{
			balance=balance+D_money;
			return balance;
		}
		double Withdraw()
		{
			balance=balance-W_money;
			return balance;
		}
};
class Atm:public Acc
{
	public:
		Acc* head;
		Atm()
		{
			head=NULL;
		}
		Atm(Acc* a)
		{
			head=a;
		}
		//
		Acc* AccountExist(string Ac_No)
		{
			Acc* temp=NULL;
			Acc* ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->Ac_No==Ac_No)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}
		//
		void CreateAccount(Acc* a)
		{
			if(AccountExist(a->Ac_No))
			{
				cout<<"Account Aldready exists with Account Number: "<<a->Ac_No<<endl;
			}
			else
			{
				if(head==NULL)
				{
					head=a;
					cout<<"Account Created"<<endl;
				}
				else
				{
					Acc* ptr=head;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
					}
					ptr->next=a;
					cout<<"Account Created"<<endl;
				}			
			}
		}
		//adding extra user interface
		bool Accountcheck(string Ac_No)
		{
			Acc* ptr=AccountExist(Ac_No);
			if(ptr==NULL)
			{
				cout<<"No Account with that number: "<<Ac_No<<endl;
				return false;
			}
			return true;
		} 
		//
		void Deposit(string Ac_No,int pin,double D_money)
		{
			Acc* ptr=AccountExist(Ac_No);
			if(ptr==NULL)
			{
				return;
			}
			else
			{
				if(ptr->pin==pin)
				{
					ptr->input_deposit(D_money);
					if(ptr->D_money>0)
					{
						countD++;
						cout<<"The Amount Deposited is: "<<ptr->D_money<<endl;
						ptr->balance=ptr->balance+ptr->D_money;
					}
				}
				else
				{
					cout<<"Incorrect Pin"<<endl;
				}
			}
		}
		//
		void Withdraw(string Ac_No,int pin,double W_money)
		{
			Acc* ptr=AccountExist(Ac_No);
			if(ptr==NULL)
			{
				return;
			}
			else
			{
				if(ptr->pin==pin)
				{
					ptr->input_withdraw(W_money);
					if(ptr->W_money<=ptr->balance)
					{
						countW++;
						cout<<"The Amount Withdrawed is: "<<ptr->W_money<<endl;
						ptr->balance-=ptr->W_money;
					}
					else
					{
						cout<<"The Available Balance is "<<ptr->balance<<" Can't withdraw more than "<<ptr->balance<<endl;
					}
				}
				else
				{
					cout<<"Incorrect Pin"<<endl;
				}
			}
			
		}
		//
		void BalanceCheck(string Ac_No,int pin)
		{
			Acc* ptr=AccountExist(Ac_No);
			if(ptr==NULL)
			{
				return;
			}
			else if(ptr->pin==pin)
			{
				cout<<"The Available balance is: "<<ptr->balance;
			}
			else
			{
				cout<<"Invalid Pin"<<endl;
			}
		}
		//
		void changingPin(string Ac_No,int pin,int npin)
		{
			Acc* ptr=AccountExist(Ac_No);
			if(ptr!=NULL)
			{
				if(ptr->pin==pin)
				{
					cout<<"Re-enter the new pin: ";
					cin>>npin1;
					if(npin1==ptr->pin)
					{
						cout<<"This pin is matching to the old one create a new pin"<<endl;
					}
					else
					{
						if(npin1==npin)
						{
							ptr->pin=npin;
							cout<<"Your Pin is Updated"<<endl;
						}
						else
						{
							cout<<"Your Pin is incorrect"<<endl;
						}
					}	
				}
				else
				{
					cout<<"Incorrect Pin"<<endl;
				}
			}
		}
};
int main()
{
	Atm At1;
	string Ac_No,Ac_Name;
	int pin,npin,npin1,opt;
	double balance,W_money,D_money;
	do{
		cout<<endl;
		cout<<"\t\t\t\t\tWelcome to the ATM"<<endl;
		cout<<"Enter the options as shown below:"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Create the Account"<<endl;
		cout<<"2. Deposit the Money"<<endl;
		cout<<"3. Withdraw the Money"<<endl;
		cout<<"4. Balance Check"<<endl;
		cout<<"5. Changing the Pin"<<endl;
		cout<<"6. Clear the Screen"<<endl;
		cin>>opt;
		
		Acc* A1=new Acc();
		
		switch(opt)
		{
			case 0:
				break;
			case 1:
				cout<<"Creating the Account"<<endl;
				cout<<"Enter the Account Number: "<<endl;
				cin>>Ac_No;
				cout<<"Enter the Account Holder Name: "<<endl;
				cin>>Ac_Name;
				cout<<"Create the pin: "<<endl;
				cin>>pin;
				A1->Ac_No=Ac_No;
				A1->Ac_Name=Ac_Name;
				A1->pin=pin;
				At1.CreateAccount(A1);
				break;
			case 2:
				cout<<"Deposit the Amount"<<endl;
				cout<<"Enter the Account Number: ";
				cin>>Ac_No;
				if(!At1.Accountcheck(Ac_No))
				{
					break;
				}
				else
				{
				
				cout<<"Enter the Depositing Amount: ";
				cin>>D_money;
				cout<<"Enter the Pin: ";
				cin>>pin;
				At1.Deposit(Ac_No,pin,D_money);
				break;
			}	
			case 3:
				cout<<"Withdraw the Amount"<<endl;
				cout<<"Enter the Account Number: ";
				cin>>Ac_No;
				if(!At1.Accountcheck(Ac_No))
				{
					break;
				}
				else
				{
					
				cout<<"Enter the Withdraw Amount: ";
				cin>>W_money;
				cout<<"Enter the Pin: ";
				cin>>pin;
				At1.Withdraw(Ac_No,pin,W_money);
				break;
			}	
			case 4:
				cout<<"Balance Checking"<<endl;
				cout<<"Enter the Account Number: ";
				cin>>Ac_No;
				if(!At1.Accountcheck(Ac_No))
				{
					break;
				}
				else
				{
				cout<<"Enter the Pin: ";
				cin>>pin;
				At1.BalanceCheck(Ac_No,pin);
				break;
			}	
			case 5:
				cout<<"Changing the Pin"<<endl;
				cout<<"Enter the Account Number: ";
				cin>>Ac_No;
				if(!At1.Accountcheck(Ac_No))
				{
					break;
				}
				else
				{
				cout<<"Enter the Pin: ";
				cin>>pin;
				cout<<"Enter the New Pin to change: ";
				cin>>npin;
				At1.changingPin(Ac_No,pin,npin);
				break;
			}	
			case 6:
				system("cls");
				break;
			default:
				cout<<"Enter the correct option"<<endl;
				break;
		}
	}while(opt!=0);
	
	return 0;
}
