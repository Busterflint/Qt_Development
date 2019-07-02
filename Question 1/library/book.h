#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString a, QString t, float c);

    void setAuthor(QString a);
    void setTitle(QString t);
    void setCost(float c);

    QString getAuthor() const;
    QString getTitle() const;
    float getCost() const;

private:
    QString author;
    QString title;
    float cost;
};

#endif // BOOK_H
