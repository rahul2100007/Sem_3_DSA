#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

stack<int> i_ball;

bool push_ball(int x) {
    if (i_ball.size() >= 9) {
        cout << "Cannot add more than 9 balls!" << endl;
        return false;
    }
    i_ball.push(x);
    return true;
}

void pop_ball() {
    if (i_ball.empty()) {
        cout << "No balls to delete!" << endl;
        return;
    }
    i_ball.pop();
}

void displayBalls() {
    stack<int> temp = i_ball;
    vector<int> balls;
    
    // Transfer elements to a vector to display them
    while (!temp.empty()) {
        balls.push_back(temp.top());
        temp.pop();
    }
    
    // Display elements in reverse order to match stack order
    for (auto it = balls.rbegin(); it != balls.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter the sequence of ball numbers and operations (e.g., '1 8 9 7 2 3'): ";
    getline(cin, input);

    stringstream ss(input);
    vector<int> numbers;
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    // Simulate the operations
    for (int i = 0; i < numbers.size(); ++i) {
        if (i == 4 || i == 5) { // Pop operations at 5th and 6th positions
            pop_ball();
        } else {
            push_ball(numbers[i]);
        }
    }

    // Display the final state of the basket
    cout << "Final state of the basket: ";
    displayBalls();

    return 0;
}