#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../include/ofpwrp.h"

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
	void on_createWrp_clicked();
	void on_importXyz_clicked();
	void on_saveXyz_clicked();
	void on_saveWrp_clicked();
	void on_gridSize_currentIndexChanged(int index);
	void on_cellSize_valueChanged(double arg1);
	void on_satelliteResolution_valueChanged(double arg1);

private:
	Ui::Widget *ui;

	double gridsize, cellsize, satelliteresolution, metersperpixel;
	void updateTerrainSize();

    // show our OFPWRP class to the widget umm, class ;)
	OFPWRP *wrp;
};

#endif // WIDGET_H
