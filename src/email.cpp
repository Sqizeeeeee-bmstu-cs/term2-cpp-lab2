#include "../include/email.h"

Email::Email() : localPart("user"), domain("example.com") {}

Email::Email(const std::string& local, const std::string& dom) 
    : localPart(local), domain(dom) {}

std::string Email::getLocalPart() const { return localPart; }
std::string Email::getDomain() const { return domain; }

void Email::setLocalPart(const std::string& local) { localPart = local; }
void Email::setDomain(const std::string& dom) { domain = dom; }

bool Email::isValid() const {
    return isValidLocalPart(localPart) && isValidDomain(domain);
}

std::string Email::getService() const {
    std::string domainLower = toLower(domain);
    
    if (domainLower.find("gmail.com") != std::string::npos) return "Google";
    if (domainLower.find("outlook.com") != std::string::npos || 
        domainLower.find("hotmail.com") != std::string::npos) return "Microsoft";
    if (domainLower.find("yahoo.com") != std::string::npos) return "Yahoo";
    if (domainLower.find("icloud.com") != std::string::npos || 
        domainLower.find("apple.com") != std::string::npos) return "Apple";
    if (domainLower.find("mail.ru") != std::string::npos) return "Mail.ru";
    if (domainLower.find("yandex.ru") != std::string::npos) return "Yandex";
    if (domainLower.find("protonmail.com") != std::string::npos) return "ProtonMail";
    
    return "Unknown";
}

std::string Email::getFullAddress() const {
    return localPart + "@" + domain;
}

bool Email::isCorporate() const {
    std::vector<std::string> publicDomains = {
        "gmail.com", "yahoo.com", "outlook.com", 
        "hotmail.com", "mail.ru", "yandex.ru"
    };
    
    std::string domainLower = toLower(domain);
    for (const auto& publicDomain : publicDomains) {
        if (domainLower == publicDomain) return false;
    }
    return true;
}

bool Email::hasSubdomain() const {
    std::string domainLower = toLower(domain);
    size_t dotCount = std::count(domainLower.begin(), domainLower.end(), '.');
    return dotCount > 1;
}

Email Email::createAlias(const std::string& alias) const {
    return Email(alias, domain);
}

bool Email::operator==(const Email& other) const {
    return toLower(localPart) == toLower(other.localPart) && 
           toLower(domain) == toLower(other.domain);
}

std::ostream& operator<<(std::ostream& os, const Email& email) {
    os << email.localPart << "@" << email.domain;
    return os;
}

Email Email::generate(const std::string& name, const std::string& domain) {
    std::string processedName = name;
    processedName.erase(std::remove(processedName.begin(), processedName.end(), ' '), 
                       processedName.end());
    std::transform(processedName.begin(), processedName.end(), 
                   processedName.begin(), ::tolower);
    return Email(processedName, domain);
}

void Email::printInfo() const {
    std::cout << "Email Information:\n";
    std::cout << "  Full address: " << getFullAddress() << "\n";
    std::cout << "  Local part: " << localPart << "\n";
    std::cout << "  Domain: " << domain << "\n";
    std::cout << "  Valid: " << (isValid() ? "Yes" : "No") << "\n";
    std::cout << "  Service: " << getService() << "\n";
    std::cout << "  Corporate: " << (isCorporate() ? "Yes" : "No") << "\n";
    std::cout << "  Has subdomain: " << (hasSubdomain() ? "Yes" : "No") << "\n";
}

bool Email::isValidLocalPart(const std::string& local) const {
    if (local.empty() || local.length() > 64) return false;
    if (local.front() == '.' || local.back() == '.') return false;
    if (local.find("..") != std::string::npos) return false;
    
    for (char c : local) {
        if (!isalnum(c) && c != '.' && c != '_' && c != '%' && c != '+' && c != '-')
            return false;
    }
    
    return true;
}

bool Email::isValidDomain(const std::string& dom) const {
    if (dom.empty() || dom.length() > 255) return false;
    if (dom.find('.') == std::string::npos) return false;
    
    size_t start = 0;
    size_t end = dom.find('.');
    
    while (end != std::string::npos) {
        std::string part = dom.substr(start, end - start);
        if (part.empty() || part.length() > 63) return false;
        if (part.front() == '-' || part.back() == '-') return false;
        
        for (char c : part) {
            if (!isalnum(c) && c != '-') return false;
        }
        
        start = end + 1;
        end = dom.find('.', start);
    }
    
    std::string lastPart = dom.substr(start);
    if (lastPart.empty() || lastPart.length() > 63) return false;
    for (char c : lastPart) {
        if (!isalpha(c)) return false;
    }
    
    return true;
}

std::string Email::toLower(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
