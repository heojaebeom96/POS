#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>

using namespace std;

class ItemData	// 상품정보 클래스
{
protected:
    string item_n, category_n, option;	// item_n: 상품이름, category_n: 카테고리 이름, option: 이벤트
    int item_p, item_a, safe = 100000, cash = 0, card = 0, month, day;
    // item_p: 상품가격, item_a: 상품재고, safe: 금고, cash: 현금, card: 카드, month: 해당 월, day: 해당 일
public:
    // setter&getter
    void setItem_n(string n);
    string getItem_n();
    void setCategory_n(string n);
    string getCategory_n();
    void setOption(string o);
    string getOption();
    void setItem_p(int p);
    int getItem_p();
    void setItem_a(int a);
    void setTotalitem_a(int a);
    void setSellitem_a(int a);
    int getItem_a();
    void setCash(int ch);
    void setDedcash(int ch);
    int getCash();
    void setCard(int cd);
    int getCard();
    void setSafe(int s);
    int getSafe();
    void setMonth(int m);
    int getMonth();
    void setDay(int d);
    int getDay();
};

class ItemNode :public ItemData
{
public:
    ItemData* data;
    ItemNode* next;
    ItemNode()
    {
        data = new ItemData;
    }
    ~ItemNode() {}
};

class Manager :public ItemNode
{
private:
    ItemData i_data;
    ItemNode* head;
    ItemNode* tail;
    Manager* category = nullptr;
    int category_c = 0, size;
    string type;
public:
    Manager() {}
    ~Manager()
    {
        delete[] category;
    }
    void addItemType();
    void add();
    int printItemlist(ItemNode* ptr);
    void showItems();
    void sell();
    void deposit();
    bool receipt(bool tf);
    void money_list();
    void today();
    void today_event();
};
