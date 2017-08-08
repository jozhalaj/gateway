#ifndef BEEEON_BLUETOOTH_DEVICE_H
#define BEEEON_BLUETOOTH_DEVICE_H

#include <list>
#include <string>

#include "model/DeviceID.h"
#include "model/ModuleType.h"
#include "net/MACAddress.h"

namespace BeeeOn {

/**
 * This class is used to monitor the presence of Bluetooth devices.
 * Contents identification of the device and status about reachability.
 */
class BluetoothDevice {
public:
	enum Status {
		AVAILABLE,
		UNAVAILABLE,
		UNKNOWN
	};

	BluetoothDevice(const DeviceID &id);

	MACAddress mac() const;

	DeviceID deviceID() const;

	Status status() const;

	void updateStatus(const Status &status);

private:
	const DeviceID m_deviceID;
	Status m_status;
};

}

#endif //BEEEON_BLUETOOTH_DEVICE_H
