#ifndef LIBRARYDIALOG_H
#define LIBRARYDIALOG_H

#include <QDialog>

namespace Ui {
    class LibraryDialog;
}

class iLibrary;
class iLibraryContainer;
class QStandardItemModel;

class LibraryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LibraryDialog(QWidget *parent = 0);
    ~LibraryDialog();
    void setFileName(QString filename);
    QString getFileName();
    void setLibraryContainer(iLibraryContainer* LibContainer);
    iLibraryContainer* getLibraryContainer();
public slots:
    void refreshUi();
    void reload();
private slots:
    void on_btnRemove_clicked();
    void on_btnApply_clicked();
    void on_btnSaveAsLibrary_clicked();
private:
    bool fillLibrary(iLibrary* lib);
    bool applyLibrary(iLibrary* lib);
    bool addLibrary(iLibrary* lib);
    bool removeLibrary(QString name);
    iLibrary* createLibrary();
    iLibrary* getLibrary(QString name);
    QString selectedLibrary();
    bool save();
    bool load();

    Ui::LibraryDialog *ui;
    iLibraryContainer* mLibContainer;
    QString mFileName;
    QStandardItemModel* mLibModel;
};

#endif // LIBRARYDIALOG_H
