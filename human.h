#include <iostream>
#include <string>

using namespace std;

class HumanData	// 담당자정보 클래스
{
private:
    string human_n;	// human_n: 사람이름
    string exchange_n;    // exc_name; 교체할 사람
    string present_n;    // pre_name; 교체될 사람
    int size = 3;
public:
    HumanData() {}
    void Exchange();
    void Lock();
};