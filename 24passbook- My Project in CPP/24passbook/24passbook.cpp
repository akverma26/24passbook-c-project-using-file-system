#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

double balance1=0;
int menu2();
exit1()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t<<< THANKS FOR  BEING HERE >>>\n\t\t\t\t\t<<< HAVE   A    NICE   DAY >>>\n\t\t\t\t\t<<< FIR MILENGE... BYE BYE >>>\n";
    cout<<"\n\n\n\n\n\n\t\t\t\t\tCREATED BY ANKIT KUMAR VERMA\n";
    cout<<"\t\t\t\t\takvindian.wixsite.com/home\n\n";
    cout<<"\nPress any key to exit...";
    getch();
    exit(0);
}
removeAccount()
{
    system("cls");
    remove("accountLogin.dat");
    remove("accountCreated.dat");
    remove("savingAccount.dat");
    remove("passBook.dat");
    cout<<"\n\n\n\t\t\t>>> Account has been Deleted, Restart the Program to Create a New Account, Press any key to Continue...";
    getch();
    exit1();
}

int curr_day=0,curr_month=0,curr_year=0;
void currDate()
{
    while(1)
    {
        system("cls");
        cout<<"<<< Current Date >>>\n\nProvide Current Date (in this format (dd/mm/yyyy): ):\t";
        scanf("%d/%d/%d",&curr_day,&curr_month,&curr_year);
        if(curr_day<32 && curr_day>0 && curr_month>0 && curr_month<13)
        {
            cout<<"\n!!! Current Date is set !!!\n\nPress any key to Continue...";
            getch();
            break;
        }
        else
        {
            cout<<"\n~~~ Invalid Date, Please Try Again ~~~\n";
            cout<<"\nPress any key to Continue...";
            getch();
        }
    }
}

class savingAccount
{
    char AccountType[21],cifNo[21],accountNo[21],bank[51],ifsc[15],branchCode[5];
    double balance;
    char customerName[31],address[101],pincode[10], district[21],state[21],mobile[21],email[26],dob[15];
public:
    Initialize(const char * ac_no)
    {
        strcpy(AccountType,"NULL");
        strcpy(cifNo,"NULL");
        strcpy(accountNo,ac_no);
        strcpy(bank,"NULL");
        strcpy(ifsc,"NULL");
        strcpy(branchCode,"NULL");
        balance=0;
        strcpy(customerName,"NULL");
        strcpy(address,"NULL");
        strcpy(pincode,"NULL");
        strcpy(district,"NULL");
        strcpy(state,"NULL");
        strcpy(mobile,"NULL");
        strcpy(email,"NULL");
        strcpy(dob,"NULL");
        ofstream out;
        out.open("savingAccount.dat",ios::binary|ios::app);
        out.write((char*)this,sizeof(*this));
        out.close();
        showAccountDetails();
    }
    void showAccountDetails();
    void updateAccountDetails(int);
};

void savingAccount::updateAccountDetails(int x)
{
    int option;




    ifstream in;
    in.open("savingAccount.dat",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));
    in.close();
    if(x==1)
    {
        balance=balance1;
    }
    else if(x==-1)
    {
        balance1=balance;
    }
    else
    {
        system("cls");
        showAccountDetails();
        cout<<"\nChoose Option that you want to Update or Press 0 to Complete Update:\t";
        cin>>option;
    }
    while(x==0)
    {

        if(option<=15 && option>0)
        {
            cout<<"\nEnter New Value:\t";
        }
        switch(option)
        {
        case 0:
        cout<<"\n\n!!! Your Account Details have been Saved !!!\n\n";
        x=1;
        cout<<"\nPress any key to Continue...";
        getch();
        break;
        case 1:
        cin.ignore();
        cin.getline(AccountType,20);
        break;
        case 2:
        cin>>cifNo;
        break;
        case 3:
        cin>>accountNo;
        break;
        case 4:
        cin.ignore();
        cin.getline(bank,50);
        break;
        case 5:
        cin>>ifsc;
        break;
        case 6:
        cin>>branchCode;
        break;
        case 7:
        cin>>balance;
        break;
        case 8:
        cin.ignore();
        cin.getline(customerName,30);
        break;
        case 9:
        cin.ignore();
        cin.getline(address,100);
        break;
        case 10:
        cin>>pincode;
        break;
        case 11:
        cin.ignore();
        cin.getline(district,20);
        break;
        case 12:
        cin.ignore();
        cin.getline(state,20);
        break;
        case 13:
        cin>>mobile;
        break;
        case 14:
        cin>>email;
        break;
        case 15:
        cin>>dob;
        break;
        default:
        cout<<"\n~~~ Invalid Option, Please Choose a Valid Option and Try Again... ~~~\n";
        cout<<"\n\nPress any key to Continue...";
        getch();
        break;
        }
        ofstream out;
        out.open("temp.dat",ios::out);
        out.write((char*)this,sizeof(*this));
        out.close();
        remove("savingAccount.dat");
        rename("temp.dat","savingAccount.dat");



        if(!x)
        {
            system("cls");
            showAccountDetails();
            cout<<"\nChoose Option that you want to Update or Press 0 to Complete Update:\t";
            cin>>option;
        }
    }
    ofstream out;
        out.open("temp.dat",ios::out);
        out.write((char*)this,sizeof(*this));
        out.close();
        remove("savingAccount.dat");
        rename("temp.dat","savingAccount.dat");
}

