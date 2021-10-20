#include"dialog.h"
int main() {
    void(*dp[5])(Table & oc) = { nullptr, AddNewStudent,DeleteStudent,
        TransportStudent, CheckAll };
    bool flag = true;
    int fl1 = 1;
    int c;
    Table table;
    table.LoadTab();
    while (fl1) {
        std::cout << "1. AddNewStudent" << std::endl;
        std::cout << "2. DeleteStudent" << std::endl;
        std::cout << "3. TransportStudent" << std::endl;
        std::cout << "4. CheckAll" << std::endl;
        std::cin >> c;
        if (!std::cin.good() || c < 0 || c > 6) {

            std::cin.clear();

            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Incorrect input!" << std::endl;
        }
        else
            if (c == 0)
                fl1 = 0;
            else
                dp[c](table);

    }
    table.SaveTab();
}