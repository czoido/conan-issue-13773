#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include <Poco/Net/MailMessage.h>

#include <iostream>

int main(int argc, char **argv)
{
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

    // create a new email message
    Poco::Net::MailMessage message;

    // set the sender and recipient email addresses
    message.setSender("sender@example.com");
    message.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, "recipient@example.com"));

    // set the subject and body of the message
    message.setSubject("Hello, world!");
    message.setContent("This is a test email message.");

    return 0;
}