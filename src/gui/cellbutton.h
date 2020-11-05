#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

/*!
 * @brief Button that displays the state of a cell button
 */
class CellButton : public QPushButton
{
    Q_OBJECT
public:

    /*!
     * @brief Class constructor
     */
    explicit CellButton();

    /*!
     * @brief Refreshes cell display
     * @param[in] text Text to display in the cell
     * @param[in] styleSheet Style of the cell to apply
     * @param[in] disable Indicates if the cell must be disabled
     */
    void repaintButton(const QString& text, const QString& styleSheet, bool disable);

private slots:

    /*!
     * @brief mousePressEvent Override to take into accout right clicks
     * @param[in] event Mouse event
     */
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

signals:
    /*!
     * @brief rightClicked Indicates that the cell was right clicked
     */
    void rightClicked();

private:
    /*!
     * @brief drawFlag Draw a flag on the cell
     */
    void drawFlag();

    int BUTTON_SIZE = 30; //!< Cell size in number of pixels
};

#endif // CELLBUTTON_H
