#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<fstream>

using namespace std;


class new_user
{
public:
    int i,j,branch,a,k,r;
    ofstream ob1;
    ifstream ob2;
    long long amt,debit;
    string name,dob,email,type,aadhaar,mob;
    long double bal;

    void create()
    {
        for(k=0;k<1;k++)
        {
            system("cls");
            cout<<"Enter your full name\n";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter your date of birth in DD-MM-YYYY Format\n";
            cin>>dob;
            cout<<"Enter Your 10-digit Mobile Number\n+91";
            cin>>mob;
            a=mob.size();
            while(1)
            {
                if(a<10||a>10)
                {
                    cout<<"Enter correct Mobile Number\n+91";
                    cin>>mob;
                    a=mob.size();
                }
                else if (a==10)
                    break;
            }
            cout<<"Enter email id\n";
            cin>>email;
            cout<<"Enter the type of account you wish to open (saving/current):\n";
            cin>>type;
            cout<<"Kindly Enter your 12 digit aadhar number\n";
            cin>>aadhaar;
            a=aadhaar.size();
            j=4;
            for(i=0;i<5;i++)
            {
                if(a<12||a>12)
                {
                    cout<<"Invalid Aadhar Number"<<endl;
                    cout<< "Remaining Attempts: "<<j<<endl;
                    cout<<"Enter correct aadhar number:\n";
                    cin>>aadhaar;
                    a=aadhaar.size();
                }
                else
                    break;
                j--;
            }
            if(a<12||a>12)
            {
                cout<<"You Have Exceeded The Number of Attempts\n";
                continue;
            }
            cout<<"We have following branches:\n1- Janakpuri, Delhi\n2- Shastri Nagar, Ghaziabad\n3- Sector-34, Chandigarh\nKindly Enter the serial number of preferred branch: ";
            cin>>branch;
            cout<<"\nWELCOME ONBOARD WITH OUR BANK\nKindly go through our bank website for information about our various services\n";
            for(i=0;i<2000;i++)
            {
                cout<<"Please Wait........we are generating your account id";
                for(j=0;j<52;j++)
                    cout<<"\b";
            }
            srand(time(0));
            ob1.open("account info.txt",ios::app);
            if (branch==2)
            {
                r=rand()%10;
                cout<<"\n\nYour Acoount ID is: 202"<<aadhaar<<r<<endl;
                ob1<<"202"<<aadhaar<<r;
            }

            else if(branch==1)
            {
                r=rand()%10;
                cout<<"\n\nYour Account ID is: 158"<<aadhaar<<r<<endl;
                ob1<<"158"<<aadhaar<<r;
            }

            else if(branch==3)
            {
                r=rand()%10;
                cout<<"\n\nYour Account ID is: 322"<<aadhaar<<r<<endl;
                ob1<<"322"<<aadhaar<<r;
            }

            else
                cout<<"\n\nInvalid Branch Choosen\n";

        }

        cout<<"Please note your Account ID for further enquiry\n";
        system("pause");
        system("cls");
         cout<<"Current Account Balance: NIL\n";
        cout<<"Add Account Opening Amount(min. 5000)\n";
        cin>>bal;
        while(1)
        {
            if(bal<5000)
            {
                cout<<"Invalid Amount....Please Try Again\n";
                cin>>bal;
            }
            else
                break;
        }
        cout<<"Updated balance: "<<bal<<endl;
        cout<<"Account Opening Process is complete\n";
        cout<<"Thank you for banking with us\n";
        system("pause");
    }
};



class existing_user:public new_user
{
private:
    long long inpid,acc_id,tinpid;
    string inpname1,inpname2,inptype,inpdob,inpmob,inpemail,inpaadhaar,tinpname1,tinpname2,tinptype,tinpdob,tinpmob,tinpemail,tinpaadhaar;
    int inpbranch,tinpbranch;
    long double inpbal,inpbald,tinpbal;

public:

    int display()
    {
        int flag=0;
        system("cls");
        cout<<"Enter your Account ID: ";
        cin>>acc_id;
        ob2.open("account info.txt");
        while(ob2>>inpid>>inpname1>>inpname2>>inpdob>>inpmob>>inpemail>>inptype>>inpaadhaar>>inpbranch>>inpbal)
        {
            if(inpid==acc_id)
            {
                cout<<"Account Holder Name: "<<inpname1<<" "<<inpname2<<endl<<"Account Balance: "<<inpbal<<endl;
                flag=1;

            }
        }
        if(flag!=1)
            cout<<"Invalid Account ID"<<endl;
        ob2.close();
        system("pause");
        return 0;
    }


