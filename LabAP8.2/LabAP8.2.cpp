#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string processStringToSpace(const string& str) {
    stringstream ss(str);
    string token, result;

    while (ss >> token) {
        size_t dotPos = token.find('.');//перевіряє чи є крапка

        if (dotPos != string::npos && dotPos + 1 < token.length() && isdigit(token[dotPos + 1])) { //чи є цифра після крпаки
            size_t digitCount = 0;
            for (size_t i = dotPos + 1; i < token.length(); ++i) {
                if (isdigit(token[i])) {
                    digitCount++;
                    if (digitCount > 2) { //чи цифер після крапки більше ніж 2
                        token.erase(i); /*решта видаляється*/
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }

        result += token + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string processedString = processStringToSpace(str);
    cout << "Processed string: " << processedString << endl;

    return 0;
}