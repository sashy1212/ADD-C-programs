#include <iostream>
using namespace std;

int main()
{
    int c=1,i,j,k;
    int n3=0,n1=1,n2=0;
    int rows;
    cout<<"enter number of rows "<<endl;
    cin>>rows;

    

    for(i = 0; i <=rows; ++i)
    {
    	
        for(j = rows; j >=i; --j)
        {
            cout <<" ";
        }
        for(k=1;k<=i;++k)
        {
        	
        	cout<<n2<<" ";
        	n3=n1+n2;        	
        	n1=n2;
        	n2=n3;
        	
        	
		}
		
        cout << endl;
    }
    
    return 0;
}
