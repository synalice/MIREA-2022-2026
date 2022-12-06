#include <iostream>
#include <cmath>

using namespace std;

int main()
{    
    int a1 = 0;
    int a2 = 0;
    
    cout << "Введите два числа: ";    
    cin >> a1 >> a2;
    
    if (a1 > a2)
    {
        int tmp = a2;
        a2 = a1;
        a1 = tmp;
    }
    
    cout << "Пифагоровы тройки от " 
        << a1 << " до " << a2 << endl;
    for (int i = a1; i <= a2; i++)
    {
        for (int j = a1; j <= a2; j++)
        {
            for (int k = a1; k <= a2; k++)
            {
                if (i*i+j*j==k*k)  
                    cout << "(" << i << "," << j << "," << k << ")" << endl; 
            }
        }
    }
   
    return 0;
}