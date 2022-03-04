#include <iostream>
using namespace std;

string arr[10]{" "," "," "," "," "," "," "," "," "," "};
int lastep[10];
int pos = 0;
int count = 0;

//move robot n spaces to the right
void right (int n) {
    if(pos+n<10)
    {
        pos = pos + n;
        lastep[count++]=pos;
        
    }
    else
        cout<<"Robot is out of bounds." << endl;
}

//move robot n spaces to the left
void left (int n) {
    if (pos-n>0)
    {
        pos-= n;
        lastep[count++]=pos;
    }
    else
        cout<<"Robot is out of bounds." << endl;
}

//display robot's position
void display() {
    cout<<"Robot is now at position " << pos << "." << endl;
}

//reboot
void reboot(){
    pos=0;
    arr[pos]="^";
}

//show array
void showarr(){

    cout<<"____________________";
    cout<<endl;

    cout<<"|";
    for (int i=0; i<10; i++)
    {
        arr[i]=" ";
        arr[pos]="^";
        cout << arr[i];
        cout << "|";
    }

    cout << endl;
    cout << "____________________";
    cout << endl;
    cout <<" 0 1 2 3 4 5 6 7 8 9"<<endl;
    
}

// cancel the last n operations
void cancel(int n)
{
    if (count > n)
    {
        count-=(n+1);
        pos = lastep[count];
    }
    else
    {
        pos=0;
        count=0;
    }
}

// replay the last n operations that have been cancelled
void replay(int n)
{
    if (count+n<10)
    {
        count+=n;
        pos=lastep[count];
    }
    else
    {
        pos=9;
        count=9;
    }
}


int main() {
    int op, n;
    arr[pos] = "^";
    while(1){
        cout<<"1. Right " << endl;
        cout<<"2. Left "<< endl;
        cout<<"3. Display "<< endl;
        cout<<"4. Reboot "<< endl;
        cout<<"5. Show Array "<< endl;
        cout<<"6. Cancel "<< endl;
        cout<<"7. Replay " << endl;
        cout<<"8. Exit "<< endl;
        cout<<"Enter choice: "<< endl;
        cin>>op;
        
        switch(op)
        {
            case 1:
                cout<<"Enter number of cells: ";
                cin>>n;
                right(n);
                break;
            case 2:
                cout<<"Enter number of cells: ";
                cin>>n;
                left(n);
                break;
            case 3:
                display();
                break;
            case 4:
                reboot();
                break;
            case 5:
                showarr();
                break;
            case 6:
                cout<<"Enter number of operations: ";
                cin>>n;
                cancel(n);
                break;
            case 7:
                cout<<"Enter number of operations: ";
                cin>>n;
                replay(n);
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid option."<< endl;
        }
        cout<< endl;
    }

    return 0;
}
