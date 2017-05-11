#include "Splash.h"
#include "PlatformResources.h"
#include "PluginOperation.h"
#include "mainwindow.h"
#include <QMdiArea>
#include <QToolBar>
#include <QSettings>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QDir>
#include <QLibrary>
#include <QSignalMapper>
#include <QSplashScreen>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        _mdiarea(nullptr),
        _toolbar(nullptr),
        _ops_mapper(nullptr) {
    QSettings settings("Lichun Zhang, Soochow University",
                       "QImageViewer v1.0"); //organization,application
    setWindowTitle(tr("QImageViewer"));
    ReadSettings();
    // initializing some widgets
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *hboxLayout = new QHBoxLayout(centralWidget);
    _mdiarea = new QMdiArea(centralWidget);
    hboxLayout->addWidget(_mdiarea);
    _mdiarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    _mdiarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(centralWidget);
    PlatformResources::g_workspace = _mdiarea;
    CreateStatusBar();

    LoadPlugins();

    // Actions
    _toolbar = addToolBar(tr("Tools"));
    _toolbar->setIconSize(QSize(40, 40));
    CreateActions();
    DefaultShows();
}

MainWindow::~MainWindow() {
    size_t count = PluginOperation::GetOpCount();
    for (size_t i = 0; i < count; ++i) {
        PluginOperation *op = PluginOperation::GetOperation(i);
        if (op->IsShown())
            op->Hide();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    _mdiarea->closeAllSubWindows();
    if (_mdiarea->activeSubWindow()) {
        event->ignore();
    } else {
        WriteSettings();
        event->accept();
    }
}

void MainWindow::ReadSettings() {
    QSettings settings("Lichun Zhang, Soochow University", "QImageViewer");
    QPoint pos = settings.value("pos", QPoint(0, 0)).toPoint();
    QSize size = settings.value("size", QSize(1024, 768)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::WriteSettings() {
    QSettings settings("Lichun Zhang, Soochow University", "QImageViewer");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

void MainWindow::CreateStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::LoadPlugins() {
    QSplashScreen *splash = GetSplashScreen();
    QDir plugins_dir("Plugins");
    plugins_dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QStringList plugins_files = plugins_dir.entryList();

    for (QStringList::Iterator it = plugins_files.begin();
         it != plugins_files.end(); ++it) {
        QLibrary lib(plugins_dir.filePath(*it));
        qDebug() << lib.fileName() << "\n";
        if (splash)
            splash->showMessage(tr("Loading Plugin: ") + lib.fileName(),
                                Qt::AlignBottom, Qt::white);
        bool Loaded = lib.load();
    }
}

void MainWindow::CreateActions() {
    /// View Menu
    QMenu *view_menu = new QMenu("&View", menuBar());
    _menu_ct1.insert("&View", view_menu);

    QAction *tileWindowsAction = new QAction("Tile child windows", view_menu);
    connect(tileWindowsAction, SIGNAL(triggered()),
            _mdiarea, SLOT(tileSubWindows()));
    view_menu->addAction(tileWindowsAction);
//    m_ActionList.append(ActionInfo(tileWindowsAction,"Tile child windows"));

    view_menu->addSeparator();

    QAction *action = _toolbar->toggleViewAction();
    action->setText("&Tool Bar");
    view_menu->addAction(action);

    /// Options Menu
    QMenu *opt_menu = new QMenu("&Options", menuBar());
    _menu_ct1.insert("&Options", opt_menu);

    /// Help Menu
    QMenu *help_menu = new QMenu("&Help", menuBar());
    _menu_ct1.insert("&Help", help_menu);

    action = new QAction("&Mannual", this);
    action->setStatusTip("Show the mannual of QImageViewer");
    connect(action, SIGNAL(triggered()), SLOT(Mannual()));
    help_menu->addAction(action);

    action = new QAction("&About QImageViewer", this);
    action->setStatusTip("About");
    connect(action, SIGNAL(triggered()), SLOT(About()));
    help_menu->addAction(action);


    /// Action mapper
    _ops_mapper = new QSignalMapper(this);
    connect(_ops_mapper, SIGNAL(mapped(int)), SLOT(OperationTriggered(int)));
    size_t count = PluginOperation::GetOpCount();
    for (size_t i = 0; i < count; ++i) {
        PluginOperation *op = PluginOperation::GetOperation(i);
        action = new QAction(op->GetDisplayName(), this);
        action->setStatusTip(op->GetTooltip());
        const QIcon icon = op->GetIcon();
        if (!icon.isNull())
            action->setIcon(icon);
        _ops_mapper->setMapping(action, i);
        connect(action, SIGNAL(triggered()), _ops_mapper, SLOT(map()));

        // Add actions to the menu
        QMenu *menu = nullptr;
        const char *menu_ct1 = op->GetMenuName();
        if (menu_ct1) {
            QString category1 = menu_ct1;
            QMap<QString, QMenu *>::iterator it = _menu_ct1.find(category1);
            if (it == _menu_ct1.end())
                it = _menu_ct1.insert(category1, menuBar()->addMenu(category1));
            menu = it.value();

            const char *menu_ct2 = op->GetMenuName2();
            if (menu_ct2) {
                QString category2 = menu_ct2;
                it = _menu_ct2.find(category2);
                if (it == _menu_ct2.end())
                    it = _menu_ct2.insert(category2, menu->addMenu(category2));
                menu = it.value();

            }
        }

        if (menu)
            menu->addAction(action);
        if (op->AddToToolbar())
            _toolbar->addAction(action);
    }

    menuBar()->addMenu(view_menu);
    menuBar()->addMenu(opt_menu);
    menuBar()->addMenu(help_menu);
}

void MainWindow::DefaultShows() {

    size_t count = PluginOperation::GetOpCount();
    for (size_t i = 0; i < count; ++i) {
        PluginOperation *op = PluginOperation::GetOperation(i);
        if (op->DefaultShow()) op->Show();
    }
}

void MainWindow::Mannual() {
}

void MainWindow::About() {
    qDebug() << "Hello World!";
}

void MainWindow::OperationTriggered(int index) {
    PluginOperation *op = PluginOperation::GetOperation(index);
    if (!op->IsShown()) op->Show();
    else op->Hide();
}
