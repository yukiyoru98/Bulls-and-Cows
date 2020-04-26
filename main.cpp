#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    
    int reply;//for asking whether to restart or end after game finishes
    srand((unsigned)(time(NULL)));//random seed
    do{
        int A=0, B=0;//save the number of As and Bs
        int answer[4];//save answer
        int input;//temporarily save user's guess
        
        for(int i=0; i<=3; i++){//randomly pick four numbers as answer
            
            answer[i]=1+rand()%9;//assign each number to the corresponding position in answer[i]
            for(int j=0; j<i; j++){//check if the number repeats
                if(answer[i]==answer[j]){
                    i--;
                    break;;//after break, i will +1 and return to the same position in answer[i]
                    
                }
            }
        }
        
        while(A!=4){//the guessing process starts and keeps operating until 4A0B
            A=0;
            B=0;//everytime before guessing, reset A and B
            int guess[4];//
            cout << "Please guess four numbers from 1~9(no number shall repeat):";//prompt for guess
            cin >> input;//read input
            for(int i=0; i<=3; i++){//assign input to guess[i]
                if(i==0){//assign first digit
                    guess[i]=input/1000;
                }
                else{//assign second, third, fourth digit
                    guess[i]=(input/static_cast<int>(pow(10,3-i)))%10;//pow returns double, but % uses integer
                }
                if(guess[i]==0){//avoid 0
                    cout << "There should not be zeros, please try again:";
                    i=(-1);//i will become 0 after this round and restart from first digit
                    cin >> input;//read input again
                    continue;//reassign
                }
                for(int j=0; j<i; j++){//check if input includes repeated numbers
                    if(guess[i]==guess[j]){
                        cout << "No number shall repeat, please try again:";
                        i=(-1);//i will become 0 after this round and restart from first digit
                        cin >> input;//read input again
                        break;//reassign
                    }
                }
                
            }
            for(int i=0; i<=3; i++){//check if guess matches answer
                for(int j=0; j<=3; j++){
                    if(guess[i]==answer[j]){
                        if(i==j)    A++;//if same position then A++
                        else    B++;//different position then B++
                    }
                }
            }
            
            cout << A << 'A' << B << 'B' << endl;//print result
        }
        cout << "You win!\n";//when 4A0B, user wins
        cout << "Enter ""0"" to restart or any other character to end:";
        cin >> reply;
    }while(reply==0);//if reply is 0 then start a new game
    system("pause");
    return 0;
}


