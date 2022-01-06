#include "tmpjpegfile.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>

QString TmpJpegFile::mLastError;

QString TmpJpegFile::emptyFile(const QString &message, const QString &fileName)
{
    mLastError = message + "'" + fileName + "'";
    qWarning() << qPrintable(mLastError);
    return "";
}

QString TmpJpegFile::instance(const QString& name)
{
    QFileInfo originalFile(name);
    QDir temp(QStandardPaths::writableLocation(QStandardPaths::TempLocation));
    QString path = temp.absoluteFilePath(originalFile.fileName());

    QFile copy(path);
    if (copy.exists() && !copy.remove())
        return emptyFile("Unable to remove", path);

    QFile original(originalFile.absoluteFilePath());
    if (!original.copy(path))
        return emptyFile("Unable to copy", path);

#ifdef Q_OS_LINUX
    if (!copy.setPermissions(QFile::ReadUser | QFile::WriteUser))
        return emptyFile("Unable to set permissions", path);
#endif
    return path;
}

QString TmpJpegFile::withGps()
{
    return instance(":/img/with_gps.jpg");
}

QString TmpJpegFile::withoutGps()
{
    return instance(":/img/without_gps.jpg");
}

QString TmpJpegFile::withoutExif()
{
    return instance(":/img/without_exif.jpg");
}
