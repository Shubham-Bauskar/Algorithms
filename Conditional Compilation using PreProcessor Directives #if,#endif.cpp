#include<iostream>
using namespace std;
#define n 20
// PUT N=21 FOR AVOIDING COMPILATION.
int main()
{
    #if(n%2==0)
    {
        cout<<"Value of N="<<n<<endl;
        // endl clears buffer and add newline , but only '\n' add newline.
        cout<<"N is Even"<<endl;
    }
    #endif
    cout<<"Inside MAIN";
    return 0;
}

