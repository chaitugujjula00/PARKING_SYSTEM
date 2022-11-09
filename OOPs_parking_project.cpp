#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int total=0;
class bikes;
class cars;
class parking{
    public:
    string name;
    string cplate;
    float intime;
    parking(){
        name="";
        cplate="";
        intime=0;
    }
};
class bikes: private parking{
    friend void entry(bikes*);
    friend int remove(bikes*,int);
    friend void info(bikes*,cars*);
    friend void check(bikes*,cars*);
    public:
    bikes(){
        name="";
        cplate="";
        intime=0;
    }
    bikes(string a,string b,float c){
        name=a;
        cplate=b;
        intime=c;
    }
};
class cars:private parking{
    friend void entry(cars*);
    friend int remove(cars*,int);
    friend void info(bikes*,cars*);
    friend void check(bikes*,cars*);
    public:
    cars(){
        name="";
        cplate="";
        intime=0;
    }
    cars(string a,string b,int c){
        name=a;
        cplate=b;
        intime=c;
    }
};
void entry(bikes b[25]){
    string nb,cb;
    int inb; 
    cout<<"Enter drivers name:";
    cin>>nb;
    cout<<"Enter vehicle number :";
    cin>>cb;
    cout<<"Enter in Time in 24hrs format (Enter nearest hour 12.20=12) :";
    cin>>inb;
    bikes *newb= new bikes(nb,cb,inb);
    int i=0;
    while(b[i].name!=""&&i<25){
        i++;
    }
    if(i<25){
    b[i]=*newb;
    cout<<"Entry successfull Please park at location :"<<i+1<<"B"<<endl;
    cout<<"Cost for each 1 Hour is 30Rs. to be payed at leaving time"<<endl;
    }
    else
    cout<<"No Parking space"<<endl;
}
void entry(cars c[25]){
    string nc,cc;
    int inc;
    cout<<"Enter drivers name :";
    cin>>nc;
    cout<<"Enter vehicle number :";
    cin>>cc;
    cout<<"Enter in Time in 24hrs format (Enter nearest hour 12.20=12) :";
    cin>>inc;
    cars *newc= new cars(nc,cc,inc);
    int i=0;
    while(c[i].name!=""&&i<25){
        i++;
    }
    if(i<25){
    c[i]= *newc;
    cout<<"Entry successfull Please park at "<<i+1<<"C"<<endl;
    cout<<"Cost for each 1 Hour is 50Rs. to be payed at leaving time"<<endl;
    }
    else
    cout<<"No Parking space"<<endl;
    return;
}
int remove(bikes b[25],int sumb){
    string checknum;
    cout<<"Enter the vehicle number :";
    cin>>checknum;
    int i=0;
    while(b[i].cplate!=checknum&&i<25){
        i++;
    }
    if(i<25){
        float outb;
        cout<<"Enter OUT Time in 24hrs format (Enter nearest hour 12.20=12) :";
        cin>>outb;
        float time=outb-b[i].intime;
        cout<<endl<<"The amount to be paid :"<<time*30<<endl;
        cout<<"Thanks for visiting!!!!"<<endl;
        sumb=sumb+(time*30);
        fstream s;
        s.open("parking.txt",ios::app);
        cout.setf(ios::left, ios::adjustfield);
        s<<setw(20)<<b[i].name<<setw(20)<<b[i].cplate<<setw(10)<<b[i].intime<<setw(10)<<outb<<setw(10)<<"BIKE"<<setw(10)<<time*30<<endl;
        s.close();
        b[i].name="";
        b[i].cplate="";
        b[i].intime=0;
    }
    else
    cout<<"NO VEHICLE FOUND"<<endl;
    return sumb;
}
int remove(cars c[25],int sumc){
    string checknum;
    cout<<"Enter the vehicle number :";
    cin>>checknum;
    int i=0;
    while(c[i].cplate!=checknum&&i<25){
        i++;
    }
    if(i<25){
        float outc;
        cout<<"Enter OUTPUT Time in 24hrs format (Enter nearest hour 12.20=12) :";
        cin>>outc;
        float time=outc-c[i].intime;
        cout<<endl<<"The amount to be paid :"<<time*50<<endl;
        sumc=sumc+(time*50);
        cout<<"Thanks for visiting!!!!"<<endl;
        fstream s;
        s.open("parking.txt",ios::app);
        cout.setf(ios::left, ios::adjustfield);
        s<<setw(20)<<c[i].name<<setw(20)<<c[i].cplate<<setw(10)<<c[i].intime<<setw(10)<<outc<<setw(10)<<"CAR"<<setw(10)<<time*50<<endl;
        s.close();
        c[i].name="";
        c[i].cplate="";
        c[i].intime=0;
        return sumc;
    }
    else
    cout<<"NO VEHICLE FOUND"<<endl;
}
void info(bikes b[25],cars c[25]){
    cout.setf(ios::left, ios::adjustfield);
    cout<<setfill(' ')<<setw(30)<<"Driver name"<<setw(20)<<"Vehicle number"<<setw(10)<<"In Time"<<setw(10)<<"TYPE"<<endl;
    for(int i=0;i<25;i++){
        if(b[i].name!=""){
            cout<<setw(30)<<b[i].name<<setw(20)<<b[i].cplate<<setw(10)<<b[i].intime<<setw(10)<<"BIKE"<<endl;
        }
    }
    for(int i=0;i<25;i++){
        if(c[i].name!=""){
            cout<<setw(30)<<c[i].name<<setw(20)<<c[i].cplate<<setw(10)<<c[i].intime<<setw(10)<<"CAR"<<endl;
        }
    }
}
void check(bikes b[25],cars c[25]){
    string checknumber;
    cout<<endl<<"Enter the vehicle number to check : ";
    cin>>checknumber;
    int i=0;
    while(b[i].cplate!=checknumber&&i<25){
        i++;
    }
    if(i<25){
        cout.setf(ios::internal,ios::adjustfield);
        cout<<"VEHICLE DETAILS"<<endl;
        cout<<"Vehicle Type :BIKE"<<endl;
        cout<<"Driver name :"<<b[i].name<<endl;
        cout<<"Vehicle number :"<<b[i].cplate<<endl;
        cout<<"In Time :"<<b[i].intime<<endl;
    }
    else{
        int j=0;
        while(c[i].cplate!=checknumber&&j<25){
            j++;
        }
        if(j<25){
        cout.setf(ios::internal);
        cout<<setw(50)<<"VEHICLE DETAILS"<<endl;
        cout<<"Vehicle Type : CAR"<<endl;
        cout<<"Driver name :"<<c[j].name<<endl;
        cout<<"Vehicle number :"<<c[j].cplate<<endl;
        cout<<"In Time :"<<c[j].intime<<endl;
        }
        else{
            cout<<"No vehicle with such number is parked now!!!!!"<<endl;
        }
    }
}
void moneyearned(int sumc,int sumb){
    total=sumc+sumb;
    cout.setf(ios::left, ios::adjustfield);
    cout<<setfill('_')<<setw(20)<<"CARS"<<setw(20)<<"BIKES"<<setw(20)<<"TOTAL"<<endl;
    cout<<endl<<setfill(' ')<<setw(20)<<sumc<<setw(20)<<sumb<<setw(20)<<total<<endl;
}
void giveoutput(){
    std::ifstream f("parking.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}
int main(){
    int sumb=0;
    int sumc=0;
    fstream s;
    s.open("parking.txt",ios::app);
    cout.setf(ios::left, ios::adjustfield);
    s<<setw(20)<<"DRIVER NAME"<<setw(20)<<"VEHICLE NUMBER"<<setw(10)<<"IN TIME"<<setw(10)<<"OUT TIME"<<setw(10)<<"TYPE"<<setw(10)<<"COST"<<endl;
    s.close();
    int choice;
    bikes b[25];
    cars c[25];
    while(true){
        string new1="";
        cout<<setw(60)<<setfill('-')<<new1<<endl;
        cout<<"1.ENTRY POINT"<<endl;
        cout<<"2.EXIT POINT"<<endl;
        cout<<"3.TO SEARCH ANY VEHICLE"<<endl;
        cout<<"4.INFO PORTAL"<<endl;
        cout<<"5.TOTAL MONEY EARNED"<<endl;
        cout<<"6.TOTAL LIST OF VEHICLES IN A DAY"<<endl;
        cout<<"7.EXIT"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch(choice){
            case 1:
                int type;
                cout<<"       1.Bike            2.Car"<<endl;
                cout<<"Enter type of vehicle:";
                cin>>type;
                if(type==1){
                    entry(b);
                }
                else if(type==2){
                    entry(c);
                }
                break;
            case 2:
                int type2;
                cout<<"       1.Bike            2.Car"<<endl;
                cout<<"Enter type of vehicle:";
                cin>>type2;
                if(type2==1){
                    int costb=remove(b,sumb);
                    sumb=costb;
                }
                else if(type2==2){
                    int costc=remove(c,sumc);
                    sumc=costc;
                }
                break;
            case 3:
                check(b,c);
                break;    
            case 4:
                info(b,c);
                break;
            case 5:  
                moneyearned(sumc,sumb);
                break;      
            case 6:
               giveoutput();
               break;
            case 7:   
                exit(0);
                break;
        }

    }
}
