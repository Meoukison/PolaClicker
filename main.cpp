#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
int getRandomDelay(int cps) {
    return (1000 / cps) * 2.5;
}
void clearConsole() {
    system("cls");
}
void printLogoAndMessage() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "  ___     _         ___ _ _    _           \n"
                 " | _ \\___| |__ _   / __| (_)__| |_____ _ _ \n"
                 " |  _/ _ \\ / _` | | (__| | / _| / / -_) '_|\n"
                 " |_| \\___/_\\__,_|  \\___|_|_\\__|_\\_\\___|_|  \n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Entrez le nombre de CPS (entre 0 et 20) pour le clic gauche : ";
}
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "  ___     _         ___ _ _    _           \n"
                 " | _ \\___| |__ _   / __| (_)__| |_____ _ _ \n"
                 " |  _/ _ \\ / _` | | (__| | / _| / / -_) '_|\n"
                 " |_| \\___/_\\__,_|  \\___|_|_\\__|_\\_\\___|_|  \n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int left_cps = 10;
    std::cout << "Entrez le nombre de CPS (entre 0 et 20) pour le clic gauche : ";
    std::cin >> left_cps;
    while (left_cps < 0 || left_cps > 20) {
        std::cout << "Nombre de CPS invalide. Entrez une valeur entre 0 et 20 : ";
        std::cin >> left_cps;
    }
    while (true) {
        if (GetAsyncKeyState('O') & 0x8000) {
            clearConsole();
            printLogoAndMessage();
            std::cin >> left_cps;
            while (left_cps < 0 || left_cps > 20) {
                std::cout << "Nombre de CPS invalide. Entrez une valeur entre 0 et 20 : ";
                std::cin >> left_cps;
            }
        }
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            HWND window = GetForegroundWindow();
            SendMessageW(window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
            SendMessageW(window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
            Sleep(20);
        }
        if (GetAsyncKeyState(VK_LBUTTON)) {
            HWND window = GetForegroundWindow();
            SendMessageW(window, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
            SendMessageW(window, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
            Sleep(rand() % getRandomDelay(left_cps));
        }
    }

    return 0;
}
