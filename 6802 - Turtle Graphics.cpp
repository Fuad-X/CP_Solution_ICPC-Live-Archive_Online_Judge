#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int x, y;
        cin >> x >> y;
        string str;
        cin >> str;
        int arr[64][64] = {0};
        
        int dir = 1;
        
        int count = 0;
        for(int j=0; j<str.length(); j++)
        {
            if(str[j] == 'R')
            {
                dir+=1;
                if(dir > 4) dir = 1;
            }
            else if(str[j] == 'L')
            {
                dir-=1;
                if(dir < 1) dir = 4;
            }
            else
            {
                if(dir == 1) y++;
                else if(dir == 2) x++;
                else if(dir == 3) y--;
                else if(dir == 4) x--;
                if(arr[x][y] == 0) arr[x][y] = 1;
                else count++;
            }
        }
        cout << "Case #"<< i << ": "<< x << " " << y << " " << count << endl;
    }
   
   return 0;
}
