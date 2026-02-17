#ifndef VERIFIEDEMAIL_H
#define VERIFIEDEMAIL_H

#include "../include/email.h"

class VerifiedEmail : public Email {

private:
    std::string verificationDate;

public:

    VerifiedEmail();
    VerifiedEmail(const std::string& local, const std::string& dom);
    VerifiedEmail(const std::string& local, const std::string& dom, const std::string& date);

    std::string getVerificationDate() const;

    void setVerificationDate();
    void setVerificationDate(std::string s);


    std::string getService() const override;

};



#endif
