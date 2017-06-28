#ifndef SADATAPROCCLIENT_H
#define SADATAPROCCLIENT_H
#include <QObject>
#include <QLocalSocket>
#include "SALocalServeReader.h"
#include "SALocalServeWriter.h"
#include "SALocalServeFigureItemProcessHeader.h"
class SADataProcClient : public QObject
{
    Q_OBJECT
public:
    SADataProcClient(QObject *parent = nullptr);
    void shakeHand();
    uint getPid() const;
    void setPid(const uint &pid);

private:
    Q_SLOT void errorOccurred(QLocalSocket::LocalSocketError err);

private slots:

    Q_SLOT void onReceivedVectorPointFData(const SALocalServeFigureItemProcessHeader& header,QVector<QPointF>& datas);

    Q_SLOT void onReceivedString(const QString& str);
private:
    QLocalSocket m_socket;
    uint m_pid;
    SALocalServeWriter* m_writer;
    SALocalServeReader* m_reader;
};

#endif // SADATAPROCCLIENT_H