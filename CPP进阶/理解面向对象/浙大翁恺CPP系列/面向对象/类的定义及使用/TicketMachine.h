#pragma once    // 防止头文件被重复包含，需要编译器支持
#ifndef TICKETMACHINE_H_    // 同样防止头文件被重复包含
#define TICKETMACHINE_H_    // 属于C/C++的标准语法，兼容性更好

class TicketMachine         // 声明了TicketMachine类
{
public:
    TicketMachine();
    ~TicketMachine();
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();
private:
    const int PRICE;
    int balance;
    int total;
};
#endif
