/********************************************************************************
** Form generated from reading UI file 'project_details.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_DETAILS_H
#define UI_PROJECT_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_project_details
{
public:

    void setupUi(QDialog *project_details)
    {
        if (project_details->objectName().isEmpty())
            project_details->setObjectName(QStringLiteral("project_details"));
        project_details->resize(538, 393);

        retranslateUi(project_details);

        QMetaObject::connectSlotsByName(project_details);
    } // setupUi

    void retranslateUi(QDialog *project_details)
    {
        project_details->setWindowTitle(QApplication::translate("project_details", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class project_details: public Ui_project_details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_DETAILS_H
