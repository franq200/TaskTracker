#include "tasktracker.h"

TaskTracker::TaskTracker(QWidget *parent)
    : QMainWindow(parent)
{
    ui_.setupUi(this);
    
    connect(ui_.startButton, &QPushButton::clicked,
		this, &TaskTracker::OnStartButtonClicked);

    connect(ui_.stopButton, &QPushButton::clicked,
            this, &TaskTracker::OnStopButtonClicked);
    

    connect(&sessionTimer_, &SessionTimer::TimeUpdated,
        this, &TaskTracker::UpdateTime);
}

TaskTracker::~TaskTracker()
{}

void TaskTracker::OnStartButtonClicked()
{
    sessionTimer_.Start();
}

void TaskTracker::OnStopButtonClicked()
{
	sessionTimer_.Stop();
}

void TaskTracker::UpdateTime(qint64 elapsedSeconds)
{
    uint64_t s = elapsedSeconds % 60;
	uint64_t m = (elapsedSeconds % 3600) / 60;
	uint64_t h = elapsedSeconds / 3600;

    QString timeText = QString("%1:%2:%3")
        .arg(h, 2, 10, QChar('0'))
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
	ui_.timeLabel->setText(timeText);
}