void savingAccount::showAccountDetails()
{
    cout<<"<<< Your Account Details >>>\n\n";
    ifstream in;
    in.open("savingAccount.dat",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));
    cout<<"1.Account Type:\t\t"<<AccountType<<endl;
    cout<<"2.CIF No.:\t\t"<<cifNo<<endl;
    cout<<"3.Account No.:\t\t"<<accountNo<<endl;
    cout<<"4.Bank Name:\t\t"<<bank<<endl;
    cout<<"5.IFSC Code:\t\t"<<ifsc<<endl;
    cout<<"6.Branch Code:\t\t"<<branchCode<<endl;
    cout<<"7.Account Balance:\t"<<balance<<endl;
    cout<<"8.Customer Name:\t"<<customerName<<endl;
    cout<<"9.Address:\t\t"<<address<<endl;
    cout<<"10.Pincode:\t\t"<<pincode<<endl;
    cout<<"11.District:\t\t"<<district<<endl;
    cout<<"12.State:\t\t"<<state<<endl;
    cout<<"13.Mobile:\t\t"<<mobile<<endl;
    cout<<"14.Email-id:\t\t"<<email<<endl;
    cout<<"15.DOB:\t\t\t"<<dob<<endl;
    balance1=balance;
    in.close();
}

class Account
{
    char ac_no[21],pass[21];

    public:

    int createAccount();
    int login();
};

int Account::login()
{
    char ac_no[21],pass[21];
    cout<<"Enter A/c No.: ";
    cin>>ac_no;
    cout<<"Enter Password: ";
    cin>>pass;

    ifstream in;
    in.open("accountLogin.dat",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));

    if(!strcmp(ac_no,this->ac_no) && !strcmp(pass,this->pass))
    {
        cout<<"\n!!! Successfully Logged In !!!\n";
        cout<<"\nPress any key to Continue...";
        getch();
        system("cls");
        return 1;
    }
    else
    {
        cout<<"\n~~~ Either Account don't exist or Password is not Correct, Please Try Again... ~~~";
        getch();
        system("cls");
        return 0;
    }
}

int Account::createAccount()
{
        char conf_pass[21];
        cout<<"Enter A/C No. (max Length 20 Characters): ";
        cin>>ac_no;
        cout<<"Create a Password (max Length 20 Characters): ";
        cin>>pass;
        cout<<"Confirm your Password: ";
        cin>>conf_pass;
        if(!strcmp(pass,conf_pass))
        {
            cout<<"\nAccount has been created Successfully !!!\n\n";
            ofstream out;
            out.open("accountLogin.dat",ios::app|ios::binary);
            out.write((char*)this,sizeof(*this));
            out.close();
            ofstream out1;
            out1.open("accountCreated.dat",ios::out|ios::binary);
            out1<<"1";
            out1.close();
            savingAccount s;
            s.Initialize(ac_no);
            cout<<"\nPlease Initialize your Current Account Balance before adding any Transaction (See Option 7) and Also add that Initial Account Balance in Credit in Add Transaction Menu, so";
            cout<<"\nDo you want to Update your Account Details (It can also be done Later) (Y/N):\t";
            char option;
            cin>>option;
            if(option=='y'||option=='y')
            {
                s.updateAccountDetails(0);
            }
            return 1;
        }
        else
        {
            cout<<"\nPasswords are not Matching !!!\n";
            return 0;
        }
}

class Transaction
{
    int d,m,y;
    char description[101];
    double credit,debit;
public:
    Transaction()
    {
        credit=0;
        debit=0;
    }

    void addTransaction();
    void showTransaction();
    void savingAccountActivity();
};

