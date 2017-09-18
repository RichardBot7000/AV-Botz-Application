#include <fstream>
using namespace std;

int main () {
    ifstream input;
    ofstream output;
    input.open ("coins.in");
    output.open ("coins.out");
    float c,x;
    int m,q,d,n,p;
    input>>c;
    x = 100 * c;
    m = x;
    q = m/25;
    m = m - q*25;
    d = m/10;
    m = m - d * 10;
    n = m/5;
    m = m-n*5;
    p = m;
    output<<q+d+n+p;

}
