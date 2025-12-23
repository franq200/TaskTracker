#include "sessionTimer.h"

SessionTimer::SessionTimer(QObject* parent)
	: QObject(parent)
{
	timer_.setInterval(1000);
	connect(&timer_, &QTimer::timeout, this, &SessionTimer::OnTick);
}

void SessionTimer::Start()
{
	if (running_)
	{
		return;
	}

	elapsedSeconds_ = 0;
	startTime_ = QDateTime::currentDateTime();
	timer_.start();
	running_ = true;
}

void SessionTimer::Stop()
{
	if (!running_)
	{
		return;
	}

	timer_.stop();
	running_ = false;
}

bool SessionTimer::IsRunning() const
{
	return running_;
}

qint64 SessionTimer::ElapsedSeconds() const
{
	return elapsedSeconds_;
}

void SessionTimer::OnTick()
{
	elapsedSeconds_ = startTime_.secsTo(QDateTime::currentDateTime());

	emit TimeUpdated(elapsedSeconds_);
}

