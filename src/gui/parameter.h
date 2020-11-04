#ifndef PARAMETER_H
#define PARAMETER_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QString>

/**
 * @brief Manages a parameter in the gui
 */
class Parameter : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Class constuctor. Initializes members and widgets
     * @param[in] name Name of the parameter
     * @param[in] value Value of the parameter
     * @param[in] min Min value of the parameter
     * @param[in] max Max value of the parameter
     * @param[in] parent Parent object
     */
    explicit Parameter(const QString &name, int value, int min, int max, QWidget *parent = nullptr);

    /**
     * @brief Default destructor
     */
    virtual ~Parameter();

    /**
     * @brief Provides layout for the parameter widgets
     * @return Layout for the parameter widgets
     */
    QHBoxLayout* parameterLayout();

    /**
     * @brief Getter of parameter value
     * @return Parameter value
     */
    int value();

public slots:
    /**
     * @brief Setter of parameter value, also updates widgets
     * @param[in] value New value
     */
    void setValue(int value);

private:
    int m_value; //!< Value of the parameter
    QLabel* m_name; //!< Display of the name of the parameter
    QSlider* m_slider; //!< Slider of the parameter
    QLCDNumber* m_LCDNumber; //!< Digital display of the parammeter value
};

#endif // PARAMETER_H
