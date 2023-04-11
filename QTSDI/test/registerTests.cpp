#include <QTest>
#include "cargoregdialog.h"
#include "transportregdialog.h"
#include "driverregdialog.h"
#include <QObject>

class registerTests : public QObject
{
    Q_OBJECT

private slots:
    void testCargoRegWithCorrectVals();
    void testTransportRegWithCorrectVals();
    void testDriverRegWithCorrectVals();
    void testCargoRegWithEmptyVals();
    void testTransportRegWithEmptyVals();
    void testDriverRegWithEmptyVals();
    void testCargoRegWithSameUsername();
    void testTransportRegWithSameUsername();
    void testDriverRegWithSameUsername();
};

void registerTests::testCargoRegWithEmptyVals()
{
    CargoRegDialog dialog;

    QString result = dialog.check_inputs("","","","","","","");
    QString expected = "Message1";

    QCOMPARE(result,expected);
}

void registerTests::testCargoRegWithCorrectVals()
{
    CargoRegDialog dialog;

    QString result = dialog.check_inputs("test","test","test","test","test","test","test");
    QString expected = "Message3";

    QCOMPARE(result,expected);
}

void registerTests::testCargoRegWithSameUsername()
{
    CargoRegDialog dialog;

    QString result = dialog.check_inputs("co1","test","test","test","test","test","test");
    QString expected = "Message2";

    QCOMPARE(result,expected);
}


void registerTests::testTransportRegWithEmptyVals()
{
    TransportRegDialog dialog;

    QString result = dialog.check_inputs("","","","");
    QString expected = "Message1";

    QCOMPARE(result,expected);
}

void registerTests::testTransportRegWithCorrectVals()
{
    TransportRegDialog dialog;

    QString result = dialog.check_inputs("test","test","test","test");
    QString expected = "Message3";

    QCOMPARE(result,expected);
}

void registerTests::testTransportRegWithSameUsername()
{
    TransportRegDialog dialog;

    QString result = dialog.check_inputs("tc1","test","test","test");
    QString expected = "Message2";

    QCOMPARE(result,expected);
}

void registerTests::testDriverRegWithEmptyVals()
{
    DriverRegDialog dialog;

    QString result = dialog.check_inputs("","","","","","","","","");
    QString expected = "Message1";

    QCOMPARE(result,expected);
}

void registerTests::testDriverRegWithCorrectVals()
{
    DriverRegDialog dialog;

    QString result = dialog.check_inputs("test","test","test","test","test","test","test","test","test");
    QString expected = "Message3";

    QCOMPARE(result,expected);
}

void registerTests::testDriverRegWithSameUsername()
{
    DriverRegDialog dialog;

    QString result = dialog.check_inputs("d1","test","test","test","test","test","test","test","test");
    QString expected = "Message2";

    QCOMPARE(result,expected);
}
