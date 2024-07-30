#include <iostream>
#include <vector>
using namespace std;
vector<int> i_ball;
int ball_push()
{
    int ball;
    cout << "enter ball number:";
    cin >> ball;
    i_ball.push_back(ball);
};
int pop_ball()
{
    if (i_ball.size() > 0)
    {
        cout << "ball poped" << endl;
        i_ball.pop_back();
    }
};
void display(vector<int> &vec)
{
    int size = vec.size();
    cout<<"total balls are in your basket is:\t";
    cout<<"[";
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << "]" << endl;
}
int main()
{
    int choice;
    
    for (int k = 0; k < 9; k++)
    {
            cout << "1.push\n2.pop\n0.to end game and display score\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                ball_push();
                break;
            case 2:
                pop_ball();
                break;
            }
            if(choice==0){
                display(i_ball);
                cout << "\nexiting...";
                k=9;
            }
    }
}