void Transaction:: showTransaction()
{
    ifstream in;
    in.open("passBook.dat",ios::in|ios::binary);
    cout<<"Date\t\tCredit\t\tDebit\t\tDescription\n";
    if(in)
    {

        in.read((char*)this,sizeof(*this));
        while(!in.eof())
        {
            cout<<d<<"/"<<m<<"/"<<y<<"\t"<<credit<<"\t\t"<<debit<<"\t\t"<<description<<endl;
            in.read((char*)this,sizeof(*this));
        }
    }
    savingAccount s2;
    s2.updateAccountDetails(1);
    cout<<"\n\n\n\t\t\t<<< Your Current Account Balance is: "<<balance1<<" INR >>>\n\n\n";
}

void Transaction::addTransaction()
{
        cout<<"\n1.Credit (Deposit)\n2.Debit (Withdrawal)\n3.Exit from this menu\n(choose any one option):\t";
        int option;
        cin>>option;
        if(option!=3)
        {
            cout<<"\nEnter Date (in this format (dd/mm/yyyy)): ";
            scanf("%d/%d/%d",&d,&m,&y);
        }
        if(option==1)
        {
            cout<<"\nEnter Amount Credited: ";
            cin>>credit;
            balance1+=credit;
            savingAccount s;
            s.updateAccountDetails(1);
        }
        else if(option==2)
        {
            cout<<"\nEnter Amount Debited: ";
            cin>>debit;
            balance1-=debit;
            savingAccount s;
            s.updateAccountDetails(1);
        }

        if(credit==0 && debit==0)
        {
            cout<<"\n~~~ Neither a Credit nor a Debit, Invalid Transaction, Try Again with Valid Transaction ~~~\n";
        }
        else
        {
            cout<<"\nAdd Description for this Transaction:\t";
            cin.ignore();
            cin.getline(description,100);
            cout<<"\nPassBook has been Updated !!!\n";
            cout<<"\nPress any key to Continue...";
            getch();
            system("cls");
            ofstream out;
            out.open("passBook.dat",ios::app|ios::binary);
            out.write((char*)this,sizeof(*this));
            out.close();
        }

}

int menu1()
{
    ifstream in;
    in.open("accountCreated.dat",ios::in|ios::binary);
    char c;
    if(!in)
    {
        return 2;
    }
    else
    {
        in.read(&c,1);
    }
    if(c=='1')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int accountSetup()
{
    int flag=0;
    int option;
    option=menu1();
    Account a;
    while(!flag)
    {
        system("cls");
        if(option==1)
        {
            cout<<"<<< Login to your Account >>>\n\n";
            flag=a.login();
        }
        else if(option==2)
        {
            cout<<"<<< Create Account >>>\n\n";
            flag=a.createAccount();
        }
    }
    savingAccount s;
    s.updateAccountDetails(-1);
    return flag;
}

savingAc()
{
    int option;
    while(1)
    {
        Transaction t;
        system("cls");
        cout<<"<<< Saving Account >>>\n\nChoose any Option:\n\n1.Add Transaction\n2.View All Transaction\n3.View Account Details\n4.Update Account Details\n5.Know Current Balance\n6.Previous Menu\n0.Exit\t";
        cin>>option;
        cout<<endl;
        switch(option)
        {
            case 0:
                exit1();
                break;
            case 1:
                cout<<"<<< Add Transaction >>>\n";
                t.addTransaction();
                break;
            case 2:
                cout<<"<<< All Transactions >>>\n\n";
                t.showTransaction();
                cout<<"\nPress any key to Continue...";
                getch();
                break;
            case 3:
                savingAccount s;
                s.showAccountDetails();
                cout<<"\nDo you want to Update Account Details: (Y/N): ";
                char ans;
                cin>>ans;
                if(ans=='y'||ans=='Y')
                {
                    s.updateAccountDetails(0);
                }
                break;
            case 4:
                savingAccount s1;
                s1.updateAccountDetails(0);
                break;
            case 5:
                system("cls");
                savingAccount s2;
                s2.updateAccountDetails(1);
                cout<<"\n\n\n\t\t\t<<< Your Current Account Balance is: "<<balance1<<" INR >>>";
                cout<<"\n\n\nPress any key to Continue...";
                getch();
                break;
            case 6:
                menu2();
                break;
            default:
                cout<<"~~~ Invalid Option, Please Choose Correct Option ~~~";
                getch();
                break;
        }

    }
}

int menu2()
{
    int option;

    while(1)
    {
        system("cls");
        cout<<"<<< Choose any Option >>>\n\n1.Saving Account\n2.Delete Account\n0.Exit:\t\t";
        cin>>option;
        switch(option)
        {
        case 1:
            savingAc();
            break;
        case 2:
            removeAccount();
            break;
        case 0:
            exit1();
            break;
        default:
            cout<<"\n ~~~Invalid Option, Please Choose Correct Option and Try Again ~~~";
            getch();
            break;
        }
    }
}

int main()
{
    int flag=accountSetup();

    if(flag)
    {
        menu2();
    }
    return 0;
}

