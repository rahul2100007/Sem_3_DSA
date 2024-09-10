#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Function to calculate capital gain or loss using LIFO (Stack)
int calculateLIFO(stack<int> &purchasePrices, int sellingPrice, int sharesSold) {
    int capitalLoss = 0;
    int sharesToSell = sharesSold;
    while (sharesToSell > 0 && !purchasePrices.empty()) {
        int purchasePrice = purchasePrices.top();
        purchasePrices.pop();
        capitalLoss += (purchasePrice - sellingPrice) * 100; // Each entry represents 100 shares
        sharesToSell -= 100;
    }
    return capitalLoss;
}

// Function to calculate capital gain or loss using FIFO (Queue)
int calculateFIFO(queue<int> &purchasePrices, int sellingPrice, int sharesSold) {
    int capitalGain = 0;
    int sharesToSell = sharesSold;
    while (sharesToSell > 0 && !purchasePrices.empty()) {
        int purchasePrice = purchasePrices.front();
        purchasePrices.pop();
        capitalGain += (sellingPrice - purchasePrice) * 100; // Each entry represents 100 shares
        sharesToSell -= 100;
    }
    return capitalGain;
}

int main() {
    // LIFO Calculation (Using Stack)
    stack<int> lifoPurchases;
    lifoPurchases.push(10);  // 100 shares in Jan at Rs. 10 per share
    lifoPurchases.push(30);  // 100 shares in Apr at Rs. 30 per share
    lifoPurchases.push(50);  // 100 shares in Sept at Rs. 50 per share

    int lifoLossInJune = calculateLIFO(lifoPurchases, 20, 100);  // Sold 100 shares in Jun at Rs. 20
    int lifoLossInNov = calculateLIFO(lifoPurchases, 30, 100);   // Sold 100 shares in Nov at Rs. 30

    cout << "Total Capital Loss (LIFO): Rs. " << lifoLossInJune + lifoLossInNov << endl;

    // FIFO Calculation (Using Queue)
    queue<int> fifoPurchases;
    fifoPurchases.push(10);  // 100 shares in Jan at Rs. 10 per share
    fifoPurchases.push(30);  // 100 shares in Apr at Rs. 30 per share
    fifoPurchases.push(50);  // 100 shares in Sept at Rs. 50 per share

    int fifoGainInJune = calculateFIFO(fifoPurchases, 20, 100);  // Sold 100 shares in Jun at Rs. 20
    int fifoGainInNov = calculateFIFO(fifoPurchases, 30, 100);   // Sold 100 shares in Nov at Rs. 30

    cout << "Total Capital Gain (FIFO): Rs. " << fifoGainInJune + fifoGainInNov << endl;

    return 0;
}