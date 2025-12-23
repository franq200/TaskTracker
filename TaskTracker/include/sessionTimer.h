#pragma once
#include <QObject>
#include <QTimer>
#include <QDateTime>

class SessionTimer : public QObject
{
	Q_OBJECT
public:
	SessionTimer(QObject* parent = nullptr);

	void Start();
	void Stop();
	bool IsRunning() const;

	qint64 ElapsedSeconds() const;

signals:
	void TimeUpdated(qint64 elapsedSeconds);

private slots:
	void OnTick();

private:
	QTimer timer_;
	QDateTime startTime_;
	qint64 elapsedSeconds_ = 0;
	bool running_ = false;
};