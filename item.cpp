#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include "item.h"

using namespace std;

void ItemData::setItem_n(string n) {
	item_n = n;
}
string ItemData::getItem_n() {
	return item_n;
}
void ItemData::setCategory_n(string n) {
	category_n = n;
}
string ItemData::getCategory_n() {
	return category_n;
}
void ItemData::setOption(string o) {
	option = o;
}
string ItemData::getOption() {
	return option;
}
void ItemData::setItem_p(int p) {
	item_p = p;
}
int ItemData::getItem_p() {
	return item_p;
}
void ItemData::setItem_a(int a) {
	item_a = a;
}
void ItemData::setTotalitem_a(int a) {
	item_a += a;
}
void ItemData::setSellitem_a(int a) {
	item_a -= a;
}
int ItemData::getItem_a() {
	return item_a;
}
void ItemData::setCash(int ch) {
	cash += ch;
}
void ItemData::setDedcash(int ch) {
	cash -= ch;
}
int ItemData::getCash() {
	return cash;
}
void ItemData::setCard(int cd) {
	card += cd;
}
int ItemData::getCard() {
	return card;
}
void ItemData::setSafe(int s) {
	safe += s;
}
int ItemData::getSafe() {
	return safe;
}
void ItemData::setMonth(int m) {
	month = m;
}
int ItemData::getMonth() {
	return month;
}
void ItemData::setDay(int d) {
	day = d;
}
int ItemData::getDay() {
	return day;
}

