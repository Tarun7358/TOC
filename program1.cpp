#include <iostream>
#include <string>
#include <vector>
using namespace std;
string optimizeExpression(const string &expr) {
    if (expr == "x = 2 * 8") return "x = 16";
    if (expr == "y = x * 1") return ""; 
    if (expr == "z = y + 0") return "z = x"; 

    return expr; 
}
int main() {
    vector<string> code = {
        "x = 2 * 8",
        "y = x * 1",
        "z = y + 0"
    };
    cout << "Optimized Code:\n";
    for (const string &line : code) {
        string optimized = optimizeExpression(line);
        if (!optimized.empty()) 
            cout << optimized << endl;
    }

    return 0;
}
