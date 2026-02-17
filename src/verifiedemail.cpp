#include "../include/verifiedemail.h"
#include "../include/email.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


VerifiedEmail::VerifiedEmail() : Email(), verificationDate("") {};


VerifiedEmail::VerifiedEmail(const std::string& local, const std::string& dom) : Email(local, dom), verificationDate("") {};


VerifiedEmail::VerifiedEmail(const std::string& local, const std::string& dom, const std::string& date) : Email(local, dom), verificationDate(date) {};


std::string VerifiedEmail::getVerificationDate() const {
    return verificationDate;
}


void VerifiedEmail::setVerificationDate() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d");
    verificationDate = ss.str();
}


void VerifiedEmail::setVerificationDate(std::string s) {
    verificationDate = s;
}


std::string VerifiedEmail::getService() const {
    std::string res = Email::getService();

    if (res == "Google" || res == "Apple" || res == "Yandex") {
        std::string result = res + "[VERIFIED]";
        return result;
    }
    
    return res;
    
}