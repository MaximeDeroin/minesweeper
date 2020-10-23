#ifndef PARAMETER_H
#define PARAMETER_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QLCDNumber>
#include <QHBoxLayout>

#include <QString>

class Parameter : public QWidget
{
    Q_OBJECT
public:
    Parameter(QWidget *parent);
    Parameter(QString name, int number, int min, int max);
    virtual ~Parameter();

    QHBoxLayout* getParameterLayout();

    int getValue();

public slots:
    void setValue(int value);
private:
    int m_value;
    QLabel* m_name;
    QSlider* m_slider;
    QLCDNumber* m_LCDNumber;
};

#endif // PARAMETER_H
