#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>

class Client
{
public:
    Client();
    Client(QString n, QDate d);

    void setName(QString n);
    QString getName() const;
    void setDate(QDate d);
    QDate getDate() const;

private:
    QString name;
    QDate date;
};

#endif // CLIENT_H
