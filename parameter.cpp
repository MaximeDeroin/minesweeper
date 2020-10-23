#include "parameter.h"

Parameter::Parameter(QWidget *parent) : QWidget(parent)
{

}

Parameter::~Parameter()
{

}

Parameter::Parameter(const QString name, int number, int min, int max)
{

    m_value = number;
    m_name = new QLabel(name);

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(min,max);
    m_slider->setValue(number);

    m_LCDNumber = new QLCDNumber();
    m_LCDNumber->setSegmentStyle(QLCDNumber::Flat);
    m_LCDNumber->display(number);

    connect(m_slider, SIGNAL(valueChanged(int)), m_LCDNumber, SLOT(display(int)));
    connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
}

int Parameter::getValue()
{
    return m_value;
}

void Parameter::setValue(int value)
{
    m_value = value;
}

QHBoxLayout* Parameter::getParameterLayout()
{
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(m_name);
    layout->addWidget(m_slider);
    layout->addWidget(m_LCDNumber);
    return layout;
}
