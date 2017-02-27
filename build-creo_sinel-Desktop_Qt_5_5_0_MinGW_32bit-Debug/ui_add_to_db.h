/********************************************************************************
** Form generated from reading UI file 'add_to_db.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_TO_DB_H
#define UI_ADD_TO_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_add_to_db
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblProjnb;
    QLineEdit *LEProjnb;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblProjName;
    QLineEdit *LEProjName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblMainDir;
    QLineEdit *LEMainDir;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblLocalDirs;
    QLineEdit *LELocalDirs;
    QDialogButtonBox *addToDbButtonBox;

    void setupUi(QDialog *add_to_db)
    {
        if (add_to_db->objectName().isEmpty())
            add_to_db->setObjectName(QStringLiteral("add_to_db"));
        add_to_db->resize(545, 298);
        verticalLayout = new QVBoxLayout(add_to_db);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblProjnb = new QLabel(add_to_db);
        lblProjnb->setObjectName(QStringLiteral("lblProjnb"));

        horizontalLayout->addWidget(lblProjnb);

        LEProjnb = new QLineEdit(add_to_db);
        LEProjnb->setObjectName(QStringLiteral("LEProjnb"));

        horizontalLayout->addWidget(LEProjnb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblProjName = new QLabel(add_to_db);
        lblProjName->setObjectName(QStringLiteral("lblProjName"));

        horizontalLayout_2->addWidget(lblProjName);

        LEProjName = new QLineEdit(add_to_db);
        LEProjName->setObjectName(QStringLiteral("LEProjName"));

        horizontalLayout_2->addWidget(LEProjName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblMainDir = new QLabel(add_to_db);
        lblMainDir->setObjectName(QStringLiteral("lblMainDir"));

        horizontalLayout_3->addWidget(lblMainDir);

        LEMainDir = new QLineEdit(add_to_db);
        LEMainDir->setObjectName(QStringLiteral("LEMainDir"));

        horizontalLayout_3->addWidget(LEMainDir);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblLocalDirs = new QLabel(add_to_db);
        lblLocalDirs->setObjectName(QStringLiteral("lblLocalDirs"));

        horizontalLayout_4->addWidget(lblLocalDirs);

        LELocalDirs = new QLineEdit(add_to_db);
        LELocalDirs->setObjectName(QStringLiteral("LELocalDirs"));

        horizontalLayout_4->addWidget(LELocalDirs);


        verticalLayout->addLayout(horizontalLayout_4);

        addToDbButtonBox = new QDialogButtonBox(add_to_db);
        addToDbButtonBox->setObjectName(QStringLiteral("addToDbButtonBox"));
        addToDbButtonBox->setOrientation(Qt::Horizontal);
        addToDbButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(addToDbButtonBox);


        retranslateUi(add_to_db);
        QObject::connect(addToDbButtonBox, SIGNAL(accepted()), add_to_db, SLOT(accept()));
        QObject::connect(addToDbButtonBox, SIGNAL(rejected()), add_to_db, SLOT(reject()));

        QMetaObject::connectSlotsByName(add_to_db);
    } // setupUi

    void retranslateUi(QDialog *add_to_db)
    {
        add_to_db->setWindowTitle(QApplication::translate("add_to_db", "Add project to database", 0));
        lblProjnb->setText(QApplication::translate("add_to_db", "Project Number:", 0));
        lblProjName->setText(QApplication::translate("add_to_db", "Project Name:", 0));
        lblMainDir->setText(QApplication::translate("add_to_db", "Main Directory:", 0));
        lblLocalDirs->setText(QApplication::translate("add_to_db", "Local Directory:", 0));
    } // retranslateUi

};

namespace Ui {
    class add_to_db: public Ui_add_to_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TO_DB_H
