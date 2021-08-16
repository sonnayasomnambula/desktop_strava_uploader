#ifndef GPX_LOADER_H
#define GPX_LOADER_H

#include <QCoreApplication>

#include "track.h"

class QGeoPath;

namespace GPX
{

QGeoCoordinate interpolated(const QGeoPositionInfo& before, const QGeoPositionInfo& after, const QDateTime time);

class Loader
{
    Q_DECLARE_TR_FUNCTIONS(Loader)

public:
    bool load(const QString& url);
    QString lastError() const { return mLastError; }

    Track track() const { return mTrack; }
    QString name() const { return mName; }
    QGeoCoordinate center() const { return mCenter; }

    static QGeoCoordinate fromExifInfernalFormat(const QVector<QPair<quint32, quint32>>& lat,
                                         const QString& latRef,
                                         const QVector<QPair<quint32, quint32>>& lon,
                                         const QString& lonRef);
private:
    bool warn(const QString& text);

    static QDateTime stringToDateTime(const QString& s);

    Track mTrack;
    QString mName;
    QGeoCoordinate mCenter;
    QString mLastError;
};

} // namespace GPX

#endif // GPX_LOADER_H
