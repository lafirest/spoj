#include <iostream>  


using namespace std;  
int main(int argc, char* argv[]) {  
    int n;  
    cin >> n;  


    while(n!=-1) {  
        int *p = new int[n];  
        int total = 0;  
        int avg = 0;  
        for (int i = 0; i < n; i++) {  
            cin >> p[i];  
            total += p[i];  
        }  
        if ((total % n) != 0) {  
            cout << "-1" << endl;  
        } else {  
            avg = total / n;  
            int move = 0;  
            for (int i = 0; i < n; i++) {  
                if (p[i] < avg) {  
                    move += avg-p[i];  
                }  
            }  
            cout << move << endl;  
        }  
        delete p;  
        cin >> n;  
    }  
}  