void Manager:: addItemType() {
    if (category == nullptr)
    {
        while (true)
        {
            cout << "카테고리 배열 크기 : ";
            cin >> size;
            if (size > 0)
            {
                category = new Manager[size];
                cout << "카테고리 배열이 생성되었습니다.\n";
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "0 이상의 수를 입력해주세요.\n";
            }
        }
    }
    if ((category_c != 0) && (size - category_c == 0))
    {
        cout << "더 이상 카테고리를 추가할 수 없습니다.\n" << endl;
        return;
    }
    cout << "카테고리 : ";
    string name;
    cin >> name;
    bool tf = true;
    for (int i = 0; i < category_c; i++)
    {
        if (category[i].category_n == name)
        {
            cout << "중복된 카테고리입니다.\n" << endl;
            tf = false;
            break;
        }
    }
    if (tf == true)
    {
        category[category_c].category_n = name;
        category[category_c].head = category[category_c].tail = nullptr;    // head, tail 초기화
        cout << category[category_c].category_n << " 카테고리 등록되었습니다.\n" << endl;
        category_c++;   // 다음 카데고리가 들어갈 자리위해 하나 증가
    }
}
void Manager::add() {
    cout << "상품을 등록합니다.\n먼저 카테고리를 입력하십시오. ";
    string c_name;
    cin >> c_name;
    for (int i = 0; i < category_c; i++)
    {
        if (category[i].category_n == c_name)
        {
            cout << c_name << " 카테고리에 어떤 상품을 등록하시겠습니까?\n";
            cout << "이름 : ";
            string name;
            cin >> name;
            ItemNode* ptr = category[i].head;    // 카테고리 내에서 같은 이름의 상품을 찾기 위한 포인터 변수
            while (ptr != nullptr)  // 상품 이름이 같은 것이 있는지 확인해주는 작업
            {
                if (ptr->data->getItem_n() == name)
                    break;
                ptr = ptr->next;
            }
            // 다를 경우 가격과 이벤트를 제시, 같을 경우 제시 안함
            int amount;
            if (ptr == nullptr) // 상품이름이 다를 때
            {
                Manager* node = new Manager;
                node->data->setItem_n(name);
                int price;
                while (true)
                {
                    cout << "가격(원) : ";
                    cin >> price;
                    if (price > 0)
                    {
                        node->data->setItem_p(price);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "제대로 적어주시길 바랍니다.\n";    // 가격을 0이하 또는 문자열로 했을 시 오류메시지
                    }
                }
                while (true)
                {
                    cout << "재고(개) : ";
                    cin >> amount;
                    if (amount > 0)
                    {
                        node->data->setItem_a(amount);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "제대로 적어주시길 바랍니다.\n";    // 재고를 0이하 또는 문자열로 했을 시 오류메시지
                    }
                }
                if (c_name == "초콜릿" && i_data.getMonth() == 2 && i_data.getDay() == 14)
                    node->data->setOption("발렌타인데이");
                else if (c_name == "사탕" && i_data.getMonth() == 3 && i_data.getDay() == 14)
                    node->data->setOption("화이트데이");
                else if (c_name == "빼빼로" && i_data.getMonth() == 11 && i_data.getDay() == 11)
                    node->data->setOption("빼빼로데이");
                else
                    node->data->setOption("없음");
                node->next = nullptr;
                if (category[i].head == nullptr)    // 물품 리스트가 없다면
                    category[i].head = category[i].tail = node;
                else    // 마지막 노드로 추가
                {
                    category[i].tail->next = node;  // 현재 마지막 노드의 뒤에 신규 노드 추가
                    category[i].tail = node;   // tail 포인터를 뒤로 이동
                }
                cout << "정상적으로 등록되었습니다.\n" << endl;
                return;
            }
            else    // 상품이름이 같을 때
            {
                ptr->data->setItem_n(name);
                while (true)
                {
                    cout << "재고(개) : ";
                    cin >> amount;
                    cin.ignore(1000, '\n');
                    if (amount > 0)
                    {
                        ptr->data->setTotalitem_a(amount);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "제대로 적어주시길 바랍니다.\n";    // 재고를 0이하 또는 문자열로 했을 시 오류메시지
                    }
                }
                cout << "정상적으로 등록되었습니다.\n" << endl;
                return;
            }
        }
    }
    cout << c_name << " 카테고리는 등록되어 있지 않습니다.\n" << endl;
}
int Manager::printItemlist(ItemNode* ptr) {
    int no = 0;
    while (ptr != nullptr)
    {
        cout << no + 1 << ". " << ptr->data->getItem_n() << " / " << ptr->data->getItem_p() << "원"
            << " / " << ptr->data->getItem_a() << "개" << " / 이벤트여부 : " << ptr->data->getOption() << endl;
        no++;
        ptr = ptr->next;
    }
    return no;
}
void Manager::showItems() {
    cout << "카테고리 : ";
    cin >> type;
    if (type == "all")
    {
        for (int i = 0; i < category_c; i++)
        {
            cout << "[" << category[i].category_n << "]" << endl;
            if (category[i].head != nullptr)    // 등록된 상품이 있다면
            {
                int num = printItemlist(category[i].head);
                cout << "상품 종류 : " << num << endl << endl;
            }
            else
                cout << "상품 종류 : 0\n" << endl;
        }
    }
    else
    {
        bool found = false; // 입력한 카데고리가 등록되었는 아닌지 체크하는 변수
        for (int i = 0; i < category_c; i++)
        {
            if (category[i].category_n == type)
            {
                cout << "[" << category[i].category_n << "]" << endl;
                if (category[i].head != nullptr)    // 등록된 상품이 있다면
                {
                    int num = printItemlist(category[i].head);
                    cout << "상품 종류 : " << num << endl << endl;
                }
                else
                    cout << "상품 종류 : 0\n" << endl;
                found = true;  // 등록된 카데고리이므로 true로 변경
                break;
            }
        }
        if (!found)
            cout << type << " 카테고리는 등록되어 있지 않습니다. \n" << endl;
    }
}
void Manager::sell() {
    cout << "카테고리 : ";
    cin >> type;
    if (type == "charge")
    {
        while (true)
        {
            cout << "얼마나 충전하시겠습니까?(단위: 원) ";
            int money;
            cin >> money;
            if (money > 0)
            {
                i_data.setCash(money);
                cout << "충전이 완료되었습니다.\n" << endl;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "제대로 적어주시길 바랍니다.\n";    // 가격을 0이하 또는 문자열로 했을 시 오류메시지
            }
        }
    }
    else
    {
        fstream myreceipt;
        myreceipt.open("receipt.txt", ios::out | ios::app);
        bool found2 = false; // 입력한 카데고리가 등록되었는 아닌지 체크하는 변수
        for (int i = 0; i < category_c; i++)
        {
            if (category[i].category_n == type)
            {
                while (true)
                {
                    if (category[i].head != nullptr)    // 등록된 상품이 있다면
                    {
                        cout << "무엇을 파시겠습니까? ";
                        string name;
                        cin >> name;
                        ItemNode* ptr = category[i].head;    // 카테고리 내에서 같은 이름의 상품을 찾기 위한 변수
                        bool tf = true;
                        while (ptr != nullptr)  // 상품 이름이 같은 것이 있는지 확인해주는 작업
                        {
                            if (ptr->data->getItem_n() == name)
                            {
                                if (ptr->data->getItem_a() == 0)
                                {
                                    cout << "재고가 없습니다. 상품등록을 이용해 재고를 추가해주세요.\n";
                                    tf = !tf;
                                    break;
                                }
                                while (true)
                                {
                                    cout << "얼마나 파시겠습니까? ";
                                    int amount;
                                    cin >> amount;
                                    auto temp = ptr->data->getItem_a() - amount;
                                    if ((temp < 0) && (amount > 0))
                                        cout << "재고가 없습니다.\n";
                                    else if ((temp >= 0) && (amount > 0))
                                    {
                                        ptr->data->setSellitem_a(amount);
                                        int price;
                                        price = ptr->data->getItem_p() * amount;
                                        while (true)
                                        {
                                            cout << "카드인가요, 현금인가요, 기프티콘인가요?(카드는 1, 현금은 2, 기프티콘은 3) ";
                                            int op;
                                            cin >> op;
                                            if (op == 1)
                                            {
                                                while (true)
                                                {
                                                    cout << "통신사할인을 하시겠습니까?(y/Y or n/N) ";
                                                    char op2;
                                                    cin >> op2;
                                                    if (op2 == 'y' || op2 == 'Y')
                                                    {
                                                        if ((type == "초콜릿" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "사탕" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "빼빼로" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.45;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.15;
                                                            break;
                                                        }
                                                    }
                                                    else if (op2 == 'n' || op2 == 'N')
                                                    {
                                                        if ((type == "초콜릿" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "사탕" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "빼빼로" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.4;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.1;
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cin.clear();
                                                        cin.ignore(1000, '\n');
                                                        cout << "제대로 적어주시길 바랍니다.\n";    // 오류메시지
                                                    }
                                                }
                                                i_data.setCard(price);
                                                myreceipt << "상품명: " + name << endl << "판매량: " + to_string(amount)
                                                    + "개\n판매한 금액: " + to_string(price) + "원\n결제수단: 카드\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else if (op == 2)
                                            {
                                                while (true)
                                                {
                                                    cout << "통신사할인을 하시겠습니까?(y/Y or n/N) ";
                                                    char op2;
                                                    cin >> op2;
                                                    if (op2 == 'y' || op2 == 'Y')
                                                    {
                                                        if ((type == "초콜릿" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "사탕" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "빼빼로" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.35;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.05;
                                                            break;
                                                        }
                                                    }
                                                    else if (op2 == 'n' || op2 == 'N')
                                                    {
                                                        if ((type == "초콜릿" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "사탕" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "빼빼로" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.3;
                                                            break;
                                                        }
                                                        else
                                                            break;
                                                    }
                                                    else
                                                    {
                                                        cin.clear();
                                                        cin.ignore(1000, '\n');
                                                        cout << "제대로 적어주시길 바랍니다.\n";    // 오류메시지
                                                    }
                                                }
                                                i_data.setCash(price);
                                                myreceipt << "상품명: " + name << endl << "판매량: " + to_string(amount)
                                                    + "개\n판매한 금액: " + to_string(price) + "원\n결제수단: 현금\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else if (op == 3)
                                            {
                                                i_data.setCard(price);
                                                myreceipt << "상품명: " + name << endl << "판매량: " + to_string(amount)
                                                    + "개\n판매한 금액: " + to_string(price) + "원\n결제수단: 기프티콘\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else
                                            {
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                                cout << "제대로 적어주시길 바랍니다.\n";    // 오류메시지
                                            }
                                        }
                                        cout << "가격은 " + to_string(price) + "원입니다.\n";
                                        break;
                                    }
                                    else
                                    {
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "제대로 적어주시길 바랍니다.\n";    // 오류메시지
                                    }
                                }
                                break;
                            }
                            ptr = ptr->next;
                        }
                        if (ptr == nullptr)
                            cout << "등록되지 않은 상품입니다.\n";
                        else if (tf == false)
                            break;
                        else
                        {
                            cout << "정상적으로 판매되었습니다.\n";
                            cout << "다른 상품을 판매하시겠습니까?(y/Y or n/N) ";
                            string op;
                            cin >> op;
                            if ((op == "y") || (op == "Y"))
                                cout << endl;
                            else if ((op == "n") || (op == "N"))
                            {
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "판매를 종료하겠습니다.\n" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "먼저 상품을 등록하십시오.\n" << endl;
                        break;
                    }
                }
                myreceipt.close();
                found2 = true;  // 등록된 카데고리이므로 true로 변경
                break;
            }
        }
        if (!found2)
            cout << type << " 카테고리는 등록되어 있지 않습니다. \n" << endl;
    }
}
void Manager::deposit() {
    int money;
    while (true)
    {
        cout << "현재 pos기의 금액 : " << i_data.getCash() << endl;
        cout << "얼마를 입금하시겠습니까?(단위: 10만원) ";
        cin >> money;
        if (money > 0)
        {
            if ((i_data.getCash() - money * 100000) >= 0)
            {
                i_data.setDedcash(money * 100000);
                i_data.setSafe(money * 100000);
            }
            else
            {
                cout << "잔액이 부족합니다.\n";
                money = 0;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "제대로 적어주시길 바랍니다.\n";    // 오류메시지
        }
    }
    cout << "금고에 " << money * 100000 << "을 입금하여\n";
    cout << i_data.getSafe() << "원 있습니다.\n" << endl;
}
bool Manager::receipt(bool tf) {
    cout << endl;
    fstream myreceipt;
    myreceipt.open("receipt.txt", ios::in);
    if (!myreceipt.is_open())
    {
        cout << "아직 판매를 안했습니다.\n" << endl;
        tf = !tf;
        return tf;
    }
    string s;
    while (myreceipt)
    {
        getline(myreceipt, s);
        cout << s << endl;
    }
    myreceipt.close();
}
void Manager::money_list() {
    cout << "카드결제내역: " << i_data.getCard() << "원" << endl;
    cout << "현금: " << i_data.getCash() << "원" << endl;
    cout << "총결산: " << i_data.getCard() + i_data.getCash() + i_data.getSafe() - 100000 << "원\n" << endl;
}
void Manager::today() {
    int month, day;
    srand(time(nullptr));
    month = rand() % 12 + 1;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        day = rand() % 31 + 1;
    else if (month == 2)
        day = rand() % 29 + 1;
    else
        day = rand() % 30 + 1;
    i_data.setMonth(month);
    i_data.setDay(day);

    /*i_data.setMonth(2);
    i_data.setDay(14);

    i_data.setMonth(3);
    i_data.setDay(14);

    i_data.setMonth(11);
    i_data.setDay(11);*/
}
void Manager::today_event() {
    cout << "오늘은 2020년 " << i_data.getMonth() << "월 " << i_data.getDay() << "일이므로\n";
    if (i_data.getMonth() == 2 && i_data.getDay() == 14)
        cout << "발렌타인데이로 초콜릿류가 30%할인입니다!\n" << endl;
    else if (i_data.getMonth() == 3 && i_data.getDay() == 14)
        cout << "화이트데이로 사탕류가 30%할인입니다!\n" << endl;
    else if (i_data.getMonth() == 11 && i_data.getDay() == 11)
        cout << "빼빼로데이로 빼빼로류가 30%할인입니다!\n" << endl;
    else
        cout << "오늘의 이벤트는 없습니다!\n" << endl;
}
