#ifndef REPAIRDIALOG_H
#define REPAIRDIALOG_H


//#include "ui_repairDialog.h"
#include "editrepair.h"
#include <QtGui>
#include <QWidget>
#include <QDockWidget>

class EditRepairPlugin;
namespace Ui {
class RepairDialog;
}
class RepairDialog : public QDockWidget{
    Q_OBJECT
public:
    //GetPointsDialog(QWidget *parent);
    RepairDialog(QWidget *parent,EditRepairPlugin *_edit);
    ~RepairDialog();


    virtual void closeEvent ( QCloseEvent * event )	;
    Qt::CheckState  checkBoxShowPointsState();
    void SetToothinfoText(QString str);
    void ToothinfoAdjustSize();
// protected:
// 	void paintEvent(QPaintEvent *event);

signals:
    void closing();
    void updateMeshSetVisibilities();
private:
    //Ui::PlanTable ui;
    Ui::RepairDialog *ui;

};

#endif

