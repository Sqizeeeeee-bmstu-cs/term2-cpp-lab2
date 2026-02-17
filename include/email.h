#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Email {
private:
    std::string localPart;
    std::string domain;

public:
    
    Email();
    Email(const std::string& local, const std::string& dom);
    
    // get и set методы
    std::string getLocalPart() const;
    void setLocalPart(const std::string& local);
    
    std::string getDomain() const;
    void setDomain(const std::string& dom);
    
    //
    bool isValid() const;
    virtual std::string getService() const;
    std::string getFullAddress() const;
    bool isCorporate() const;
    bool hasSubdomain() const;
    Email createAlias(const std::string& alias) const;
    
    // Перегрузка операторов
    bool operator==(const Email& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Email& email);
    
    // Статический метод
    static Email generate(const std::string& name, const std::string& domain);
    
    // Метод для вывода состояния
    void printInfo() const;
    
private:
    // Вспомогательные приватные методы
    bool isValidLocalPart(const std::string& local) const;
    bool isValidDomain(const std::string& dom) const;
    std::string toLower(const std::string& str) const;
};

#endif
