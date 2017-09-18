#include <fstream>
using namespace std;

int numCoins(int coins[], int price) {
    int coinsrequired[price+1];
    coinsrequired[0] = 0;
    for (int i = 1; i <= price; i++) {
        coinsrequired[i] = 2147483647;
    }
    for (int i = 1; i <= price; i++) {
        for (int j = 0; j < 4; j++) {
            if (coins[j] <= i) {
                int dummy_var = coinsrequired[i-coins[j]];
                if (dummy_var + 1 < coinsrequired[i]) {
                    coinsrequired[i] = dummy_var + 1;
                }
            }
        }
    }
    return coinsrequired[price];
}

int main () {
    ifstream input;
    ofstream output;
    input.open ("coins2.in");
    output.open ("coins2.in");
    int x;
    input>>x;
    int coinval[4];
    for (int j = 0;j < 4;j++) {
        input>>coinval[j];
    }
    output<<numCoins(coinval,x);
}

