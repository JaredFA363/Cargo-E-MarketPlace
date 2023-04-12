#include <QTest>
#include "logindialog.h"
#include <QObject>

class loginTests : public QObject
{
    Q_OBJECT

private slots:
    void loginWithCorrectVals();
    void loginWithIncorrectValsUsername();
    void loginWithIncorrectValsPassword();
};

void loginTests::loginWithCorrectVals()
{
    LoginDialog dialog;

    QString result = dialog.checkLoginDetails("Transportation Company","tc1","tc1");
    QString expected = "Correct Transportation Company";

    QCOMPARE(result,expected);
}

void loginTests::loginWithIncorrectValsUsername()
{
    LoginDialog dialog;

    QString result = dialog.checkLoginDetails("Transportation Company","521615216","2562151");
    QString expected = "Incorrect Username";

    QCOMPARE(result,expected);
}

void loginTests::loginWithIncorrectValsPassword()
{
    LoginDialog dialog;

    QString result = dialog.checkLoginDetails("Transportation Company","tc1","2562151");
    QString expected = "Incorrect Password";

    QCOMPARE(result,expected);
}

//QTEST_MAIN(loginTests);
//#include "loginTests.moc";
