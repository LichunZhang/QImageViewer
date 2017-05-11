#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

class QMdiArea;
class QSignalMapper;
class QCloseEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void OperationTriggered(int index);
    void About();
    void Mannual();

private:
    void ReadSettings();
    void WriteSettings();
    void CreateStatusBar();
    void LoadPlugins();
    void CreateActions();
    void DefaultShows();

    QMdiArea *_mdiarea;
    QToolBar *_toolbar;
    QSignalMapper *_ops_mapper;
    QMap<QString,QMenu*> _menu_ct1;
    QMap<QString,QMenu*> _menu_ct2;

};

#endif // MAINWINDOW_H
