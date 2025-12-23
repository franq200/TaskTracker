#include "tasktracker.h"
#include <QTimeEdit>

TaskTracker::TaskTracker(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QPushButton* startButton = centralWidget()->findChild<QPushButton*>("startButton");
    connect(startButton, &QPushButton::clicked, this, &TaskTracker::OnStartButtonClicked);

    QPushButton* stopButton = centralWidget()->findChild<QPushButton*>("stopButton");
    connect(stopButton, &QPushButton::clicked, this, &TaskTracker::OnStopButtonClicked);
    /*
    connect(ui.startButton, &QPushButton::clicked,
		this, &TaskTracker::OnStartButtonClicked);

    connect(ui.stopButton, &QPushButton::clicked,
            this, &TaskTracker::OnStopButtonClicked);
    */

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

    QTimeEdit* timeEdit = centralWidget()->findChild<QTimeEdit*>("time");
	timeEdit->setTime(t);
}