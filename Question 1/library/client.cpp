#include "client.h"

Client::Client()
{
    name = "Unknown";
    date = QDate(1900, 01, 01);
}

Client::Client(QString n, QDate d) : name(n), date(d)
{
}

void Client::setName(QString n)
{
    name = n;
}

void Client::setDate(QDate d)
{
    date = d;
}

QString Client::getName() const
{
    return name;
}

QDate Client::getDate() const
{
    return date;
}
