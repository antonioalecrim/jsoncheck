#include "checker.h"

Checker::Checker()
{

}

Checker::~Checker()
{

}

QString Checker::checkJsonFile(QUrl fileurl)
{
    QFile file;
    QString fileContents;
    QString filepath = fileurl.toLocalFile();

    file.setFileName(filepath);

    if (!file.exists()) {

        return filepath+": file not found!";
    }

    if (!file.open(QIODevice::ReadOnly)) {

        return filepath+": unable to open the file";
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    fileContents = in.readAll();
    QJsonParseError err;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileContents.toUtf8(), &err);
    Q_UNUSED(jsonDoc);
    file.close();

    if (err.error) {

        return filepath+": "+err.errorString()+" | offset: "+QString::number(err.offset)
                + "\n" + fileContents.section("", err.offset-100, err.offset+10);
    }



    return filepath+": OK";
}