    int deposit()
    {
        int flag=0;
        system("cls");
        cout<<"Enter your Account ID: ";
        cin>>acc_id;
        ob2.open("account info.txt");
        while(ob2>>inpid>>inpname1>>inpname2>>inpdob>>inpmob>>inpemail>>inptype>>inpaadhaar>>inpbranch>>inpbal)
        {
                if(inpid==acc_id)
                {
                    cout<<"Account Holder Name: "<<inpname1<<" "<<inpname2<<endl;
                    cout<<"Current Balance: "<<inpbal<<endl;
                    cout<<"Enter Amount to be deposited: ";
                    cin>>bal;
                    inpbald=inpbal+bal;
                    cout<<"Updated Balance: "<<inpbald<<endl;
                    flag=1;
                    break;
                }
        }
        ob2.close();
        ob2.open("account info.txt");
        ob1.open("temp.txt");
        while(ob2>>tinpid>>tinpname1>>tinpname2>>tinpdob>>tinpmob>>tinpemail>>tinptype>>tinpaadhaar>>tinpbranch>>tinpbal)
        {
                if(tinpid!=acc_id)
                    ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<tinpbal<<endl;
                else
                    ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<inpbald<<endl;
        }
        ob2.close();
        ob1.close();
        ob1.open("account info.txt");
        ob2.open("temp.txt");
        while(ob2>>tinpid>>tinpname1>>tinpname2>>tinpdob>>tinpmob>>tinpemail>>tinptype>>tinpaadhaar>>tinpbranch>>tinpbal)
        {
            ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<tinpbal<<endl;
            ob1.close();
            ob1.open("account info.txt",ios::app);
        }
        ob1.close();
        ob2.close();
        if(flag!=1)
            cout<<"Invalid Account ID\n";
        system("pause");
        return 0;
    }


    int withdraw()
    {
        int flag=0;
        system("cls");
        cout<<"Enter your Account ID: ";
        cin>>acc_id;
        ob2.open("account info.txt");
        while(ob2>>inpid>>inpname1>>inpname2>>inpdob>>inpmob>>inpemail>>inptype>>inpaadhaar>>inpbranch>>inpbal)
        {
                if(inpid==acc_id)
                {
                    cout<<"Account Holder Name: "<<inpname1<<" "<<inpname2<<endl;
                    cout<<"Current Balance: "<<inpbal<<endl;
                    cout<<"Enter Amount to be withdrawn: ";
                    cin>>bal;
                    inpbald=inpbal;
                    if(bal<inpbal)
                        inpbald=inpbal-bal;
                    else
                        cout<<"Insufficient Account Balance\n";
                    cout<<"Updated Balance: "<<inpbald<<endl;
                    flag=1;
                    break;
                }
        }
        ob2.close();
        ob2.open("account info.txt");
        ob1.open("temp.txt");
        while(ob2>>tinpid>>tinpname1>>tinpname2>>tinpdob>>tinpmob>>tinpemail>>tinptype>>tinpaadhaar>>tinpbranch>>tinpbal)
        {
                if(tinpid!=acc_id)
                    ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<tinpbal<<endl;
                else
                    ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<inpbald<<endl;
        }
        ob2.close();
        ob1.close();
        ob1.open("account info.txt");
        ob2.open("temp.txt");
        while(ob2>>tinpid>>tinpname1>>tinpname2>>tinpdob>>tinpmob>>tinpemail>>tinptype>>tinpaadhaar>>tinpbranch>>tinpbal)
        {
            ob1<<tinpid<<" "<<tinpname1<<" "<<tinpname2<<" "<<tinpdob<<" "<<tinpmob<<" "<<tinpemail<<" "<<tinptype<<" "<<tinpaadhaar<<" "<<tinpbranch<<" "<<tinpbal<<endl;
            ob1.close();
            ob1.open("account info.txt",ios::app);
        }
        ob1.close();
        ob2.close();
        if(flag!=1)
            cout<<"Invalid Account ID\n";
        system("pause");
        return 0;
    }

};




int main()
{
    int ch;
    new_user p;
    existing_user q;

    while(1)
    {
        system("cls");
        cout<<"                           WElCOME                           \n\n";
        cout<<"1- Create Account\n2- Check Balance\n3- Deposit\n4- Withdraw\n5- Exit\nPlease Select your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: p.create();


                    p.ob1<< " "<<p.name <<" "<<p.dob<<" " <<p.mob <<" "<<p.email <<" "<<p.type <<" "<<p.aadhaar<<" "<<p.branch<<" "<<p.bal<<endl;
                    p.ob1.close();
                    break;

            case 2: q.display();
                    break;

            case 3: q.deposit();
                    break;

            case 4: q.withdraw();
                    break;

            case 5: exit(0);
                    break;
        }
    }

    return 0;
}

