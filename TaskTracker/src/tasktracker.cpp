#include "tasktracker.h"

TaskTracker::TaskTracker(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.startButton, &QPushButton::clicked,
		this, &TaskTracker::OnStartButtonClicked);

    connect(ui.stopButton, &QPushButton::clicked,
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
	uint64_t m = (elapsedSeconds / 60) % 60;
	uint64_t h = elapsedSeconds / 3600;

    QTime t(h, m, s);

    ui.time->setTime(t);
	ui.dial->setValue(static_cast<int>(s));
}