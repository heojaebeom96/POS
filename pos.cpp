// POS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "item.h"
#include "extitem.h"

using namespace std;

void showMenu()
{
    cout << "어서오세요, ㅇㅇ편의점입니다.\n";
    cout << "1. 카테고리 등록\n";
    cout << "2. 상품등록\n";
    cout << "3. 상품목록\n";
    cout << "4. 판매하기\n";
    cout << "5. 금고입금\n";
    cout << "6. 영수증기록\n";
    cout << "7. 담당교대\n";
    cout << "8. 금액보기\n";
    cout << "9. 오늘의 이벤트\n";
    cout << "10. 잠그기\n";
    cout << "0. 종료\n";
}

int main()
{
    HumanData don;
    Manager c;
    showMenu();
    c.today();
    while (true)
    {
        bool tf = true;
        cout << ">>메뉴 : ";
        string menu;
        cin >> menu;
        if (menu == "0")
        {
            cout << "종료하겠습니다.\n";
            system("pause");
            return 0;
        }
        else if (menu == "1")
            c.addItemType();
        else if (menu == "2")
            c.add();
        else if (menu == "3")
            c.showItems();
        else if (menu == "4")
            c.sell();
        else if (menu == "5")
            c.deposit();
        else if (menu == "6")
            tf = c.receipt(tf);
        else if (menu == "7")
            don.Exchange();
        else if (menu == "8")
            c.money_list();
        else if (menu == "9")
            c.today_event();
        else if (menu == "10")
            don.Lock();
        else
            cout << "잘못 입력하셨습니다.\n" << endl;    // 메뉴선택의 실수 방지용
    }
}
