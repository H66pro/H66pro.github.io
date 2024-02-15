#include "Ticketmachine.h"
#include "Ticketmachine.cpp"

int main()
{
    TicketMachine tm;
    tm.insertMoney( 100);
    tm.showBalance();
    
    system("pause");
    return 0;
}