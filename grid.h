#ifndef GRID_H
#define GRID_H


class Grid
{
public:
    Grid();

    int width() const;

    int height() const;

private:
    int m_width;
    int m_height;
};

#endif // GRID_H
