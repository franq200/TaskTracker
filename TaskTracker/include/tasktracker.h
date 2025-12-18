#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tasktracker.h"

class TaskTracker : public QMainWindow
{
    Q_OBJECT

public:
    TaskTracker(QWidget *parent = nullptr);
    ~TaskTracker();

private:
    Ui::TaskTrackerClass ui;
};

