#include <iostream>
using namespace std;
// int maze(int cr, int cc, int er, int ec)
// {
//     int rightways = 0;
//     int downways = 0;
//     if(cr==er  && cc==ec){
//         return 1;
//     }
//     if (cr == er) {
//        rightways += maze(cr , cc+1 , er , ec );
//        }
//     if (cc == ec){
//         downways += maze(cr + 1, cc, er, ec);
//     }
//     if(cr<er  && cc<ec){
//         rightways += maze(cr , cc+1 , er , ec );
//         downways += maze(cr + 1, cc, er, ec);
//     }
//     int totalways = rightways + downways;
//     return totalways;
// }
int maze(int sr, int sc ,int er,int ec){
    if(sr>er || sc>ec) return 0;
    if(sr == er && sc == ec) return 1;
    int rightways = maze(sr,sc+1,er,ec);
    int downways= maze(sr+1,sc,er,ec);
    int totalways = rightways + downways;
    return totalways;
}
void printpath(int sr, int sc ,int er,int ec,string s){
    if(sr>er || sc>ec) return;
    if(sr == er && sc == ec) {
        cout<<s<<endl;
        return;
    }
    printpath(sr,sc+1,er,ec,s+'R');
    printpath(sr+1,sc,er,ec,s+'D');
}
int main()
{
    int n;
    cout<<"ENTER NUMBER OF ROWS IN MAZE :   ";
    cin>>n;
    int m;
    cout<<"ENTER  NUMBER OF COLUMN IN MAZE :   ";
    cin>>m;
    int noOfways = maze(1, 1, n, m);
    cout<<" the number of ways "<< noOfways<<endl;
    
    printpath(1, 1, n, m,"");
    return 0;
}