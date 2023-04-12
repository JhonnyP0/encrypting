#include <iostream>
#include <fstream>

using namespace std;

int bordering(int i)
{
    if(i>126)
        {
            int m;
            m=i-126;
            i=33+m;
        }
    return i;
}

void encrypting(string inputvalue)
{
    cout<<"\n"<<" | ";
    for(int x=0; x<inputvalue.length();x++)
    {
        int i =int(inputvalue[x]);
        cout<<i<<" | ";
    }

    //ASCI encrypting
    cout<<"\n"<<" | ";
    for(int x=0; x<inputvalue.length();x++)
    {
        int i =int(inputvalue[x]);
        i+=10;
        cout<<bordering(i)<<" | ";
    }

    //STRING encrypting
    cout<<"\n"<<" |  ";
    for(int x=0; x<inputvalue.length();x++)
    {
        int i =int(inputvalue[x]);
        i+=10;
        char afterEnc=char(bordering(i));
        cout<<afterEnc<<"  |  ";
    }
    cout<<"\n";
}

void filesaccessing(string filename)
{
    fstream textFile;
    textFile.open(filename,ios::in);
    if(textFile.good()==true)
    {
        string DataChain;
        cout<<"access granted";
        textFile>>DataChain;               //need to change method of saving data to variable bcs white chars stopping code
        textFile.close();
        encrypting(DataChain);
    }
    else
    {
        cout<<"access denied or cant find file";
        textFile.close();
    }


}

void welcomePage()
{
    cout<<"Please choose option of encrypting:\n1.from file\n2.from terminal"<<endl;
    int switchval=0;
    cin>>switchval;
    switch(switchval)
    {
        case 1:
        {
            cout<<"encrypting from file has been choosen\nplease enter file directory or if file is in folder with app enter name of file"<<endl;
            string filename;
            cin>>filename;
            filesaccessing(filename);
        }break;
        case 2:
        {
            string termSramb;
            cout<<"enter char chain to encrypt"<<endl;
            cin>>termSramb;
            encrypting(termSramb);
        }break;
        default:
        {
            cout<<"this option is not available in this moment";
        }break;
    }
}



int main()
{
    welcomePage();
    return 0;
}