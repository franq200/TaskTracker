#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tasktracker.h"
#include "sessionTimer.h"

class TaskTracker : public QMainWindow
{
    Q_OBJECT

public:
    TaskTracker(QWidget *parent = nullptr);
    ~TaskTracker();

private slots:
    void OnStartButtonClicked();
    void OnStopButtonClicked();
	void UpdateTime(qint64 elapsedSeconds);

private:
    Ui::TaskTrackerClass ui_;
    SessionTimer sessionTimer_;
};

