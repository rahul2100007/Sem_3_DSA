#include <iostream>
#include <vector>
using namespace std;
vector<int> i_ball;
int ball_push()
{
    int ball;
        throw_ball:
            cout << "enter ball number:";
            cin >> ball;
            for (int k = 0; k < i_ball.size(); k++)
            {
                if (ball == i_ball[k])
                {
                    cout << "ball already exist" << endl;
                    goto throw_ball;
                }
            }
    i_ball.push_back(ball);
};
int pop_ball()
{
    if (i_ball.size() > 0)
    {  
        i_ball.pop_back();
    }
};
void display(vector<int> &vec)
{
    int size = vec.size();
    cout << "total balls are in your basket is:\t";
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << "]" << endl;
    cout << "Total " << i_ball.size() << " ball in basket :)" << endl;
}
int attempt_push()
{
    int x;
    cout << "How many ball you want to throw at this time:";
    cin >> x;
    if (x > 9 || i_ball.size() + x > 9)
    {
        cout << "you can't throw more then 9 ball because it has no space greter then '9' " << endl;
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            ball_push();
        }
    }
}
int attempt_pop()
{
    int x;
    cout << "How many ball you want to pop at this time:";
    cin >> x;
    cout << "ball poped" << endl;
    for (int j = 0; j < x; j++)
    {
        pop_ball();
    }
}
int main()
{
    int choice;
    cout << "Welcome to the ball game" << endl;
game:
    do
    {
        cout << "<1> push\n<2> pop\n<3> Display Score\n<9> Restart Game\n<0> To exit game\nENTER CHOICE:>:>>>";
        cin >> choice;
        switch (choice)
        {
        case 1:
            attempt_push();
            break;
        case 2:
            attempt_pop();
            break;
        case 3:
            display(i_ball);
            break;
        case 9:
            i_ball.clear();
            goto game;
        case 0:
            cout << "\nexiting...";
            exit(0);
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 0);
}