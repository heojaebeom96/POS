#include <iostream>
#include <string>
#include "human.h"

using namespace std;

void HumanData :: Exchange() 
{
    string human_n[3] = { "오전알바", "오후알바", "야간알바" };
    cout << "-----알바목록-----" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "-" << human_n[i] << endl;
    }
    while (true)
    {
        cout << "교체할 담당자를 입력하시오. : ";
        cin >> exchange_n;
        for (int i = 0; i < 3; i++)
        {
            if (human_n[i] == exchange_n)
            {
                present_n = exchange_n;
                cout << "변경완료" << endl;
                break;
            }
        }
        if (present_n != exchange_n)
            cout << "등록되지 않은 알바생입니다." << endl;
        else
            break;
    }
    cout << "현재 담당자 : " << present_n << endl << endl;
}

void HumanData::Lock()
{
    string human_narray[3] = { "오전알바", "오후알바", "야간알바" };
    string name;
    cout << "잠금되었습니다. 잠금을 해제하려면 담당자 이름을 적어주세요." << endl;

    while (true)
    {
        cin >> human_n;
        for (int i = 0; i < 3; i++)
        {
            if (human_narray[i] == human_n)
            {
                name = human_n;
                cout << "잠금이 해제되었습니다.\n" << endl;
                break;
            }
        }
        if (name != human_n) {}
        else
            break;
    }
}