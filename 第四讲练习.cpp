#include <iostream>
#include <string>
using namespace std;

class CPU {
public:
    // 位域来表示各项信息
    struct {
        unsigned int clockFrequency : 12; 
        unsigned int wordLength : 1;      
        unsigned int coreCount : 2;       
        unsigned int hyperThreading : 1;  
    } info;

    // 构造函数
    CPU(unsigned int freq, unsigned int word, unsigned int cores, unsigned int hyperThread)
        : info{ freq, word, cores, hyperThread } {}

    // 显示CPU信息
    void displayInfo() {
        cout << "Clock Frequency: " << info.clockFrequency << " MHz\n";
        cout << "Word Length: " << ((info.wordLength == 0) ? "32-bit" : "64-bit") << "\n";
        cout << "Core Count: ";
        switch (info.coreCount) {
        case 0:
            cout << "Single Core\n";
            break;
        case 1:
            cout << "Dual Core\n";
            break;
        case 2:
            cout << "Quad Core\n";
            break;
        default:
            cout << "Invalid Core Count\n";
            break;
        }
        cout << "Hyper-Threading Support: " << ((info.hyperThreading == 1) ? "Yes" : "No") << "\n";
    }
};

int main() {
    CPU cpu(2500, 1, 2, 1); // 示例CPU对象

    cpu.displayInfo();
    cout << "Size of CPU object: " << sizeof(CPU) << " bytes\n";

    return 0;
}
