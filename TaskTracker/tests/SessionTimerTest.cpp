#include <QtTest>
#include "sessionTimer.h"

class SessionTimerTest : public QObject
{
    Q_OBJECT

private slots:
    void startStop();
    void elapsedTime();
    void signalEmitted();
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

void SessionTimerTest::elapsedTime()
{
    SessionTimer timer;
    timer.Start();
    QTest::qWait(2100);
    QVERIFY(timer.ElapsedSeconds() >= 2);
}

void SessionTimerTest::signalEmitted()
{
    SessionTimer timer;
    QSignalSpy spy(&timer, &SessionTimer::TimeUpdated);

    timer.Start();
    QTest::qWait(1100);

    QVERIFY(spy.count() >= 1);
}

QTEST_MAIN(SessionTimerTest)
#include "SessionTimerTest.moc"
