#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int coloumn;
char token='x';
bool tie =false;
string n1="";  //for player1
string n2="";  //for player2

   void functionOne(){
   
    cout<<"     |        |     \n";
    cout<<"  "<<space[0][0]<<"  |    "  <<space[0][1]<<   "   |   "<<space[0][2]<<"  \n";
    cout<<"     |        |     \n";
    cout<<"--------------------\n";
    cout<<"     |        |     \n";
    cout<<"  "<<space[1][0]<<"  |    "  <<space[1][1]<<   "   |   "<<space[1][2]<<"  \n";
    cout<<"     |        |     \n";
    cout<<"--------------------\n"; 
    cout<<"     |        |     \n";
    cout<<"  "<<space[2][0]<<"  |    "  <<space[2][1]<<   "   |   "<<space[2][2]<<"  \n";
    cout<<"     |        |     \n";
}

void functionTwo(){
    int digit;
    int n1;
    int n2;

    if(token== 'x'){
        cout<<n1<<"please enter: ";
        cin>>digit;
    }

    if(token== '0'){
        cout<<n2<<"please enter: ";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        coloumn=0;
    }
    if(digit==2){
        row=0;
        coloumn=1;
    }
    if(digit==3){
        row=0;
        coloumn=2;
    }
    if(digit==4){
        row=1;
        coloumn=0;
    }
    if(digit==5){
        row=1;
        coloumn=1;
    }
    if(digit==6){
        row=1;
        coloumn=2;
    }
    if(digit==7){
        row=2;
        coloumn=0;
    }
    if(digit==8){
        row=2;
        coloumn=1;
    }
    if(digit==9){
        row=2;
        coloumn=2;
    } else{
        cout<<"invalid!!!"<<endl;
    }

    if(token=='x' && space[row][coloumn]!='0' && space[row][coloumn]!='0'){

    space[row][coloumn]='x';
    token='0';
    } else if (token=='0' && space[row][coloumn]!='0' && space[row][coloumn]!='0'){

        space[row][coloumn]='0';
    token='x';
    } else{
        cout<<"no empty space"<<endl;
        functionTwo();
    }
    functionOne();
}
bool functionThree(){
    for(int i=0; i<3; i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j] != 'x' && space[i][j] != '0'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}

int main(){

     cout<<"enter the name of player 1: "<<endl;
    getline(cin,n1);
    cout<<"enter the name of player 2: "<<endl;
    getline(cin,n2);
    cout<<n1<< " is player 1 and "<<n2<<" is player 2"<<endl;

    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token == 'x' && tie == false){

        cout<<n2<<" wins"<<endl;

    } else if(token == '0' && tie == false){

        cout<<n1<<" wins"<<endl;

    } else{

        cout<<"It's a draw."<<endl;

    }
}
