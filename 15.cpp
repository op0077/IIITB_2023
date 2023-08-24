#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    extern char **environ;
    for (int i = 0; environ[i] != nullptr; ++i) 
        cout<<environ[i]<<endl;
    return 0;
}
