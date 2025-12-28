#include <QtTest>
#include "sessionTimer.h"

class SessionTimerTest : public QObject
{
    Q_OBJECT

private slots:
    void startStop();
};

void SessionTimerTest::startStop()
{
    SessionTimer timer;
    QVERIFY(!timer.IsRunning());

    timer.Start();
    QVERIFY(timer.IsRunning());

    timer.Stop();
    QVERIFY(!timer.IsRunning());
}

QTEST_MAIN(SessionTimerTest)
#include "SessionTimerTest.moc"
