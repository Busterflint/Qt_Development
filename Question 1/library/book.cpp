#include "book.h"

Book::Book()
{
    author = "Unknown";
    title = "Unknown";
    cost = 0.0;
}

Book::Book(QString a, QString t, float c): author(a), title(t), cost(c)
{
}

void Book::setAuthor(QString a)
{
    author = a;
}

void Book::setTitle(QString t)
{
    title = t;
}

void Book::setCost(float c)
{
    cost = c;
}

QString Book::getAuthor() const
{
    return author;
}

QString Book::getTitle() const
{
    return title;
}

float Book::getCost() const
{
    return cost;
}
