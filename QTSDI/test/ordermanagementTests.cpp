#include <QTest>
#include "driverview.h"
#include "transportcompanyview.h"
#include "userform.h"
#include <QObject>

class ordermanagementTests : public QObject
{
    Q_OBJECT

private slots:
    void testCargoOrderWithCorrectVals();
    void testCargoOrderWithEmptyVals();
    void testTransportAcceptWithIncorrectVal();
    void testTransportAcceptWithCorrectVal();
    void testDriverAcceptWithIncorrectVal();
    void testDriverAcceptWithCorrectVal();
};

void ordermanagementTests::testCargoOrderWithCorrectVals()
{
    userform *Userform = new userform("Cargo Company","co1");

    QString result = Userform->checkOrder("test","test","test","test","tc1","test");
    QString expected = "Order Placed";

    QCOMPARE(result,expected);
}

void ordermanagementTests::testCargoOrderWithEmptyVals()
{
    userform *Userform = new userform("Cargo Company","co1");

    QString result = Userform->checkOrder("","","","","","");
    QString expected = "Empty Order";

    QCOMPARE(result,expected);
}

void ordermanagementTests::testTransportAcceptWithIncorrectVal()
{
    transportcompanyview *Transport = new transportcompanyview("Transportation Company","tc1");

    bool result = Transport->checkOrderId("z");
    bool expected = false;

    QCOMPARE(result,expected);
}

void ordermanagementTests::testTransportAcceptWithCorrectVal()
{
    transportcompanyview *Transport = new transportcompanyview("Transportation Company","tc1");

    //May need to change value
    bool result = Transport->checkOrderId("1");
    bool expected = true;

    QCOMPARE(result,expected);
}

void ordermanagementTests::testDriverAcceptWithIncorrectVal()
{
    driverview *driver = new driverview("Driver","d1");

    bool result = driver->checkOrderId("z");
    bool expected = false;

    QCOMPARE(result,expected);
}

void ordermanagementTests::testDriverAcceptWithCorrectVal()
{
    driverview *driver = new driverview("Driver","d1");

    //May need to change value
    bool result = driver->checkOrderId("1");
    bool expected = true;

    QCOMPARE(result,expected);
}

//QTEST_MAIN(ordermanagementTests);
//#include "ordermanagementTests.moc";
