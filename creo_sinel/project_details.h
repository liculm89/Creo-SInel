#ifndef PROJECT_DETAILS_H
#define PROJECT_DETAILS_H

#include <QDialog>

namespace Ui {
class project_details;
}

class project_details : public QDialog
{
    Q_OBJECT

public:
    explicit project_details(QWidget *parent = 0);
    ~project_details();

private:
    Ui::project_details *ui;
};

#endif // PROJECT_DETAILS_H
