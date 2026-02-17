#include <iostream>
#include "include/email.h"
#include "include/verifiedemail.h"

int main() {
    std::cout << "=== Создание обычных Email ===\n";
    Email email1("user", "gmail.com");
    Email email2("admin", "yandex.ru");
    Email email3("contact", "company.ru");
    
    std::cout << "Email1: " << email1.getFullAddress() 
              << " -> " << email1.getService() << "\n";
    std::cout << "Email2: " << email2.getFullAddress() 
              << " -> " << email2.getService() << "\n";
    std::cout << "Email3: " << email3.getFullAddress() 
              << " -> " << email3.getService() << "\n\n";
    
    std::cout << "=== Создание VerifiedEmail ===\n";
    VerifiedEmail vemail1("user", "gmail.com", "2024-01-15");
    VerifiedEmail vemail2("admin", "yandex.ru", "2024-02-20");
    VerifiedEmail vemail3("contact", "apple.com", "2024-03-10");
    
    std::cout << "Verified1: " << vemail1.getFullAddress() 
              << " -> " << vemail1.getService() 
              << " (верифицирован: " << vemail1.getVerificationDate() << ")\n";
    std::cout << "Verified2: " << vemail2.getFullAddress() 
              << " -> " << vemail2.getService()
              << " (верифицирован: " << vemail2.getVerificationDate() << ")\n";
    std::cout << "Verified3: " << vemail3.getFullAddress() 
              << " -> " << vemail3.getService()
              << " (верифицирован: " << vemail3.getVerificationDate() << ")\n\n";
    
    std::cout << "=== Демонстрация полиморфизма ===\n";
    Email* ptr1 = &vemail1;  // Указатель на базовый класс, но объект VerifiedEmail
    Email* ptr2 = &vemail2;
    Email* ptr3 = &vemail3;
    
    std::cout << "Через указатель на Email:\n";
    std::cout << ptr1->getFullAddress() << " -> " << ptr1->getService() << "\n";
    std::cout << ptr2->getFullAddress() << " -> " << ptr2->getService() << "\n";
    std::cout << ptr3->getFullAddress() << " -> " << ptr3->getService() << "\n\n";
    
    std::cout << "=== Сравнение методов ===\n";
    std::cout << "Обычный Email (gmail): " << email1.getService() << "\n";
    std::cout << "Verified Email (gmail): " << vemail1.getService() << "\n";
    std::cout << "Обычный Email (yandex): " << email2.getService() << "\n";
    std::cout << "Verified Email (yandex): " << vemail2.getService() << "\n\n";
    
    std::cout << "=== Тест сеттера без параметра (текущая дата) ===\n";
    VerifiedEmail vemail4("test", "gmail.com");
    std::cout << "До setVerificationDate(): " << vemail4.getVerificationDate() << "\n";
    vemail4.setVerificationDate();  // устанавливает текущую дату
    std::cout << "После setVerificationDate(): " << vemail4.getVerificationDate() << "\n";
    
    return 0;
}
