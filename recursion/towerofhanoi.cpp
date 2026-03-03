#include<iostream>
#include<cmath>
using namespace std;
void towerofhanoi(int n, char source, char aux, char destination){
    //n=no of disks
    //aux=helper stand
    if(n==1){
        cout<<"Moved disk A from "<<source<<" To "<<destination<<endl;
        return;
    }
    towerofhanoi(n-1, source, destination, aux);//n-1,s,d,a
    cout<<"Move disk from "<<source<<" to "<<destination<<endl;
    towerofhanoi(n-1, aux, source, destination);//n-1,a,s,d

}
int main(){
    int n;
    cout<<"enter number of disks: "<<endl;
    cin>>n;
    towerofhanoi(n,'A','B','C');
    cout<<"NUMBER OF STEPS: "<<pow(2,n)-1;
    return 0;
}