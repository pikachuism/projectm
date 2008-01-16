#include "QPulseAudioDeviceChooser.hpp"
#include <QSettings>

void QPulseAudioDeviceChooser::writeSettings() {
	
	QSettings settings ( "projectM", "qprojectM-pulseaudio");
	settings.setValue ( "tryFirstAvailablePlaybackMonitor", 
		this->tryFirstPlayBackMonitorCheckBox->checkState() == Qt::Checked);	
	
}


void QPulseAudioDeviceChooser::readSettings() {
	
QSettings settings ( "projectM", "qprojectM-pulseaudio");

this->tryFirstPlayBackMonitorCheckBox->setCheckState
	(settings.value("tryFirstAvailablePlaybackMonitor", true).toBool() ? Qt::Checked : Qt::Unchecked);
}

QPulseAudioDeviceChooser::QPulseAudioDeviceChooser(const QHash<int, QString> & devices, QWidget * parent = 0, Qt::WindowFlags f) : QDialog(parent, f), m_qpulseAudioDeviceModel(devices, this) {

	setupUi(this);
	readSettings();
	this->devicesListView->setModel(&m_qpulseAudioDeviceModel);
}

void QPulseAudioDeviceChooser::open() {
	this->show();
	
}
