#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
	void on_gridSize_currentIndexChanged(int index);
	void on_cellSize_valueChanged(double arg1);
	void on_satelliteResolution_valueChanged(double arg1);

private:
	Ui::Widget *ui;

	double gridsize, cellsize, satelliteresolution, metersperpixel;
	void updateTerrainSize();
};

#endif // WIDGET_H
