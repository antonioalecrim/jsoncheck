#ifndef CHECKER_H
#define CHECKER_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

class Checker: public QObject
{
    Q_OBJECT

public:
    Checker();
    ~Checker();

    Q_INVOKABLE QString checkJsonFile(QUrl fileurl);
};

#endif // CHECKER_H
