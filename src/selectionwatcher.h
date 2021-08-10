#ifndef SELECTIONWATCHER_H
#define SELECTIONWATCHER_H

#include <QObject>
#include <QQmlEngine>

QT_BEGIN_NAMESPACE
class QAbstractItemView;
QT_END_NAMESPACE

/* The class to pass current selection between C++ and QML */

class SelectionWatcher : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString current MEMBER mCurrent WRITE setCurrent NOTIFY currentChanged)

signals:
    void currentChanged(const QString& current);

public:
    using QObject::QObject;
    void setCurrent(const QString& current);

private:
    QString mCurrent; // full path to the picture
};

#endif // SELECTIONWATCHER_H
