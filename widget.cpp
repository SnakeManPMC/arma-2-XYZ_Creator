#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_gridSize_currentIndexChanged(int index)
{
	updateTerrainSize();
}


void Widget::on_cellSize_valueChanged(double arg1)
{
	updateTerrainSize();
}


void Widget::on_satelliteResolution_valueChanged(double arg1)
{
	updateTerrainSize();
}


// updates line edit text for terrain size in meters
void Widget::updateTerrainSize()
{
	/*
	correct calculation is:
	grid size x cell size == meters

	terrainSize = QLineEdit
	gridSize = QComboBox
	cellSize = QDoubleSpinBox
	*/
	cellsize = ui->cellSize->value();
	satelliteresolution = ui->satelliteResolution->value();
	double meters;
	double km2;
	double pixelfinal;

	// calculate terrain size
	if (ui->gridSize->currentIndex() == 0)
		gridsize = 16;

	if (ui->gridSize->currentIndex() == 1)
		gridsize = 32;

	if (ui->gridSize->currentIndex() == 2)
		gridsize = 64;

	if (ui->gridSize->currentIndex() == 3)
		gridsize = 128;

	if (ui->gridSize->currentIndex() == 4)
		gridsize = 256;

	if (ui->gridSize->currentIndex() == 5)
		gridsize = 512;

	if (ui->gridSize->currentIndex() == 6)
		gridsize = 1024;

	if (ui->gridSize->currentIndex() == 7)
		gridsize = 2048;

	if (ui->gridSize->currentIndex() == 8)
		gridsize = 4096;

	// new for arma3 terrain builder
	if (ui->gridSize->currentIndex() == 9)
		gridsize = 8192;

	// terrain size in meters
	meters = (gridsize * cellsize);

	// terrain size in square kilometers
	km2 = ( (meters/1000) * (meters/1000));

	// satellite map details - meters per pixel
	pixelfinal = (meters / satelliteresolution);

	// display them in text edits
	// first the size of the terrain
	ui->terrainSize->setText( QString::number( (meters) ) + " x " + QString::number( (meters) ) + " meters (" + QString::number( (meters/1000) ) + " km), " + QString::number(km2) + " square km" );
	// then pixels per meter and also blue edge
	ui->metersPerPixel->setText( QString::number( (pixelfinal) ) + ", blue edge: " + QString::number( (satelliteresolution / gridsize) ) );
}
