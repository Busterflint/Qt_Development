#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "book.h"
#include "client.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->deDate->setDate(QDate::currentDate());

    connect(ui->addBook, SIGNAL(clicked()), this, SLOT(addBook()));
    connect(ui->addClient, SIGNAL(clicked()), this, SLOT(addClient()));
    connect(ui->issueBook, SIGNAL(clicked()), this, SLOT(issueBook()));
    connect(ui->returnBook, SIGNAL(clicked()), this, SLOT(returnBook()));
    connect(ui->listIssued, SIGNAL(clicked()), this, SLOT(listIssued()));
    connect(ui->cbReturnClient, SIGNAL(currentIndexChanged(int)), this, SLOT(updateReturnBook()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// slot for add book button
void MainWindow::addBook()
{
    // create new book
    Book *b = new Book();
    b->setAuthor(ui->leBookAuthor->text());
    b->setTitle(ui->leBookTitle->text());
    b->setCost(ui->dsbBookCost->value());

    // add to list of books and clear dialog
    booklist.addBook(b);
    ui->leBookAuthor->clear();
    ui->leBookTitle->clear();
    ui->dsbBookCost->setValue(0.00);

    // update book combo box for issuing books
    ui->cbBookTitle->clear();
    ui->cbBookTitle->insertItems(0, booklist.returnBookTitles());
}

// slot for add client button
void MainWindow::addClient()
{
    // create new client
    Client *c = new Client;
    c->setName(ui->leClientName->text());
    c->setDate(ui->deDate->date());

    // add to list of clients and clear dialog
    clientlist.addClient(c);
    ui->leClientName->clear();
    ui->deDate->setDate(QDate::currentDate());

    // update client combo box for issuing books
    ui->cbClientName->clear();
    ui->cbClientName->insertItems(0, clientlist.returnClientNames());
}

// slot for issue book button
void MainWindow::issueBook()
{
    // add client and book to issued list
    issuedBooks.issueBook(ui->cbClientName->currentText(), ui->cbBookTitle->currentText());

    //update return client combo box and books for that client
    ui->cbReturnClient->clear();
    ui->cbReturnClient->insertItems(0, issuedBooks.allClients());
    updateReturnBook();
}

// slot for return book button
void MainWindow::returnBook()
{
    issuedBooks.returnBook(ui->cbReturnClient->currentText(), ui->cbReturnBook->currentText());
    updateReturnBook();
}

// slot for displaying detail to the window
void MainWindow::listIssued()
{
    ui->displayWindow->clear();
    if (issuedBooks.count()>0)
        ui->displayWindow->append(issuedBooks.allIssuedBooks());
    else
        ui->displayWindow->append("No issued books");
}

// slot to update books for specific client in return section
void MainWindow::updateReturnBook()
{
    ui->cbReturnBook->clear();
    ui->cbReturnBook->insertItems(0, issuedBooks.booksForClient(ui->cbReturnClient->currentText()));
}
